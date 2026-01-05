#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <istream>
#include <iostream>
using namespace std;

class Expression
{
    public:
        Expression();
        virtual ~Expression();

        virtual void afficher_classique(ostream &os = cout) = 0;
        virtual void afficher_npi(ostream &os = cout) = 0;
        virtual float calculer() = 0;

    protected:

    private:
};

class TableDesSymboles;


void sauvegarder_npi(Expression &expr, const std::string &nomFichier);


Expression* charger_npi(std::istream &is, TableDesSymboles &tds);


Expression* charger_npi_fichier(const std::string &nomFichier, TableDesSymboles &tds);


#endif // EXPRESSION_H
