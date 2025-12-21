// Oppose.h
#ifndef OPPOSE_H
#define OPPOSE_H

#include "OperateurUnaire.h"

class Oppose : public OperateurUnaire
{
public:
    Oppose(Expression* op);
    virtual ~Oppose();

    void afficher_classique(ostream &os = cout) override;
    void afficher_npi(ostream &os = cout) override;
    float calculer() override;
};

#endif
