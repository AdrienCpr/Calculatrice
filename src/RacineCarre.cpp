
// RacineCarree.cpp
#include "RacineCarre.h"
#include <cmath>
#include <limits>

RacineCarree::RacineCarree(Expression* op) : OperateurUnaire(op) {}
RacineCarree::~RacineCarree() {}

void RacineCarree::afficher_classique(ostream &os) {
    os << "sqrt(";
    GetOperande()->afficher_classique(os);
    os << ")";
}

void RacineCarree::afficher_npi(ostream &os) {
    GetOperande()->afficher_npi(os);
    os << " sqrt";
}

float RacineCarree::calculer() {
    float x = GetOperande()->calculer();
    if (x < 0.0f) return std::numeric_limits<float>::quiet_NaN();
    return std::sqrt(x);
}
