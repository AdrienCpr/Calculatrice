// Expression.h
#pragma once
#include <memory>
#include <iostream>

class Expression {
public:
    virtual ~Expression() = default;

    // Renvoie une nouvelle expression simplifiee
    virtual std::unique_ptr<Expression> simplify() const = 0;

    // Évaluation numerique (si possible)
    virtual double eval() const = 0;

    // Pour afficher l’expression (debug)
    virtual void print(std::ostream& os) const = 0;
};

inline std::ostream& operator<<(std::ostream& os, const Expression& expr) {
    expr.print(os);
    return os;
}
