#include "Variable.h"

Variable::Variable(const std::string& nom, float valeur)
    : m_nom(nom), m_valeur(valeur)
{
}

Variable::~Variable()
{
}

void Variable::afficher_classique(ostream &os)
{
    os << m_nom;
}

void Variable::afficher_npi(ostream &os)
{
    os << m_nom << " ";
}

float Variable::calculer()
{
    return m_valeur;
}
