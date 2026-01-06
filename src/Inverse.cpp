#include "Inverse.h"
#include <limits>

Inverse::Inverse(Expression* op) : OperateurUnaire(op) {}
Inverse::~Inverse() {}

void Inverse::afficher_classique(ostream &os) {
    os << "inv(";
    GetOperande()->afficher_classique(os);
    os << ")";
}

void Inverse::afficher_npi(ostream &os) {
    GetOperande()->afficher_npi(os);
    os << " inv";
}

float Inverse::calculer() {
    float x = GetOperande()->calculer();
    if (x == 0.0f) return std::numeric_limits<float>::quiet_NaN();
    return 1.0f / x;
}
