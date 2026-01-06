
// LogNeperien.h
#ifndef LOGNEPERIEN_H
#define LOGNEPERIEN_H

#include "OperateurUnaire.h"

class LogNeperien : public OperateurUnaire
{
public:
    LogNeperien(Expression* op);
    virtual ~LogNeperien();

    void afficher_classique(ostream &os = cout) override;
    void afficher_npi(ostream &os = cout) override;
    float calculer() override;
};

#endif
