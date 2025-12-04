#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H

#include "Singleton.h"
#include "Expression.h"

class ExpressionManager : public Singleton<ExpressionManager> {
    friend class Singleton<ExpressionManager>;

private:
    Expression* currentExpression = nullptr;

    ExpressionManager() = default;
    ~ExpressionManager() = default;

public:
    void setExpression(Expression* e) {
        currentExpression = e;
    }

    Expression* getExpression() const {
        return currentExpression;
    }
};

#endif
