#include "Division.h"
#include <stdexcept>

Division::Division(Expression *opg, Expression *opd)
    : OperateurBinaire(opg, opd) {}

Division::~Division() {}

void Division::afficher_classique(ostream &os) {
    os << '(';
    GetOperandeGauche()->afficher_classique(os);
    os << " / ";
    GetOperandeDroit()->afficher_classique(os);
    os << ')';
    os << '\n';
}

void Division::afficher_npi(ostream &os) {
    GetOperandeGauche()->afficher_npi(os);
    os << ' ';
    GetOperandeDroit()->afficher_npi(os);
    os << " /\n";
}

float Division::calculer() {
    float d = GetOperandeDroit()->calculer();
    if (d == 0.0f) throw std::runtime_error("Division par zero");
    return GetOperandeGauche()->calculer() / d;
}
