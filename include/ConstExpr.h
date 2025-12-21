#pragma once
#include "Expression.h"
#include <memory>
#include <iostream>

class ConstExpr : public Expression {
    double value;

public:
    explicit ConstExpr(double v) : value(v) {}

    // Ancienne interface (OBLIGATOIRE)
    void afficher_classique(std::ostream& os = std::cout) override { os << value; }
    void afficher_npi(std::ostream& os = std::cout) override { os << value; }
    float calculer() override { return static_cast<float>(value); }

    // Nouvelle feature
    std::unique_ptr<Expression> simplify() const override {
        return std::make_unique<ConstExpr>(value);
    }
    double eval() const override { return value; }
    void print(std::ostream& os) const override { os << value; }
};
