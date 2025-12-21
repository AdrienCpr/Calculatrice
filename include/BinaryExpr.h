#pragma once
#include "Expression.h"
#include <memory>
#include <iostream>
#include "ConstExpr.h"

enum class OpType { Add, Sub, Mul, Div };

class BinaryExpr : public Expression {
    OpType op;
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;

public:
    BinaryExpr(OpType o, std::unique_ptr<Expression> l, std::unique_ptr<Expression> r)
        : op(o), left(std::move(l)), right(std::move(r)) {}

    // Ancienne interface (OBLIGATOIRE)
    void afficher_classique(std::ostream& os = std::cout) override {
        os << "(";
        left->afficher_classique(os);
        os << " ";
        switch(op){
            case OpType::Add: os << "+"; break;
            case OpType::Sub: os << "-"; break;
            case OpType::Mul: os << "*"; break;
            case OpType::Div: os << "/"; break;
        }
        os << " ";
        right->afficher_classique(os);
        os << ")";
    }

    void afficher_npi(std::ostream& os = std::cout) override {
        left->afficher_npi(os);  os << " ";
        right->afficher_npi(os); os << " ";
        switch(op){
            case OpType::Add: os << "+"; break;
            case OpType::Sub: os << "-"; break;
            case OpType::Mul: os << "*"; break;
            case OpType::Div: os << "/"; break;
        }
    }

    float calculer() override {
        float a = left->calculer();
        float b = right->calculer();
        switch(op){
            case OpType::Add: return a + b;
            case OpType::Sub: return a - b;
            case OpType::Mul: return a * b;
            case OpType::Div: return a / b;
        }
        return 0.0f;
    }

    // Nouvelle feature
    double eval() const override {
        // par défaut on réutilise calculer()
        return static_cast<double>(const_cast<BinaryExpr*>(this)->calculer());
    }

    void print(std::ostream& os) const override {
        // debug = affichage classique
        const_cast<BinaryExpr*>(this)->afficher_classique(os);
    }

    std::unique_ptr<Expression> simplify() const override {
        // 1) Simplification récursive des enfants
        auto l = left->simplify();
        auto r = right->simplify();

        // 2) Constant folding : si les deux côtés sont des constantes, on calcule
        auto lc = dynamic_cast<ConstExpr*>(l.get());
        auto rc = dynamic_cast<ConstExpr*>(r.get());

        if (lc && rc) {
            double a = lc->eval();
            double b = rc->eval();
            double res = 0.0;

            switch (op) {
                case OpType::Add: res = a + b; break;
                case OpType::Sub: res = a - b; break;
                case OpType::Mul: res = a * b; break;
                case OpType::Div: res = a / b; break;
            }
            return std::make_unique<ConstExpr>(res);
        }

        // 3) Sinon on retourne un nouvel arbre (jamais nullptr)
        return std::make_unique<BinaryExpr>(op, std::move(l), std::move(r));
    }
};
