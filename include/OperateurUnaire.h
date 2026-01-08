#ifndef OPERATEURUNAIRE_H
#define OPERATEURUNAIRE_H

#include "Expression.h"

class OperateurUnaire : public Expression
{
public:
    OperateurUnaire(Expression *op);
    virtual ~OperateurUnaire();

    Expression* GetOperande() { return m_operande; }
    void SetOperande(Expression* op) { m_operande = op; }

private:
    Expression* m_operande;
};

#endif
