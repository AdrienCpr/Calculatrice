#include "Division.h"

Division::Division(Expression *opg, Expression *opd) : OperateurBinaire(opg, opd)
{
}

Division::~Division()
{
}


void Division::afficher_classique(std::ostream &os) const {
    os << "(";
    GetOperandeGauche()->print(os);
    os << " / ";
    GetOperandeDroit()->print(os);
    os << ")";
}

void Division::afficher_npi(std::ostream &os) const {
    GetOperandeGauche()->print(os);
    os << " ";
    GetOperandeDroit()->print(os);
    os << " /";
}


float Division::calculer() const {
    double denominateur = GetOperandeDroit()->eval();

    if (denominateur == 0) {
        std::cerr << "Erreur : division par zero !" << std::endl;
        return 0;
    }

    return static_cast<float>(GetOperandeGauche()->eval() / denominateur);
}

std::unique_ptr<Expression> Division::simplify() const {
    auto leftS = GetOperandeGauche()->simplify();
    auto rightS = GetOperandeDroit()->simplify();

    auto leftConst = dynamic_cast<ConstExpr*>(leftS.get());
    auto rightConst = dynamic_cast<ConstExpr*>(rightS.get());

    if (leftConst && rightConst) {
        double result = leftConst->value() / rightConst->value();
        return std::make_unique<ConstExpr>(result);
    }

    return std::make_unique<BinaryExpr>(OpType::Div, std::move(leftS), std::move(rightS));
}
