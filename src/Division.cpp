#include "Division.h"

Division::Division(Expression *opg, Expression *opd) : OperateurBinaire(opg, opd)
{
}

Division::~Division()
{
    //dtor
}


void Division::afficher_classique(ostream &os) {
    cout << "( ";
    GetOperandeGauche()->afficher_classique();
    cout << " / ";
    GetOperandeDroit()->afficher_classique();
    cout << " )";
}

void Division::afficher_npi(ostream &os) {
    GetOperandeGauche()->afficher_npi();
    cout << " ";
    GetOperandeDroit()->afficher_npi();
    cout << " /\n";
}


float Division::calculer() {
    return GetOperandeGauche()->calculer() / GetOperandeDroit()->calculer();
}
