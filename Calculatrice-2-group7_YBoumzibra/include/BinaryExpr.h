// BinaryExpr.h
#pragma once
#include "Expression.h"
#include "ConstExpr.h"
#include <memory>
#include <vector>
#include <functional>

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
        // 1) Simplifier r�cursivement les sous-expressions
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
                    // � g�rer proprement (division par 0)
                    result = lv / rv;
                    break;
            }

            // Retourner une nouvelle constante
            return std::make_unique<ConstExpr>(result);
        }

        // 3) Simplifications algébriques supplémentaires pour les additions (aplatissement)
        if (m_op == OpType::Add) {
            // On va rassembler les termes non-constants et sommer toutes les constantes
            std::vector<std::unique_ptr<Expression>> terms;
            double constSum = 0.0;

            // helper lambda: prend ownership d'une expression, et aplatie les additions
            std::function<void(std::unique_ptr<Expression>)> collect = [&](std::unique_ptr<Expression> node) {
                if (!node) return;

                // Si c'est une constante -> ajouter à constSum
                if (auto c = dynamic_cast<ConstExpr*>(node.get())) {
                    constSum += c->value();
                    return;
                }

                // Si c'est une BinaryExpr d'addition -> extraire ses enfants et les traiter
                if (auto b = dynamic_cast<BinaryExpr*>(node.get())) {
                    if (b->m_op == OpType::Add) {
                        // Extraire les enfants (on prend ownership)
                        std::unique_ptr<Expression> leftChild = std::move(b->m_left);
                        std::unique_ptr<Expression> rightChild = std::move(b->m_right);
                        // libérer node (b) avant de récursivement collecter
                        // node ira être détruit à la sortie de cette lambda si non utilisé
                        collect(std::move(leftChild));
                        collect(std::move(rightChild));
                        return;
                    }
                }

                // Sinon garder le terme
                terms.push_back(std::move(node));
            };

            // Collecter depuis les deux côtés
            collect(std::move(leftS));
            collect(std::move(rightS));

            // Si on a une somme constante, l'ajouter comme terme
            if (constSum != 0.0) {
                terms.push_back(std::make_unique<ConstExpr>(constSum));
            }

            // Reconstruire l'expression: si aucun terme -> 0
            if (terms.empty()) {
                return std::make_unique<ConstExpr>(0.0);
            }

            // Si un seul terme -> le retourner
            if (terms.size() == 1) {
                return std::move(terms.front());
            }

            // Sinon reconstituer une BinaryExpr en chaînant les termes de gauche à droite
            std::unique_ptr<Expression> acc = std::move(terms[0]);
            for (size_t i = 1; i < terms.size(); ++i) {
                acc = std::make_unique<BinaryExpr>(OpType::Add, std::move(acc), std::move(terms[i]));
            }

            return acc;
        }

        // 4) Sinon on retourne une nouvelle opération binaire avec les enfants déjà simplifiés
        return std::make_unique<BinaryExpr>(m_op, std::move(leftS), std::move(rightS));
    }

    double eval() const override {
        double lv = m_left->eval();
        double rv = m_right->eval();

        switch (m_op) {
            case OpType::Add: return lv + rv;
            case OpType::Sub: return lv - rv;
            case OpType::Mul: return lv * rv;
            case OpType::Div: return lv / rv; // idem: g�rer /0
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
