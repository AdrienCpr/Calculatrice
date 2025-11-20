#include "Soustraction.h"

Soustraction::Soustraction(Expression *opg, Expression *opd) : OperateurBinaire(opg, opd)
{
    //ctor
}

Soustraction::~Soustraction()
{
    //dtor
}

void Soustraction::afficher_classique(ostream &os) {
    GetOperandeGauche()->afficher_classique(os);
    os << " - ";
    GetOperandeDroit()->afficher_classique(os);
}

void Soustraction::afficher_npi(ostream &os) {
    GetOperandeGauche()->afficher_classique(os);
    os << " ";
    GetOperandeDroit()->afficher_classique(os);
    os << " -";
}

float Soustraction::calculer() {
    return GetOperandeGauche()->calculer() - GetOperandeDroit()->calculer();
}
