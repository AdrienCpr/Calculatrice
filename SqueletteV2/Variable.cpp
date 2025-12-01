#include "Variable.h"
#include <stdexcept>

std::map<std::string,float> Variable::s_table;

Variable::Variable(const std::string &nom)
    : m_nom(nom)
{
}

Variable::~Variable()
{
}

void Variable::afficher_classique(std::ostream &os)
{
    os << m_nom;
}

void Variable::afficher_npi(std::ostream &os)
{
    os << m_nom;
}

float Variable::calculer()
{
    auto it = s_table.find(m_nom);
    if (it == s_table.end())
        throw std::runtime_error("Valeur de variable inconnue : " + m_nom);
    return it->second;
}

void Variable::setValeur(const std::string &nom, float valeur)
{
    s_table[nom] = valeur;
}

bool Variable::getValeur(const std::string &nom, float &valeur)
{
    auto it = s_table.find(nom);
    if (it == s_table.end())
        return false;
    valeur = it->second;
    return true;
}

