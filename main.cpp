#include <iostream>
using namespace std;

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Multiplication.h"
#include "Expression.h"

int main() {
    // ((20 + 30) * 2) - 5
    Constante c1(20.0f), c2(30.0f), c3(2.0f), c4(5.0f);
    Addition add(&c1, &c2);
    Multiplication mul(&add, &c3);
    Soustraction expr(&mul, &c4);

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

    return 0;
}
