#include "OperateurBinaire.h"

OperateurBinaire::OperateurBinaire(Expression *opg, Expression *opd)
{
    m_OperandeGauche = opg;
    m_OperandeDroit = opd;
}

OperateurBinaire::~OperateurBinaire()
{
    delete m_OperandeGauche;
    delete m_OperandeDroit;
}
