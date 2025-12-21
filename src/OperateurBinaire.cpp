#include "OperateurBinaire.h"

OperateurBinaire::OperateurBinaire(Expression *opg, Expression *opd)
{
    SetOperandeGauche(opg);
    SetOperandeDroit(opd);
}

OperateurBinaire::~OperateurBinaire()
{
    //dtor
}
