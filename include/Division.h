#ifndef DIVISION_H
#define DIVISION_H

#include "OperateurBinaire.h"


class Division : public OperateurBinaire
{
    public:
        Division(Expression *opg, Expression *opd);
        virtual ~Division();

        void afficher_classique(ostream &os = cout) override;
        void afficher_npi(ostream &os = cout) override;
        float calculer() override;

    protected:

    private:
};

#endif // DIVISION_H
