#include "OperateurUnaire.h"

OperateurUnaire::OperateurUnaire(Expression *op)
    : m_operande(op)
{
}

OperateurUnaire::~OperateurUnaire()
{
    delete m_operande;
    m_operande = nullptr;
}
