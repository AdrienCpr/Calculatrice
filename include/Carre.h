#ifndef CARRE_H
#define CARRE_H

#include "OperateurUnaire.h"

class Carre : public OperateurUnaire
{
public:
    Carre(Expression* op);
    virtual ~Carre();

    void afficher_classique(ostream &os = cout) override;
    void afficher_npi(ostream &os = cout) override;
    float calculer() override;
};

#endif
