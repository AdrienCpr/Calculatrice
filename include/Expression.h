#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <string>
using namespace std;

class Expression
{
    public:
        Expression();
        virtual ~Expression();

        virtual void afficher_classique(ostream &os = cout) = 0;
        virtual void afficher_npi(ostream &os = cout) = 0;
        virtual float calculer() = 0;
};

// ---------- Fonctions de sauvegarde / chargement en NPI ----------

// Sauvegarde l'expression en NPI dans un fichier texte
void sauvegarder_npi(Expression &expr, const std::string &nomFichier);

// Charge une expression en NPI depuis un flux (ifstream, stringstream, ...)
Expression* charger_npi(std::istream &is);

// Charge une expression en NPI depuis un fichier texte
Expression* charger_npi_fichier(const std::string &nomFichier);

#endif // EXPRESSION_H
