#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <stdexcept>
#include <string>

class Expression;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Exception de parsing UI
    class ParseError : public std::runtime_error {
    public:
        explicit ParseError(const std::string& msg) : std::runtime_error(msg) {}
    };

private:
    Ui::MainWindow *ui;

    // helpers internes
    void appendText(const QString& s);
    void refreshDisplay();

    // parse infix -> arbre Expression*
    Expression* buildExpressionFromInfix(const std::string& infix, double xValue);

private slots:
    // boutons principaux
    void on_btnEval_clicked();
    void on_btnSave_clicked();
    void on_btnLoad_clicked();
    void on_btnClear_clicked();
    void on_btnDel_clicked();

    // digits & opérateurs
    void on_btn0_clicked();
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
    void on_btn5_clicked();
    void on_btn6_clicked();
    void on_btn7_clicked();
    void on_btn8_clicked();
    void on_btn9_clicked();

    void on_btnDot_clicked();
    void on_btnSpace_clicked();

    void on_btnPlus_clicked();
    void on_btnMinus_clicked();
    void on_btnMul_clicked();
    void on_btnDiv_clicked();
    void on_btnPow_clicked();

    void on_btnLPar_clicked();
    void on_btnRPar_clicked();
    void on_btnX_clicked();

    // fonctions unaires
    void on_btnSqrt_clicked();
    void on_btnLn_clicked();
    void on_btnAbs_clicked();
    void on_btnInv_clicked();
    void on_btnSq_clicked();
    void on_btnNeg_clicked();

    // Menus
    void on_actionSauvegarder_triggered();
    void on_actionCharger_triggered();

    void on_actionSaisieExpression_triggered();
    void on_actionAffichage_notation_classique_triggered();
    void on_actionAffichage_notation_P_I_triggered();
    void on_actionAffichage_valeur_triggered();
    void on_actionAffichage_graphique_2D_triggered();
    void on_actionAffichage_graphique_3D_triggered();

    void on_actionSimplification_triggered();

};

#endif // MAINWINDOW_H
