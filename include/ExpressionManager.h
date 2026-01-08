#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H

#include "Expression.h"

class ExpressionManager
{
public:
    static ExpressionManager& Instance()
    {
        static ExpressionManager instance;
        return instance;
    }

    void setExpression(Expression* e)
    {
        if (currentExpression == e) return;
        delete currentExpression;        // 🔧 CHANGEMENT CLÉ
        currentExpression = e;
    }

    Expression* getExpression() const
    {
        return currentExpression;
    }

    void clear()
    {
        delete currentExpression;
        currentExpression = nullptr;
    }

private:
    Expression* currentExpression = nullptr;

    ExpressionManager() = default;
    ~ExpressionManager()
    {
        delete currentExpression;
    }

    ExpressionManager(const ExpressionManager&) = delete;
    ExpressionManager& operator=(const ExpressionManager&) = delete;
};

#endif
