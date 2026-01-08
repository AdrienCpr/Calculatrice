#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Expression
{
public:
    Expression();
    virtual ~Expression();

    virtual void afficher_classique(ostream &os = cout) = 0;
    virtual void afficher_npi(ostream &os = cout) = 0;
    virtual float calculer() = 0;

    virtual unique_ptr<Expression> simplify() const { return nullptr; }

    virtual double eval() const { return static_cast<double>(const_cast<Expression*>(this)->calculer()); }

    virtual void print(ostream& os) const { const_cast<Expression*>(this)->afficher_classique(os); }
};

inline std::ostream& operator<<(std::ostream& os, const Expression& expr) {
    expr.print(os);
    return os;
}

void sauvegarder_npi(Expression &expr, const std::string &nomFichier);
Expression* charger_npi(std::istream &is);
Expression* charger_npi_fichier(const std::string &nomFichier);

#endif // EXPRESSION_H
