#include "Multiplication.h"

Multiplication::Multiplication(Expression *opg, Expression *opd)
    : OperateurBinaire(opg, opd) {}

Multiplication::~Multiplication() {}

void Multiplication::afficher_classique(ostream &os) {
    os << '(';
    GetOperandeGauche()->afficher_classique(os);
    os << " * ";
    GetOperandeDroit()->afficher_classique(os);
    os << ')';
    os << '\n';
}

void Multiplication::afficher_npi(ostream &os) {
    GetOperandeGauche()->afficher_npi(os);
    os << ' ';
    GetOperandeDroit()->afficher_npi(os);
    os << " *\n";
}

float Multiplication::calculer() {
    return GetOperandeGauche()->calculer() * GetOperandeDroit()->calculer();
}
