#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "Expression.h"
#include <iostream>
#include "ConstExpr.h"


class Constante : public Expression
{
    public:
        Constante(float valeur = 10.0);
        virtual ~Constante();

        float Getvaleur() const { return m_valeur; }
        void Setvaleur(float val) { m_valeur = val; }

        void afficher_classique(std::ostream &os = std::cout) const;
        void afficher_npi(std::ostream &os = std::cout) const;
        float calculer() const;

        // Expression interface
        std::unique_ptr<Expression> simplify() const override {
            return std::make_unique<ConstExpr>(m_valeur);
        }

        double eval() const override {
            return static_cast<double>(calculer());
        }

        void print(std::ostream &os) const override {
            afficher_classique(os);
        }

    protected:

    private:
        float m_valeur;
};

#endif // CONSTANTE_H
