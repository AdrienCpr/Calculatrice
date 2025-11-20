#include "Addition.h"

Addition::Addition(Expression *opg, Expression *opd) : OperateurBinaire(opg, opd)
{
    // à compléter
}

Addition::~Addition()
{
    //dtor
}

void Addition::afficher_classique(ostream &os) {
    GetOperandeGauche()->afficher_classique(os);
    os << " + ";
    GetOperandeDroit()->afficher_classique(os);
}

void Addition::afficher_npi(ostream &os) {
    GetOperandeGauche()->afficher_classique(os);
    os << " ";
    GetOperandeDroit()->afficher_classique(os);
    os << " +";
}

float Addition::calculer() {
    return GetOperandeGauche()->calculer() + GetOperandeDroit()->calculer();
}
