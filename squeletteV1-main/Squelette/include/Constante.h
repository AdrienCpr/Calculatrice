#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "Expression.h"


class Constante : public Expression
{
    public:
        Constante(float valeur = 10.0);
        virtual ~Constante();

        float Getvaleur() { return m_valeur; }
        void Setvaleur(float val) { m_valeur = val; }

        void afficher_classique(ostream &os = cout) override;
        void afficher_npi(ostream &os = cout) override;
        float calculer() override;

    protected:

    private:
        float m_valeur;
};

#endif // CONSTANTE_H
