#include "Expression.h"

#include <fstream>
#include <stack>
#include <sstream>
#include <stdexcept>

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Multiplication.h"

using namespace std;

Expression::Expression() {}
Expression::~Expression() {}

void sauvegarder_npi(Expression &expr, const std::string &nomFichier)
{
    ofstream fichier(nomFichier.c_str());
    if (!fichier)
        throw runtime_error("Impossible d'ouvrir le fichier en écriture");

    expr.afficher_npi(fichier);
    fichier << '\n';
}

Expression* charger_npi(std::istream &is)
{
    stack<Expression*> pile;
    string token;

    auto appliquerOperateur = [&pile](char op) {
        if (pile.size() < 2)
            throw runtime_error("Expression NPI invalide (pas assez d'opérandes)");

        Expression *droit  = pile.top(); pile.pop();
        Expression *gauche = pile.top(); pile.pop();

        Expression *node = nullptr;
        switch (op) {
        case '+': node = new Addition(gauche, droit); break;
        case '-': node = new Soustraction(gauche, droit); break;
        case '*': node = new Multiplication(gauche, droit); break;
        case '/': node = new Division(gauche, droit); break;
        default:
            throw runtime_error("Operateur inconnu");
        }
        pile.push(node);
    };

    while (is >> token)
    {
        if (token.size() == 1 &&
            (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
        {
            appliquerOperateur(token[0]);
        }
        else
        {
            stringstream ss(token);
            float valeur;
            ss >> valeur;
            if (!ss)
                throw runtime_error("Nombre invalide dans la NPI : " + token);

            pile.push(new Constante(valeur));
        }
    }

    if (pile.size() != 1)
        throw runtime_error("Expression NPI invalide (pile finale != 1)");

    return pile.top();
}

Expression* charger_npi_fichier(const std::string &nomFichier)
{
    ifstream fichier(nomFichier.c_str());
    if (!fichier)
        throw runtime_error("Impossible d'ouvrir le fichier en lecture");

    return charger_npi(fichier);
}
