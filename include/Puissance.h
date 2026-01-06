#ifndef PUISSANCE_H
#define PUISSANCE_H

#include "OperateurBinaire.h"

class Puissance : public OperateurBinaire
{
public:
    Puissance(Expression *opg, Expression *opd);
    virtual ~Puissance();

    void afficher_classique(ostream &os = cout) override;
    void afficher_npi(ostream &os = cout) override;
    float calculer() override;
};

#endif
