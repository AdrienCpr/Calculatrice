#include "Addition.h"

Addition::Addition(Expression *opg, Expression *opd) : OperateurBinaire(opg, opd)
{
}

Addition::~Addition()
{
}

void Addition::afficher_classique(std::ostream &os) const {
    os << "(";
    GetOperandeGauche()->print(os);
    os << " + ";
    GetOperandeDroit()->print(os);
    os << ")";
}

void Addition::afficher_npi(std::ostream &os) const {
    GetOperandeGauche()->print(os);
    os << " ";
    GetOperandeDroit()->print(os);
    os << " +";
}

float Addition::calculer() const {
    return static_cast<float>(GetOperandeGauche()->eval() + GetOperandeDroit()->eval());
}

std::unique_ptr<Expression> Addition::simplify() const {
    auto leftS = GetOperandeGauche()->simplify();
    auto rightS = GetOperandeDroit()->simplify();

    auto leftConst = dynamic_cast<ConstExpr*>(leftS.get());
    auto rightConst = dynamic_cast<ConstExpr*>(rightS.get());

    if (leftConst && rightConst) {
        double result = leftConst->value() + rightConst->value();
        return std::make_unique<ConstExpr>(result);
    }

    return std::make_unique<BinaryExpr>(OpType::Add, std::move(leftS), std::move(rightS));
}
