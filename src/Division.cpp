#include "Division.h"

Division::Division(Expression *opg, Expression *opd) : OperateurBinaire(opg, opd)
{
}

Division::~Division()
{
    //dtor
}


void Division::afficher_classique(ostream &os) {
    GetOperandeGauche()->afficher_classique(os);
    os << " / ";
    GetOperandeDroit()->afficher_classique(os);
}

void Division::afficher_npi(ostream &os) {
    GetOperandeGauche()->afficher_classique(os);
    os << " ";
    GetOperandeDroit()->afficher_classique(os);
    os << " /";
}


float Division::calculer() {
    float denominateur = GetOperandeDroit()->calculer();

    if (denominateur == 0) {
        cerr << "Erreur : division par zéro !" << endl;
        return 0;
    }

    return GetOperandeGauche()->calculer() / denominateur;
}
