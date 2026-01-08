#ifndef VALEURABSOLUE_H
#define VALEURABSOLUE_H

#include "OperateurUnaire.h"

class ValeurAbsolue : public OperateurUnaire
{
public:
    ValeurAbsolue(Expression* op);
    virtual ~ValeurAbsolue();

    void afficher_classique(ostream &os = cout) override;
    void afficher_npi(ostream &os = cout) override;
    float calculer() override;
};

#endif
