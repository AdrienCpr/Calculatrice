#include <iostream>
#include <fstream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Multiplication.h"
#include "Variable.h"

void sauvegarder_npi(Expression &expr, const std::string &nomFichier)
{
    std::ofstream fichier(nomFichier.c_str());
    if (!fichier)
        throw std::runtime_error("Impossible d'ouvrir le fichier en écriture");


    expr.afficher_npi(fichier);
    fichier << '\n';
}
bool estNombre(const std::string &token, float &valeur)
{
    std::stringstream ss(token);
    ss >> valeur;

    return (ss && ss.eof());
}


bool estOperateurBinaire(const std::string &token)
{
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return true;



    return false;
}

Expression *creerOperateurBinaire(const std::string &token,
                                  Expression *gauche,
                                  Expression *droit)
{
    if (token == "+") return new Addition(gauche, droit);
    if (token == "-") return new Soustraction(gauche, droit);
    if (token == "*") return new Multiplication(gauche, droit);
    if (token == "/") return new Division(gauche, droit);


    throw std::runtime_error("Operateur binaire non supporte : " + token);
}


Expression* charger_npi(std::istream &is)
{
    std::stack<Expression*> pile;
    std::string token;

    while (is >> token) {
        float valeur = 0.0f;

        if (estNombre(token, valeur)) {

            pile.push(new Constante(valeur));
        }
        else if (estOperateurBinaire(token)) {

            if (pile.size() < 2)
                throw std::runtime_error("Expression NPI invalide : pas assez d'operandes");

            Expression *droit  = pile.top(); pile.pop();
            Expression *gauche = pile.top(); pile.pop();

            pile.push(creerOperateurBinaire(token, gauche, droit));
        }
        else {

            pile.push(new Variable(token));
        }
    }

    if (pile.size() != 1)
        throw std::runtime_error("Expression NPI invalide : pile finale != 1");

    return pile.top();
}

Expression* charger_npi_fichier(const std::string &nomFichier)
{
    std::ifstream fichier(nomFichier.c_str());
    if (!fichier)
        throw std::runtime_error("Impossible d'ouvrir le fichier en lecture");

    return charger_npi(fichier);
}




int main()
{
    // Expression : ((x + 3) * y) - 5
    Variable x("x");
    Constante c3(3.0f), c5(5.0f);
    Variable y("y");

    Addition add(&x, &c3);
    Multiplication mul(&add, &y);
    Soustraction expr(&mul, &c5);


    Variable::setValeur("x", 2.0f);
    Variable::setValeur("y", 5.0f);

    cout << "Classique : ";
    expr.afficher_classique(cout);
    cout << '\n';

    cout << "NPI : ";
    expr.afficher_npi(cout);
    cout << '\n';

    cout << "Valeur : " << expr.calculer() << '\n';

    sauvegarder_npi(expr, "expr.txt");


    Expression *expr2 = charger_npi_fichier("expr.txt");
    cout << "\nRechargee, NPI : ";
    expr2->afficher_npi(cout);
    cout << '\n';
    cout << "Rechargee, valeur : " << expr2->calculer() << '\n';

    delete expr2;

    return 0;
}
