// RacineCarree.h
#ifndef RACINECARREE_H
#define RACINECARREE_H

#include "OperateurUnaire.h"

class RacineCarree : public OperateurUnaire
{
public:
    RacineCarree(Expression* op);
    virtual ~RacineCarree();

    void afficher_classique(ostream &os = cout) override;
    void afficher_npi(ostream &os = cout) override;
    float calculer() override;
};

#endif
