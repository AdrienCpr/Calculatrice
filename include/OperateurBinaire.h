#ifndef OPERATEURBINAIRE_H
#define OPERATEURBINAIRE_H

#include "Expression.h"


class OperateurBinaire : public Expression
{
    public:
        OperateurBinaire(Expression *opg, Expression *opd);
        virtual ~OperateurBinaire();

        Expression * GetOperandeGauche() { return m_OperandeGauche; }
        void SetOperandeGauche(Expression * val) { m_OperandeGauche = val; }
        Expression * GetOperandeDroit() { return m_OperandeDroit; }
        void SetOperandeDroit(Expression * val) { m_OperandeDroit = val; }

    protected:

    private:
        Expression * m_OperandeGauche;
        Expression * m_OperandeDroit;
};

#endif // OPERATEURBINAIRE_H
