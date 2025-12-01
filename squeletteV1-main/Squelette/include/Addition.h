#ifndef ADDITION_H
#define ADDITION_H

#include "OperateurBinaire.h"


class Addition : public OperateurBinaire
{
    public:
        Addition(Expression *opg, Expression *opd);
        virtual ~Addition();

        void afficher_classique(ostream &os = cout) override;
        void afficher_npi(ostream &os = cout) override;
        float calculer() override;
    protected:

    private:
};

#endif // ADDITION_H
