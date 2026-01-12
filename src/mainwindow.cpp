#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

#include <sstream>
#include <stack>
#include <vector>
#include <cctype>
#include <cmath>

#include "ExpressionManager.h"
#include "Expression.h"

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "Puissance.h"

#include "Carre.h"
#include "Oppose.h"
#include "RacineCarree.h"
#include "Inverse.h"
#include "ValeurAbsolue.h"
#include "LogNeperien.h"
#include "Graph2dDialog.h"


// ------------------ helpers affichage ------------------
static std::string expr_classique(Expression* e){
    if(!e) return "Aucune expression";
    std::ostringstream oss; e->afficher_classique(oss); return oss.str();
}
static std::string expr_npi(Expression* e){
    if(!e) return "Aucune expression";
    std::ostringstream oss; e->afficher_npi(oss); return oss.str();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->leExpr->setText("inv(sqrt((20+10)^2)) * ln(abs(-5))");
    refreshDisplay();
}

MainWindow::~MainWindow(){ delete ui; }

void MainWindow::appendText(const QString& s)
{
    ui->leExpr->insert(s);
}

void MainWindow::refreshDisplay()
{
    Expression* e = ExpressionManager::Instance().getExpression();
    if(!e){
        ui->lblResult->setText("Résultat : -");
        ui->pteDetails->setPlainText("Aucune expression dans le manager.");
        return;
    }

    float v = e->calculer();
    QString res;
    if (std::isnan(v)) res = "Résultat : NaN";
    else if (std::isinf(v)) res = "Résultat : Inf";
    else res = QString("Résultat : %1").arg(v);

    ui->lblResult->setText(res);

    QString details;
    details += "Classique:\n";
    details += QString::fromStdString(expr_classique(e));
    details += "\n\nNPI:\n";
    details += QString::fromStdString(expr_npi(e));
    details += "\n\nValeur:\n";
    details += res;

    ui->pteDetails->setPlainText(details);
}

// ------------------ tokenizer + shunting-yard ------------------
struct Tok { enum Type { Num, Ident, Op, LPar, RPar, End } t; std::string s; };

static std::vector<Tok> tokenize(const std::string& in)
{
    std::vector<Tok> out;
    size_t i=0;
    while(i<in.size()){
        char c=in[i];
        if(std::isspace((unsigned char)c)){ i++; continue; }

        if(std::isdigit((unsigned char)c) || c=='.'){
            size_t j=i;
            while(j<in.size() && (std::isdigit((unsigned char)in[j]) || in[j]=='.')) j++;
            out.push_back({Tok::Num, in.substr(i, j-i)});
            i=j; continue;
        }

        if(std::isalpha((unsigned char)c)){
            size_t j=i;
            while(j<in.size() && (std::isalnum((unsigned char)in[j]) || in[j]=='_')) j++;
            out.push_back({Tok::Ident, in.substr(i, j-i)});
            i=j; continue;
        }

        if(c=='('){ out.push_back({Tok::LPar,"("}); i++; continue; }
        if(c==')'){ out.push_back({Tok::RPar,")"}); i++; continue; }

        if(std::string("+-*/^").find(c)!=std::string::npos){
            out.push_back({Tok::Op,std::string(1,c)});
            i++; continue;
        }

        throw MainWindow::ParseError(std::string("Caractère invalide: '") + c + "'");
    }
    out.push_back({Tok::End,""});
    return out;
}

static bool isFunc(const std::string& id){
    return (id=="sqrt"||id=="ln"||id=="abs"||id=="inv"||id=="sq");
}
static int prec(const std::string& op){
    if(op=="neg") return 5;
    if(op=="sqrt"||op=="ln"||op=="abs"||op=="inv"||op=="sq") return 5;
    if(op=="^") return 4;
    if(op=="*"||op=="/") return 3;
    if(op=="+"||op=="-") return 2;
    return 0;
}
static bool rightAssoc(const std::string& op){ return (op=="^" || op=="neg"); }

