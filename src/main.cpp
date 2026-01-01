#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>


#include <iostream>

using namespace std;

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Multiplication.h"

// V1 + V2
#include "Variable.h"
#include "TableDesSymboles.h"



int main(int argc, char *argv[])
{

    setbuf(stdout, NULL);
    qDebug() << "snafu";

    Constante c1(20.0);

    c1.afficher_classique();
    cout << endl;

    Constante c2(30.0);
    Addition add1(&c1, &c2);

    add1.afficher_classique(cout);
    cout << endl;

    add1.afficher_npi(cout);
    cout << endl;

    Constante c3(34.0);
    Multiplication m1(&c3, &add1);

    m1.afficher_classique(cout);
    cout << endl;

    m1.afficher_npi(cout);
    cout << endl;

    Constante c4(50.0);
    Constante c5(10.0);
    Soustraction s1(&c4, &c5);

    s1.afficher_classique(cout);
    cout << endl;

    s1.afficher_npi(cout);
    cout << endl;

    Division d1(&m1, &c5);

    d1.afficher_classique(cout);
    cout << endl;

    d1.afficher_npi(cout);
    cout << endl;

    // ==========================================================
    //              V1 : TESTS VARIABLES (sans table)
    // ==========================================================
    cout << "\n=== V1 : Tests Variables (sans table) ===\n";

    Variable x("x");
    x.Setvaleur(3.0f);

    Addition v1_expr1(&x, &c5);      // (x + 10)
    cout << "V1 Expr1 classique : ";
    v1_expr1.afficher_classique(cout);
    cout << "\nV1 Expr1 NPI       : ";
    v1_expr1.afficher_npi(cout);
    cout << "\nV1 Expr1 calculee  : " << v1_expr1.calculer() << "\n";

    Addition v1_add2(&c1, &x);       // (20 + x)
    Multiplication v1_expr2(&c3, &v1_add2); // 34 * (20 + x)

    cout << "\nV1 Expr2 classique : ";
    v1_expr2.afficher_classique(cout);
    cout << "\nV1 Expr2 NPI       : ";
    v1_expr2.afficher_npi(cout);
    cout << "\nV1 Expr2 calculee  : " << v1_expr2.calculer() << "\n";

    x.Setvaleur(10.0f);
    cout << "\nV1 Apres x = 10 :\n";
    cout << "V1 Expr1 calculee  : " << v1_expr1.calculer() << "\n";
    cout << "V1 Expr2 calculee  : " << v1_expr2.calculer() << "\n";

    // ==========================================================
    //                 V2 : TESTS VARIABLES + TDS
    // ==========================================================
    cout << "\n=== V2 : Tests Variables + TableDesSymboles ===\n";

    TableDesSymboles tds;

    Variable* x1 = tds.getOuCreer("x");
    Variable* x2 = tds.getOuCreer("x");

    cout << "Adresse x1 = " << x1 << "\n";
    cout << "Adresse x2 = " << x2 << "\n";

    tds.affecter("x", 3.0f);

    Addition v2_expr1(&c1, x1);   // (20 + x)
    cout << "V2 Expr1 classique : ";
    v2_expr1.afficher_classique(cout);
    cout << "\nV2 Expr1 NPI       : ";
    v2_expr1.afficher_npi(cout);
    cout << "\nV2 Expr1 calculee  : " << v2_expr1.calculer() << "\n";

    tds.affecter("x", 10.0f);
    cout << "V2 Apres x = 10, Expr1 calculee : " << v2_expr1.calculer() << "\n";

    Addition v2_exprAdd(x1, &c2);               // (x + 30)
    Multiplication v2_expr2(&c3, &v2_exprAdd);  // 34 * (x + 30)

    cout << "\nV2 Expr2 classique : ";
    v2_expr2.afficher_classique(cout);
    cout << "\nV2 Expr2 NPI       : ";
    v2_expr2.afficher_npi(cout);
    cout << "\nV2 Expr2 calculee  : " << v2_expr2.calculer() << "\n";

    cout << "\n--- Contenu TableDesSymboles ---\n";
    tds.afficher(cout);

    cout.flush();

    // Partie graphique
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

