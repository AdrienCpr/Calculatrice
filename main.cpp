#include <iostream>
using namespace std;

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Multiplication.h"
#include "Variable.h"
#include "Expression.h"

int main()
{
    // Expression : ((x + 3) * y) - 5
    Variable x("x");
    Constante c3(3.0f), c5(5.0f);
    Variable y("y");

    Addition add(&x, &c3);        // x + 3
    Multiplication mul(&add, &y); // (x + 3) * y
    Soustraction expr(&mul, &c5); // ((x + 3) * y) - 5

    // valeurs des variables
    Variable::setValeur("x", 2.0f);
    Variable::setValeur("y", 5.0f);

    cout << "Classique : ";
    expr.afficher_classique(cout);
    cout << '\n';

    cout << "NPI : ";
    expr.afficher_npi(cout);
    cout << '\n';

    cout << "Valeur : " << expr.calculer() << '\n';

    // Sauvegarde
    sauvegarder_npi(expr, "expr.txt");

    // Rechargement
    Expression *expr2 = charger_npi_fichier("expr.txt");
    cout << "\nRechargee, NPI : ";
    expr2->afficher_npi(cout);
    cout << '\n';
    cout << "Rechargee, valeur : " << expr2->calculer() << '\n';

    delete expr2; // (un jour on fera une vraie destruction récursive)

    return 0;
}
