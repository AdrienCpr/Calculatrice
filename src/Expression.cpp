#include "Expression.h"

#include <fstream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <map>

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "TableDesSymboles.h"
#include "Variable.h"

using namespace std;

Expression::Expression() {}
Expression::~Expression() {}


//  Petit "registre" d'opérateurs extensible

namespace {
    using CreateurBin = Expression* (*)(Expression*, Expression*);

    map<string, CreateurBin>& registre()
    {
        static map<string, CreateurBin> r;
        return r;
    }

    // Fonctions de création
    Expression* mkAdd(Expression* g, Expression* d) { return new Addition(g,d); }
    Expression* mkSub(Expression* g, Expression* d) { return new Soustraction(g,d); }
    Expression* mkMul(Expression* g, Expression* d) { return new Multiplication(g,d); }
    Expression* mkDiv(Expression* g, Expression* d) { return new Division(g,d); }

    void init_registre()
    {
        if (!registre().empty()) return;
        registre()["+"] = &mkAdd;
        registre()["-"] = &mkSub;
        registre()["*"] = &mkMul;
        registre()["/"] = &mkDiv;
    }

    bool estNombre(const string &token, float &val)
    {
        stringstream ss(token);
        ss >> val;
        return (ss && ss.eof());
    }
}




// Sauvegarde / chargement

void sauvegarder_npi(Expression &expr, const std::string &nomFichier)
{
    ofstream fichier(nomFichier.c_str());
    if (!fichier)
        throw runtime_error("Impossible d'ouvrir le fichier en écriture");

    expr.afficher_npi(fichier);
    fichier << "\n";
}

Expression* charger_npi(std::istream &is, TableDesSymboles &tds)
{
    init_registre();

    stack<Expression*> pile;
    string token;

    while (is >> token)
    {
        float valeur = 0.0f;


        if (estNombre(token, valeur))
        {
            pile.push(new Constante(valeur));
            continue;
        }


        auto it = registre().find(token);
        if (it != registre().end())
        {
            if (pile.size() < 2)
                throw runtime_error("NPI invalide : pas assez d'opérandes pour " + token);

            Expression* d = pile.top(); pile.pop();
            Expression* g = pile.top(); pile.pop();

            pile.push(it->second(g, d));
            continue;
        }


        pile.push(tds.getOuCreer(token));
    }

    if (pile.size() != 1)
        throw runtime_error("NPI invalide : pile finale != 1");

    return pile.top();
}

Expression* charger_npi_fichier(const std::string &nomFichier, TableDesSymboles &tds)
{
    ifstream fichier(nomFichier.c_str());
    if (!fichier)
        throw runtime_error("Impossible d'ouvrir le fichier en lecture");

    return charger_npi(fichier, tds);
}
