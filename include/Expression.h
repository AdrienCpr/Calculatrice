#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
using namespace std;

class Expression
{
    public:
        Expression();
        virtual ~Expression();

        virtual void afficher_classique(ostream &os = cout) = 0;
        virtual void afficher_npi(ostream &os = cout) = 0;
        virtual float calculer() = 0;

    protected:

    private:
};

#endif // EXPRESSION_H
