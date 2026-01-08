#include "Carre.h"

Carre::Carre(Expression* op)
    : OperateurUnaire(op)
{
}

Carre::~Carre()
{
}

void Carre::afficher_classique(ostream &os)
{
    os << "(";
    GetOperande()->afficher_classique(os);
    os << ")^2";
}

void Carre::afficher_npi(ostream &os)
{
    GetOperande()->afficher_npi(os);
    os << " sq";
}

float Carre::calculer()
{
    float x = GetOperande()->calculer();
    return x * x;
}
