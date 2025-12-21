// BinaryExpr.h
#pragma once
#include "Expression.h"
#include "ConstExpr.h"
#include <memory>

enum class OpType {
    Add,
    Sub,
    Mul,
    Div
};

class BinaryExpr : public Expression {
public:
    BinaryExpr(OpType op,
               std::unique_ptr<Expression> left,
               std::unique_ptr<Expression> right)
        : m_op(op), m_left(std::move(left)), m_right(std::move(right)) {}

    std::unique_ptr<Expression> simplify() const override {
        // 1) Simplifier récursivement les sous-expressions
        auto leftS  = m_left->simplify();
        auto rightS = m_right->simplify();

        // 2) Si les deux sont des constantes -> on calcule
        auto leftConst  = dynamic_cast<ConstExpr*>(leftS.get());
        auto rightConst = dynamic_cast<ConstExpr*>(rightS.get());

        if (leftConst && rightConst) {
            double lv = leftConst->value();
            double rv = rightConst->value();
            double result = 0.0;

            switch (m_op) {
                case OpType::Add: result = lv + rv; break;
                case OpType::Sub: result = lv - rv; break;
                case OpType::Mul: result = lv * rv; break;
                case OpType::Div:
                    // à gérer proprement (division par 0)
                    result = lv / rv;
                    break;
            }

            // Retourner une nouvelle constante
            return std::make_unique<ConstExpr>(result);
        }

        // 3) Sinon on retourne une nouvelle opération binaire avec les enfants déjà simplifiés
        return std::make_unique<BinaryExpr>(m_op, std::move(leftS), std::move(rightS));
    }

    double eval() const override {
        double lv = m_left->eval();
        double rv = m_right->eval();

        switch (m_op) {
            case OpType::Add: return lv + rv;
            case OpType::Sub: return lv - rv;
            case OpType::Mul: return lv * rv;
            case OpType::Div: return lv / rv; // idem: gérer /0
        }
        return 0; // pour calmer le compilateur
    }

    void print(std::ostream& os) const override {
        os << "(";
        m_left->print(os);
        os << opToString(m_op);
        m_right->print(os);
        os << ")";
    }

private:
    static const char* opToString(OpType op) {
        switch (op) {
            case OpType::Add: return " + ";
            case OpType::Sub: return " - ";
            case OpType::Mul: return " * ";
            case OpType::Div: return " / ";
        }
        return " ?";
    }

    OpType m_op;
    std::unique_ptr<Expression> m_left;
    std::unique_ptr<Expression> m_right;
};
