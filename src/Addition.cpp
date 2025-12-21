#include "Addition.h"

Addition::Addition(Expression *opg, Expression *opd) : OperateurBinaire(opg, opd)
{

}

Addition::~Addition()
{
    //dtor
}


void Addition::afficher_classique(ostream &os) {
    cout << "( ";
    GetOperandeGauche()->afficher_classique();
    cout << " + ";
    GetOperandeDroit()->afficher_classique();
    cout << " )";
}

void Addition::afficher_npi(ostream &os) {
    cout << "\n ";
    GetOperandeGauche()->afficher_npi();
    cout << " ";
    GetOperandeDroit()->afficher_npi();
    cout << " +\n";
}

float Addition::calculer() {
    return GetOperandeGauche()->calculer() + GetOperandeDroit()->calculer();
}
