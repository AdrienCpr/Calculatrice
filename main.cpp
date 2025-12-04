#include <iostream>
using namespace std;

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Multiplication.h"
#include "Expression.h"
#include "ExpressionManager.h"
#include "tests_runner.h"


int main(void) {

    run_all_tests();

    Constante c1(20.0);

    c1.afficher_classique();
    cout << endl;

    Constante c2(30.0);
    Addition add1(&c1, &c2);

    cout << "Classique: ";
    expr.afficher_classique(cout);
    cout << '\n';

    cout << "NPI: ";
    expr.afficher_npi(cout);
    cout << '\n';

    cout << "Valeur: " << expr.calculer() << '\n';

    // Sauvegarde
    sauvegarder_npi(expr, "expression.txt");

    // Rechargement
    Expression *expr_chargee = charger_npi_fichier("expression.txt");

    cout << "\nAprès chargement depuis le fichier :\n";

    cout << "Classique: ";
    expr_chargee->afficher_classique(cout);
    cout << '\n';

    cout << "NPI: ";
    expr_chargee->afficher_npi(cout);
    cout << '\n';

    cout << "Valeur: " << expr_chargee->calculer() << '\n';

    // (pour l’instant on ne détruit pas récursivement tout l’arbre)
    delete expr_chargee;

    ExpressionManager::Instance().setExpression(&d1);

    cout << "--- Expression via Singleton ---" << endl;

    Expression* e = ExpressionManager::Instance().getExpression();

    e->afficher_classique(cout);
    cout << endl;
    e->afficher_npi(cout);
    cout << endl;

    return 0;
}
