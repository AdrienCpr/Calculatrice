// VarExpr.h
#pragma once
#include "Expression.h"
#include <string>
#include <iostream>

class VarExpr : public Expression {
public:
    explicit VarExpr(std::string name) : m_name(std::move(name)) {}

    std::unique_ptr<Expression> simplify() const override {
        return std::make_unique<VarExpr>(m_name);
    }

    double eval() const override {
        // Valeur inconnue; ici on retourne 0.0 mais on pourrait lever une exception
        return 0.0;
    }

    void print(std::ostream& os) const override {
        os << m_name;
    }

private:
    std::string m_name;
};
