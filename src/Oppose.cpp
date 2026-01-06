// Oppose.cpp
#include "Oppose.h"

Oppose::Oppose(Expression* op) : OperateurUnaire(op) {}
Oppose::~Oppose() {}

void Oppose::afficher_classique(ostream &os) {
    os << "-(";
    GetOperande()->afficher_classique(os);
    os << ")";
}

void Oppose::afficher_npi(ostream &os) {
    GetOperande()->afficher_npi(os);
    os << " neg";
}

float Oppose::calculer() {
    return -GetOperande()->calculer();
}
