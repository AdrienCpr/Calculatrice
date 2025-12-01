#include "Soustraction.h"

Soustraction::Soustraction(Expression *opg, Expression *opd)
    : OperateurBinaire(opg, opd) {}

Soustraction::~Soustraction() {}

void Soustraction::afficher_classique(ostream &os) {
    os << '(';
    GetOperandeGauche()->afficher_classique(os);
    os << " - ";
    GetOperandeDroit()->afficher_classique(os);
    os << ')';
    os << '\n';
}

void Soustraction::afficher_npi(ostream &os) {
    GetOperandeGauche()->afficher_npi(os);
    os << ' ';
    GetOperandeDroit()->afficher_npi(os);
    os << " -\n";
}

float Soustraction::calculer() {
    return GetOperandeGauche()->calculer() - GetOperandeDroit()->calculer();
}
