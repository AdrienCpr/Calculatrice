#ifndef SOUSTRACTION_H
#define SOUSTRACTION_H

#include "OperateurBinaire.h"


class Soustraction : public OperateurBinaire
{
    public:
        Soustraction(Expression *opg, Expression *opd);
        virtual ~Soustraction();

        void afficher_classique(ostream &os = cout) override;
        void afficher_npi(ostream &os = cout) override;
        float calculer() override;

    protected:

    private:
};

#endif // SOUSTRACTION_H
