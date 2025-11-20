#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "OperateurBinaire.h"


class Multiplication : public OperateurBinaire
{
    public:
        Multiplication(Expression *opg, Expression *opd);
        virtual ~Multiplication();

        void afficher_classique(ostream &os = cout) override;
        void afficher_npi(ostream &os = cout) override;
        float calculer() override;

    protected:

    private:
};

#endif // MULTIPLICATION_H
