#include "ValeurAbsolue.h"
#include <cmath>

ValeurAbsolue::ValeurAbsolue(Expression* op)
    : OperateurUnaire(op)
{
}

ValeurAbsolue::~ValeurAbsolue()
{
}

void ValeurAbsolue::afficher_classique(ostream &os)
{
    os << "abs(";
    GetOperande()->afficher_classique(os);
    os << ")";
}

void ValeurAbsolue::afficher_npi(ostream &os)
{
    GetOperande()->afficher_npi(os);
    os << " abs";
}

float ValeurAbsolue::calculer()
{
    return std::fabs(GetOperande()->calculer());
}
