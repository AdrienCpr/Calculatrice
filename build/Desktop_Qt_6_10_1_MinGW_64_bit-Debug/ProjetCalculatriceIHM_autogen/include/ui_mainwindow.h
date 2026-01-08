/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *leExpr;
    QHBoxLayout *topRow;
    QLabel *lblX;
    QDoubleSpinBox *sbX;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnLoad;
    QGridLayout *gridButtons;
    QPushButton *btnSqrt;
    QPushButton *btnLn;
    QPushButton *btnAbs;
    QPushButton *btnInv;
    QPushButton *btnSq;
    QPushButton *btnClear;
    QPushButton *btnDel;
    QPushButton *btnLPar;
    QPushButton *btnRPar;
    QPushButton *btnPow;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;
    QPushButton *btnDiv;
    QPushButton *btnNeg;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btnMul;
    QPushButton *btnX;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btnMinus;
    QPushButton *btnPlus;
    QPushButton *btn0;
    QPushButton *btnDot;
    QPushButton *btnSpace;
    QPushButton *btnEval;
    QLabel *lblResult;
    QPlainTextEdit *pteDetails;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        leExpr = new QLineEdit(centralwidget);
        leExpr->setObjectName("leExpr");
        leExpr->setMinimumHeight(40);

        verticalLayout->addWidget(leExpr);

        topRow = new QHBoxLayout();
        topRow->setObjectName("topRow");
        lblX = new QLabel(centralwidget);
        lblX->setObjectName("lblX");

        topRow->addWidget(lblX);

        sbX = new QDoubleSpinBox(centralwidget);
        sbX->setObjectName("sbX");
        sbX->setMinimum(-1000000.000000000000000);
        sbX->setMaximum(1000000.000000000000000);
        sbX->setDecimals(6);
        sbX->setValue(0.000000000000000);

        topRow->addWidget(sbX);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        topRow->addItem(horizontalSpacer);

        btnSave = new QPushButton(centralwidget);
        btnSave->setObjectName("btnSave");

        topRow->addWidget(btnSave);

        btnLoad = new QPushButton(centralwidget);
        btnLoad->setObjectName("btnLoad");

        topRow->addWidget(btnLoad);


        verticalLayout->addLayout(topRow);

        gridButtons = new QGridLayout();
        gridButtons->setObjectName("gridButtons");
        btnSqrt = new QPushButton(centralwidget);
        btnSqrt->setObjectName("btnSqrt");

        gridButtons->addWidget(btnSqrt, 0, 0, 1, 1);

        btnLn = new QPushButton(centralwidget);
        btnLn->setObjectName("btnLn");

        gridButtons->addWidget(btnLn, 0, 1, 1, 1);

        btnAbs = new QPushButton(centralwidget);
        btnAbs->setObjectName("btnAbs");

        gridButtons->addWidget(btnAbs, 0, 2, 1, 1);

        btnInv = new QPushButton(centralwidget);
        btnInv->setObjectName("btnInv");

        gridButtons->addWidget(btnInv, 0, 3, 1, 1);

        btnSq = new QPushButton(centralwidget);
        btnSq->setObjectName("btnSq");

        gridButtons->addWidget(btnSq, 0, 4, 1, 1);

        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName("btnClear");

        gridButtons->addWidget(btnClear, 1, 0, 1, 1);

        btnDel = new QPushButton(centralwidget);
        btnDel->setObjectName("btnDel");

        gridButtons->addWidget(btnDel, 1, 1, 1, 1);

        btnLPar = new QPushButton(centralwidget);
        btnLPar->setObjectName("btnLPar");

        gridButtons->addWidget(btnLPar, 1, 2, 1, 1);

        btnRPar = new QPushButton(centralwidget);
        btnRPar->setObjectName("btnRPar");

        gridButtons->addWidget(btnRPar, 1, 3, 1, 1);

        btnPow = new QPushButton(centralwidget);
        btnPow->setObjectName("btnPow");

        gridButtons->addWidget(btnPow, 1, 4, 1, 1);

        btn7 = new QPushButton(centralwidget);
        btn7->setObjectName("btn7");

        gridButtons->addWidget(btn7, 2, 0, 1, 1);

        btn8 = new QPushButton(centralwidget);
        btn8->setObjectName("btn8");

        gridButtons->addWidget(btn8, 2, 1, 1, 1);

        btn9 = new QPushButton(centralwidget);
        btn9->setObjectName("btn9");

        gridButtons->addWidget(btn9, 2, 2, 1, 1);

        btnDiv = new QPushButton(centralwidget);
        btnDiv->setObjectName("btnDiv");

        gridButtons->addWidget(btnDiv, 2, 3, 1, 1);

        btnNeg = new QPushButton(centralwidget);
        btnNeg->setObjectName("btnNeg");

        gridButtons->addWidget(btnNeg, 2, 4, 1, 1);

        btn4 = new QPushButton(centralwidget);
        btn4->setObjectName("btn4");

        gridButtons->addWidget(btn4, 3, 0, 1, 1);

        btn5 = new QPushButton(centralwidget);
        btn5->setObjectName("btn5");

        gridButtons->addWidget(btn5, 3, 1, 1, 1);

        btn6 = new QPushButton(centralwidget);
        btn6->setObjectName("btn6");

        gridButtons->addWidget(btn6, 3, 2, 1, 1);

        btnMul = new QPushButton(centralwidget);
        btnMul->setObjectName("btnMul");

        gridButtons->addWidget(btnMul, 3, 3, 1, 1);

        btnX = new QPushButton(centralwidget);
        btnX->setObjectName("btnX");

        gridButtons->addWidget(btnX, 3, 4, 1, 1);

        btn1 = new QPushButton(centralwidget);
        btn1->setObjectName("btn1");

        gridButtons->addWidget(btn1, 4, 0, 1, 1);

        btn2 = new QPushButton(centralwidget);
        btn2->setObjectName("btn2");

        gridButtons->addWidget(btn2, 4, 1, 1, 1);

        btn3 = new QPushButton(centralwidget);
        btn3->setObjectName("btn3");

        gridButtons->addWidget(btn3, 4, 2, 1, 1);

        btnMinus = new QPushButton(centralwidget);
        btnMinus->setObjectName("btnMinus");

        gridButtons->addWidget(btnMinus, 4, 3, 1, 1);

        btnPlus = new QPushButton(centralwidget);
        btnPlus->setObjectName("btnPlus");

        gridButtons->addWidget(btnPlus, 4, 4, 1, 1);

        btn0 = new QPushButton(centralwidget);
        btn0->setObjectName("btn0");

        gridButtons->addWidget(btn0, 5, 0, 1, 1);

        btnDot = new QPushButton(centralwidget);
        btnDot->setObjectName("btnDot");

        gridButtons->addWidget(btnDot, 5, 1, 1, 1);

        btnSpace = new QPushButton(centralwidget);
        btnSpace->setObjectName("btnSpace");

        gridButtons->addWidget(btnSpace, 5, 2, 1, 1);

        btnEval = new QPushButton(centralwidget);
        btnEval->setObjectName("btnEval");

        gridButtons->addWidget(btnEval, 5, 3, 1, 2);


        verticalLayout->addLayout(gridButtons);

        lblResult = new QLabel(centralwidget);
        lblResult->setObjectName("lblResult");
        lblResult->setMinimumHeight(28);

        verticalLayout->addWidget(lblResult);

        pteDetails = new QPlainTextEdit(centralwidget);
        pteDetails->setObjectName("pteDetails");
        pteDetails->setReadOnly(true);

        verticalLayout->addWidget(pteDetails);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Calculatrice d'expressions", nullptr));
        leExpr->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ex: inv(sqrt((20+10)^2)) * ln(abs(-5))", nullptr));
        lblX->setText(QCoreApplication::translate("MainWindow", "x =", nullptr));
        btnSave->setText(QCoreApplication::translate("MainWindow", "Sauver (NPI)", nullptr));
        btnLoad->setText(QCoreApplication::translate("MainWindow", "Charger (NPI)", nullptr));
        btnSqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        btnLn->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        btnAbs->setText(QCoreApplication::translate("MainWindow", "abs", nullptr));
        btnInv->setText(QCoreApplication::translate("MainWindow", "inv", nullptr));
        btnSq->setText(QCoreApplication::translate("MainWindow", "sq", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        btnDel->setText(QCoreApplication::translate("MainWindow", "DEL", nullptr));
        btnLPar->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        btnRPar->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        btnPow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        btn7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        btn8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        btn9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        btnDiv->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        btnNeg->setText(QCoreApplication::translate("MainWindow", "neg", nullptr));
        btn4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        btn5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btn6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btnMul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        btnX->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        btn1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        btn2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        btn3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        btnMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btnPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btn0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnDot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        btnSpace->setText(QCoreApplication::translate("MainWindow", "\342\220\240", nullptr));
        btnEval->setText(QCoreApplication::translate("MainWindow", "= Evaluer", nullptr));
        lblResult->setText(QCoreApplication::translate("MainWindow", "R\303\251sultat : -", nullptr));
        pteDetails->setPlaceholderText(QCoreApplication::translate("MainWindow", "D\303\251tails : classique, NPI, valeur\342\200\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
