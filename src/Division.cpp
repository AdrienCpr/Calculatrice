#include "Division.h"

Division::Division(Expression *opg, Expression *opd) : OperateurBinaire(opg, opd)
{
}

Division::~Division()
{
    //dtor
}



void Division::afficher_classique(ostream &os)
{
    GetOperandeGauche()->afficher_classique(os);
    os << " / ";
    GetOperandeDroit()->afficher_classique(os);
}

void Division::afficher_npi(ostream &os)
{
    GetOperandeGauche()->afficher_npi(os);
    os << " ";
    GetOperandeDroit()->afficher_npi(os);
    os << " /";
}

float Division::calculer()
{
    float denominateur = GetOperandeDroit()->calculer();

    if (denominateur == 0.0f) {
        cerr << "Erreur : division par zéro !" << endl;
        return 0.0f;
    }

    return GetOperandeGauche()->calculer() / denominateur;
}
