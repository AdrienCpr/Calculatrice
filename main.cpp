#include <iostream>
#include <stack>
#include <string>

using namespace std;

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Multiplication.h"
#include "Expression.h"

// Fonction utilitaire : construit une Expression* a partir d une saisie NPI
Expression* lire_expression_npi() {
    stack<Expression*> pile;
    string token;

    cout << "=== Calculatrice NPI (notation polonaise inversee) ===" << endl;
    cout << "Entrez votre expression, un element a la fois," << endl;
    cout << "puis 'p' pour terminer et calculer." << endl;
    cout << endl;
    cout << "Exemple pour (5/2 + 4) * (-20 - 3) :" << endl;
    cout << "  5 2 / 4 + -20 -3 + * p" << endl << endl;

    while (cin >> token && token != "p") {

        // Est-ce un operateur ? (un seul caractere parmi + - * /)
        if (token.size() == 1 &&
            (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {

            if (pile.size() < 2) {
                cerr << "Erreur : pas assez d operandes sur la pile pour appliquer l operateur '"
                     << token << "'." << endl;
                return nullptr;
            }

            // On depile d abord l operande droit puis l operande gauche
            Expression* opd = pile.top(); pile.pop();
            Expression* opg = pile.top(); pile.pop();

            Expression* expr = nullptr;
            switch (token[0]) {
                case '+':
                    expr = new Addition(opg, opd);
                    break;
                case '-':
                    expr = new Soustraction(opg, opd);
                    break;
                case '*':
                    expr = new Multiplication(opg, opd);
                    break;
                case '/':
                    expr = new Division(opg, opd);
                    break;
            }

            pile.push(expr);
        }
        else {
            // Sinon, on considere que c est un nombre (entier ou flottant, eventuellement negatif)
            float valeur = stof(token);  // on suppose la syntaxe correcte
            pile.push(new Constante(valeur));
        }
    }

    if (pile.size() != 1) {
        cerr << "Erreur : expression incomplete ou mal formee (pile.size = "
             << pile.size() << ")." << endl;
        return nullptr;
    }

    return pile.top();
}

int main() {
    Expression* expr = lire_expression_npi();
    if (!expr) {
        return 1;  // erreur deja affichee
    }

    cout << endl;
    cout << "=== Resultat ===" << endl;

    cout << "Notation classique : ";
    expr->afficher_classique(cout);
    cout << endl;

    cout << "Notation polonaise inversee : ";
    expr->afficher_npi(cout);
    cout << endl;

    cout << "Valeur numerique : " << expr->calculer() << endl;

    // Si le destructeur d OperateurBinaire detruit ses operandes,
    // un seul delete ici suffit pour tout liberer
    delete expr;

    return 0;
}
