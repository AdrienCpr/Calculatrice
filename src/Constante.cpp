#include "Constante.h"

Constante::Constante(float valeur)
{
    m_valeur = valeur;
}

Constante::~Constante()
{
    // dtor
}

void Constante::afficher_classique(ostream &os) {
    os << m_valeur;
}

void Constante::afficher_npi(ostream &os) {
    // En NPI, une constante s affiche comme en classique
    os << m_valeur;
}

float Constante::calculer() {
    // Le resultat d une constante est sa valeur
    return m_valeur;
}
