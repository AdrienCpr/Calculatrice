#include <iostream>
#include <fstream>
#include <stack>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Multiplication.h"

void sauvegarder_npi(Expression &expr, const std::string &nomFichier)
{
    std::ofstream fichier(nomFichier.c_str());
    if (!fichier)
        throw std::runtime_error("Impossible d'ouvrir le fichier en écriture");


    expr.afficher_npi(fichier);
    fichier << '\n';
}

Expression* charger_npi(std::istream &is)
{
    std::stack<Expression*> pile;
    std::string token;

    auto appliquerOperateur = [&pile](char op) {
        if (pile.size() < 2)
            throw std::runtime_error("Expression NPI invalide (pas assez d'opérandes)");

        Expression *droit  = pile.top(); pile.pop();
        Expression *gauche = pile.top(); pile.pop();

        Expression *node = nullptr;
        switch (op) {
            case '+': node = new Addition(gauche, droit); break;
            case '-': node = new Soustraction(gauche, droit); break;
            case '*': node = new Multiplication(gauche, droit); break;
            case '/': node = new Division(gauche, droit); break;
            default:
                throw std::runtime_error("Operateur inconnu");
        }

        pile.push(node);
    };

    while (is >> token) {

        if (token.size() == 1 &&
            (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {

            appliquerOperateur(token[0]);
        }
        else {

            std::stringstream ss(token);
            float valeur;
            ss >> valeur;
            if (!ss)
                throw std::runtime_error("Nombre invalide dans la NPI : " + token);

            pile.push(new Constante(valeur));
        }
    }

    if (pile.size() != 1)
        throw std::runtime_error("Expression NPI invalide (pile finale != 1)");

    return pile.top();
}

Expression* charger_npi_fichier(const std::string &nomFichier)
{
    std::ifstream fichier(nomFichier.c_str());
    if (!fichier)
        throw std::runtime_error("Impossible d'ouvrir le fichier en lecture");

    return charger_npi(fichier);
}


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


    sauvegarder_npi(expr, "expression.txt");


    Expression *expr_chargee = charger_npi_fichier("expression.txt");

    cout << "\nAprès chargement depuis le fichier :\n";

    cout << "Classique: ";
    expr_chargee->afficher_classique(cout);
    cout << '\n';

    cout << "NPI: ";
    expr_chargee->afficher_npi(cout);
    cout << '\n';

    cout << "Valeur: " << expr_chargee->calculer() << '\n';



    return 0;
}
