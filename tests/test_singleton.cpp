#include <iostream>
#include "ExpressionManager.h"
#include "Constante.h"

using namespace std;

int test_singleton() {
    cout << "[TEST Singleton] " << endl;

    Constante c1(10);
    ExpressionManager::Instance().setExpression(&c1);

    if (ExpressionManager::Instance().getExpression() == &c1)
        cout << "OK : Singleton fonctionne." << endl;
    else
        cout << "ERREUR : Singleton ne stocke pas correctement." << endl;

    return 0;
}