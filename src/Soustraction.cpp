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
    cout << "( ";
    GetOperandeGauche()->afficher_classique();
    cout << " - ";
    GetOperandeDroit()->afficher_classique();
    cout << " )";
}

void Soustraction::afficher_npi(ostream &os) {
    GetOperandeGauche()->afficher_npi();
    cout << " ";
    GetOperandeDroit()->afficher_npi();
    cout << " -\n";
}

float Soustraction::calculer() {
    return GetOperandeGauche()->calculer() - GetOperandeDroit()->calculer();
}
