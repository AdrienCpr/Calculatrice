#ifndef SOUSTRACTION_H
#define SOUSTRACTION_H

#include "OperateurBinaire.h"
#include <iostream>
#include "ConstExpr.h"
#include "BinaryExpr.h"


class Soustraction : public OperateurBinaire
{
    public:
        Soustraction(Expression *opg, Expression *opd);
        virtual ~Soustraction();

        void afficher_classique(std::ostream &os = std::cout) const;
        void afficher_npi(std::ostream &os = std::cout) const;
        float calculer() const;

        // Expression interface
        std::unique_ptr<Expression> simplify() const override;
        double eval() const override { return static_cast<double>(calculer()); }
        void print(std::ostream &os) const override { afficher_classique(os); }

    protected:

    private:
};

#endif // SOUSTRACTION_H
