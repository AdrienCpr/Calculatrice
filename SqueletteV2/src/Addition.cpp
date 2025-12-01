#include "Addition.h"

Addition::Addition(Expression *opg, Expression *opd)
    : OperateurBinaire(opg, opd) {}

Addition::~Addition() {}

void Addition::afficher_classique(ostream &os) {
    os << '(';
    GetOperandeGauche()->afficher_classique(os);
    os << " + ";
    GetOperandeDroit()->afficher_classique(os);
    os << ')';
    os << '\n';
}

void Addition::afficher_npi(ostream &os) {
    GetOperandeGauche()->afficher_npi(os);
    os << ' ';
    GetOperandeDroit()->afficher_npi(os);
    os << " +\n";
}

float Addition::calculer() {
    return GetOperandeGauche()->calculer() + GetOperandeDroit()->calculer();
}
