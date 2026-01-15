// ConstExpr.hpp
#pragma once
#include "Expression.h"

class ConstExpr : public Expression {
public:
    explicit ConstExpr(double value) : m_value(value) {}

    std::unique_ptr<Expression> simplify() const override {
        // Une constante est dejà simplifiee
        return std::make_unique<ConstExpr>(m_value);
    }

    double eval() const override {
        return m_value;
    }

    void print(std::ostream& os) const override {
        os << m_value;
    }

    double value() const { return m_value; }

private:
    double m_value;
};
