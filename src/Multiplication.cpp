#include "Multiplication.h"

Multiplication::Multiplication(Expression *opg, Expression *opd) : OperateurBinaire(opg, opd)
{
    //ctor
}

Multiplication::~Multiplication()
{
    //dtor
}

void Multiplication::afficher_classique(ostream &os) {
    GetOperandeGauche()->afficher_classique(os);
    os << " * ";
    GetOperandeDroit()->afficher_classique(os);
}

void Multiplication::afficher_npi(ostream &os) {
    GetOperandeGauche()->afficher_npi(os);
    os << " ";
    GetOperandeDroit()->afficher_npi(os);
    os << " *";
}

float Multiplication::calculer() {
    return GetOperandeGauche()->calculer() * GetOperandeDroit()->calculer();
}
