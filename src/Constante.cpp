#include "Constante.h"

Constante::Constante(float valeur)
{
    m_valeur = valeur;
}

Constante::~Constante()
{
    //dtor
}



void Constante::afficher_classique(ostream &os) {
    os << m_valeur;
}

void Constante::afficher_npi(ostream &os) {
        // à compléter
}

float Constante::calculer() {
        // à compléter
}
