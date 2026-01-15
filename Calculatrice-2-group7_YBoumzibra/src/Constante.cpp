#include "Constante.h"

Constante::Constante(float valeur)
{
    m_valeur = valeur;
}

Constante::~Constante()
{
    //dtor
}



void Constante::afficher_classique(std::ostream &os) const {
    os << m_valeur;
}

void Constante::afficher_npi(std::ostream &os) const {
    os << m_valeur;
}

float Constante::calculer() const {
    return m_valeur;
}
