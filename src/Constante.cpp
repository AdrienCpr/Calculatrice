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
        cout << m_valeur;
}

void Constante::afficher_npi(ostream &os) {
        cout << m_valeur;
}

float Constante::calculer() {
        return m_valeur;
}