static std::vector<std::string> toRpn(const std::vector<Tok>& toks)
{
    std::vector<std::string> output;
    std::stack<std::string> ops;

    bool expectUnary = true;

    for(size_t i=0; toks[i].t!=Tok::End; i++){
        const Tok& tk = toks[i];

        if(tk.t==Tok::Num){
            output.push_back(tk.s);
            expectUnary = false;
        }
        else if(tk.t==Tok::Ident){
            if(isFunc(tk.s)) { ops.push(tk.s); expectUnary = true; }
            else if(tk.s=="x") { output.push_back("x"); expectUnary = false; }
            else if(tk.s=="neg") { ops.push("neg"); expectUnary = true; }
            else throw MainWindow::ParseError("Identifiant inconnu : " + tk.s + " (autorisé: x, sqrt, ln, abs, inv, sq, neg)");
        }
        else if(tk.t==Tok::Op){
            std::string op = tk.s;
            if(op=="-" && expectUnary) op = "neg";

            while(!ops.empty()){
                std::string top = ops.top();
                if(top=="(") break;

                int p1=prec(op), p2=prec(top);
                if( (rightAssoc(op) && p1<p2) || (!rightAssoc(op) && p1<=p2) ){
                    output.push_back(top);
                    ops.pop();
                } else break;
            }
            ops.push(op);
            expectUnary = true;
        }
        else if(tk.t==Tok::LPar){
            ops.push("(");
            expectUnary = true;
        }
        else if(tk.t==Tok::RPar){
            while(!ops.empty() && ops.top()!="("){
                output.push_back(ops.top());
                ops.pop();
            }
            if(ops.empty()) throw MainWindow::ParseError("Parenthèse fermante sans ouvrante");
            ops.pop();

            if(!ops.empty() && isFunc(ops.top())){ output.push_back(ops.top()); ops.pop(); }
            if(!ops.empty() && ops.top()=="neg"){ output.push_back("neg"); ops.pop(); }

            expectUnary = false;
        }
    }

    while(!ops.empty()){
        if(ops.top()=="(") throw MainWindow::ParseError("Parenthèse ouvrante non fermée");
        output.push_back(ops.top());
        ops.pop();
    }
    return output;
}

static Expression* buildFromRpn(const std::vector<std::string>& rpn, double xValue)
{
    std::stack<Expression*> st;

    auto pop1 = [&](){
        if(st.empty()) throw MainWindow::ParseError("RPN invalide (pile vide)");
        auto a=st.top(); st.pop(); return a;
    };
    auto pop2 = [&](){
        if(st.size()<2) throw MainWindow::ParseError("RPN invalide (pas assez d'opérandes)");
        auto b=st.top(); st.pop();
        auto a=st.top(); st.pop();
        return std::pair<Expression*,Expression*>{a,b};
    };

    for(const auto& tok : rpn){
        char* end=nullptr;
        double val = std::strtod(tok.c_str(), &end);
        if(end && *end=='\0' && tok!="x"){ st.push(new Constante((float)val)); continue; }
        if(tok=="x"){ st.push(new Constante((float)xValue)); continue; }

        if(tok=="sqrt"){ st.push(new RacineCarree(pop1())); continue; }
        if(tok=="ln"){   st.push(new LogNeperien(pop1())); continue; }
        if(tok=="abs"){  st.push(new ValeurAbsolue(pop1())); continue; }
        if(tok=="inv"){  st.push(new Inverse(pop1())); continue; }
        if(tok=="sq"){   st.push(new Carre(pop1())); continue; }
        if(tok=="neg"){  st.push(new Oppose(pop1())); continue; }

        if(tok=="+"){ auto [a,b]=pop2(); st.push(new Addition(a,b)); continue; }
        if(tok=="-"){ auto [a,b]=pop2(); st.push(new Soustraction(a,b)); continue; }
        if(tok=="*"){ auto [a,b]=pop2(); st.push(new Multiplication(a,b)); continue; }
        if(tok=="/"){ auto [a,b]=pop2(); st.push(new Division(a,b)); continue; }
        if(tok=="^"){ auto [a,b]=pop2(); st.push(new Puissance(a,b)); continue; }

        throw MainWindow::ParseError("Token RPN inconnu : "+tok);
    }

    if(st.size()!=1) throw MainWindow::ParseError("Expression invalide (pile finale != 1)");
    return st.top();
}

Expression* MainWindow::buildExpressionFromInfix(const std::string& infix, double xValue)
{
    auto toks = tokenize(infix);
    auto rpn  = toRpn(toks);
    return buildFromRpn(rpn, xValue);
}

// ------------------ slots ------------------
void MainWindow::on_btnEval_clicked()
{
    try {
        std::string infix = ui->leExpr->text().toStdString();
        double xVal = ui->sbX->value();

        Expression* e = buildExpressionFromInfix(infix, xVal);
        ExpressionManager::Instance().setExpression(e);
        refreshDisplay();
    } catch(const std::exception& ex){
        QMessageBox::critical(this, "Erreur", ex.what());
    }
}

void MainWindow::on_btnSave_clicked()
{
    Expression* e = ExpressionManager::Instance().getExpression();
    if(!e){ QMessageBox::warning(this,"Sauvegarde","Aucune expression."); return; }

    QString fileName = QFileDialog::getSaveFileName(this,"Sauver NPI","","*.txt");
    if(fileName.isEmpty()) return;

    try {
        sauvegarder_npi(*e, fileName.toStdString());
        QMessageBox::information(this,"Sauvegarde","OK");
    } catch(const std::exception& ex){
        QMessageBox::critical(this,"Erreur sauvegarde", ex.what());
    }
}

