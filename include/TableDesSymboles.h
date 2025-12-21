#ifndef TABLEDESSYMBOLES_H
#define TABLEDESSYMBOLES_H

#include <map>
#include <string>
#include <iostream>

#include "Variable.h"

class TableDesSymboles
{
public:
    TableDesSymboles();
    virtual ~TableDesSymboles();

    // Retourne la Variable existante si déjà créée, sinon la crée.
    Variable* getOuCreer(const std::string& nom);

    // Recherche sans créer : retourne nullptr si absent.
    Variable* rechercher(const std::string& nom) const;

    bool contient(const std::string& nom) const;

    // Affecte une valeur (crée la variable si besoin)
    void affecter(const std::string& nom, float valeur);

    // Récupère la valeur (crée la variable si besoin, valeur par défaut = 0)
    float valeur(const std::string& nom);

    // Debug
    void afficher(std::ostream& os = std::cout) const;

    // Libère tout
    void vider();

private:
    std::map<std::string, Variable*> m_table;
};

#endif // TABLEDESSYMBOLES_H
