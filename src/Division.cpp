#include "Division.h"
#include <iostream>    // pour cerr

using namespace std;

Division::Division(Expression *opg, Expression *opd) : OperateurBinaire(opg, opd)
{
}

Division::~Division()
{
    // dtor
}

void Division::afficher_classique(ostream &os) {
    GetOperandeGauche()->afficher_classique(os);
    os << " / ";
    GetOperandeDroit()->afficher_classique(os);
}

void Division::afficher_npi(ostream &os) {
    // Meme logique que Addition / Soustraction / Multiplication
    GetOperandeGauche()->afficher_classique(os);
    os << " ";
    GetOperandeDroit()->afficher_classique(os);
    os << " /";
}

float Division::calculer() {
    float denominateur = GetOperandeDroit()->calculer();

    if (denominateur == 0) {
        cerr << "Erreur : division par zero !" << endl;
        return 0;
    }

    return GetOperandeGauche()->calculer() / denominateur;
}
