
// LogNeperien.cpp
#include "LogNeperien.h"
#include <cmath>
#include <limits>

LogNeperien::LogNeperien(Expression* op) : OperateurUnaire(op) {}
LogNeperien::~LogNeperien() {}

void LogNeperien::afficher_classique(ostream &os) {
    os << "ln(";
    GetOperande()->afficher_classique(os);
    os << ")";
}

void LogNeperien::afficher_npi(ostream &os) {
    GetOperande()->afficher_npi(os);
    os << " ln";
}

float LogNeperien::calculer() {
    float x = GetOperande()->calculer();
    if (x <= 0.0f) return std::numeric_limits<float>::quiet_NaN();
    return std::log(x);
}
