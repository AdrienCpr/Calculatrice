#include "Puissance.h"
#include <cmath>

Puissance::Puissance(Expression *opg, Expression *opd)
    : OperateurBinaire(opg, opd)
{
}

Puissance::~Puissance()
{
}

void Puissance::afficher_classique(ostream &os)
{
    os << "( ";
    GetOperandeGauche()->afficher_classique(os);
    os << " ^ ";
    GetOperandeDroit()->afficher_classique(os);
    os << " )";
}

void Puissance::afficher_npi(ostream &os)
{
    GetOperandeGauche()->afficher_npi(os);
    os << " ";
    GetOperandeDroit()->afficher_npi(os);
    os << " ^";
}

float Puissance::calculer()
{
    return std::pow(
        GetOperandeGauche()->calculer(),
        GetOperandeDroit()->calculer()
        );
}