void MainWindow::on_btnLoad_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Charger NPI","","*.txt");
    if(fileName.isEmpty()) return;

    try {
        Expression* e = charger_npi_fichier(fileName.toStdString());
        ExpressionManager::Instance().setExpression(e);
        refreshDisplay();
        QMessageBox::information(this,"Chargement","OK");
    } catch(const std::exception& ex){
        QMessageBox::critical(this,"Erreur chargement", ex.what());
    }
}

void MainWindow::on_btnClear_clicked(){ ui->leExpr->clear(); }
void MainWindow::on_btnDel_clicked(){
    QString t=ui->leExpr->text();
    if(!t.isEmpty()) t.chop(1);
    ui->leExpr->setText(t);
}

#define APPEND_SLOT(name, txt) void MainWindow::on_##name##_clicked(){ appendText(txt); }
APPEND_SLOT(btn0,"0") APPEND_SLOT(btn1,"1") APPEND_SLOT(btn2,"2") APPEND_SLOT(btn3,"3") APPEND_SLOT(btn4,"4")
    APPEND_SLOT(btn5,"5") APPEND_SLOT(btn6,"6") APPEND_SLOT(btn7,"7") APPEND_SLOT(btn8,"8") APPEND_SLOT(btn9,"9")
    APPEND_SLOT(btnDot,".") APPEND_SLOT(btnSpace," ")
    APPEND_SLOT(btnPlus,"+") APPEND_SLOT(btnMinus,"-") APPEND_SLOT(btnMul,"*") APPEND_SLOT(btnDiv,"/")
    APPEND_SLOT(btnPow,"^") APPEND_SLOT(btnLPar,"(") APPEND_SLOT(btnRPar,")") APPEND_SLOT(btnX,"x")
#undef APPEND_SLOT

void MainWindow::on_btnSqrt_clicked(){ appendText("sqrt("); }
void MainWindow::on_btnLn_clicked(){ appendText("ln("); }
void MainWindow::on_btnAbs_clicked(){ appendText("abs("); }
void MainWindow::on_btnInv_clicked(){ appendText("inv("); }
void MainWindow::on_btnSq_clicked(){ appendText("sq("); }
void MainWindow::on_btnNeg_clicked(){ appendText("neg("); }

#include <QMessageBox>

// ============ MENUS ============

#include <QMessageBox>

// ========= MENUS DU PROF =========

void MainWindow::on_actionSauvegarder_triggered()
{
    // Reuse bouton Sauver (NPI)
    on_btnSave_clicked();
    if (ui->statusbar) ui->statusbar->showMessage("Sauvegarde NPI via menu.", 2000);
}

void MainWindow::on_actionCharger_triggered()
{
    // Reuse bouton Charger (NPI)
    on_btnLoad_clicked();
    if (ui->statusbar) ui->statusbar->showMessage("Chargement NPI via menu.", 2000);
}

void MainWindow::on_actionSaisieExpression_triggered()
{
    ui->leExpr->setFocus();
    ui->leExpr->selectAll();
    if (ui->statusbar) ui->statusbar->showMessage("Saisie : entre une expression puis '='.", 2000);
}

void MainWindow::on_actionAffichage_notation_classique_triggered()
{
    ui->pteDetails->appendPlainText("=== Notation classique (infix) ===");
    ui->pteDetails->appendPlainText(ui->leExpr->text());
}

void MainWindow::on_actionAffichage_notation_P_I_triggered()
{
    try {
        const std::string infix = ui->leExpr->text().toStdString();
        double xVal = ui->sbX->value();

        std::unique_ptr<Expression> e(buildExpressionFromInfix(infix, xVal));

        std::ostringstream oss;
        e->afficher_npi(oss);

        ui->pteDetails->appendPlainText("=== Notation P.I (NPI) ===");
        ui->pteDetails->appendPlainText(QString::fromStdString(oss.str()));
    }
    catch (const std::exception& ex) {
        ui->pteDetails->appendPlainText("ERREUR NPI : " + QString(ex.what()));
    }
}


void MainWindow::on_actionAffichage_valeur_triggered()
{
    on_btnEval_clicked();
    if (ui->statusbar) ui->statusbar->showMessage("Évaluation via menu.", 2000);
}

void MainWindow::on_actionAffichage_graphique_2D_triggered()
{
    Graph2DDialog dlg(this);
    dlg.exec();

}

void MainWindow::on_actionAffichage_graphique_3D_triggered()
{
    QMessageBox::information(this, "Graphique 3D",
                             "Non implémenté pour le moment (autorisé).\n"
                             "Les autres fonctionnalités sont actives.");
}

void MainWindow::on_actionSimplification_triggered()
{
    ui->pteDetails->appendPlainText("=== Simplification ===");
    ui->pteDetails->appendPlainText("(À brancher sur simplify() : itération 2)");
    if (ui->statusbar) ui->statusbar->showMessage("Simplification : placeholder (itération 2).", 2000);
}
