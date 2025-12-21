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
    cout << "( ";
    GetOperandeGauche()->afficher_classique();
    cout << " x ";
    GetOperandeDroit()->afficher_classique();
    cout << " )";
}

void Multiplication::afficher_npi(ostream &os) {
    GetOperandeGauche()->afficher_npi();
    cout << " ";
    GetOperandeDroit()->afficher_npi();
    cout << " x\n";
}

float Multiplication::calculer() {
    return GetOperandeGauche()->calculer() * GetOperandeDroit()->calculer();
}
