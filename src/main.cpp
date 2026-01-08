#include "mainwindow.h"
#include <QApplication>

#include <iostream>

#include "TestsRunner.h"
#include "ExpressionManager.h"

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Multiplication.h"
#include "Division.h"

using namespace std;

int main(int argc, char *argv[])
{
    TestsRunner::run_all_tests();

    Expression* expr =
        new Soustraction(
            new Multiplication(
                new Addition(new Constante(20.0f), new Constante(30.0f)),
                new Constante(2.0f)
                ),
            new Constante(5.0f)
            );

    ExpressionManager::Instance().setExpression(expr);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int ret = a.exec();

    ExpressionManager::Instance().clear();

    return ret;
}
