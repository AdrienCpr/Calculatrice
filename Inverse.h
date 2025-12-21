#ifndef INVERSE_H
#define INVERSE_H

#include "OperateurUnaire.h"

class Inverse : public OperateurUnaire
{
public:
    Inverse(Expression* op);
    virtual ~Inverse();

    void afficher_classique(ostream &os = cout) override;
    void afficher_npi(ostream &os = cout) override;
    float calculer() override;
};

#endif
