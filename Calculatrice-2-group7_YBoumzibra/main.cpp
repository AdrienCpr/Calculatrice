#include <iostream>

using namespace std;

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Multiplication.h"
#include <memory>
#include "ConstExpr.h"
#include "BinaryExpr.h"
#include "VarExpr.h"

int main(void) {

    std::unique_ptr<Expression> expr =
    std::make_unique<BinaryExpr>(
        OpType::Add,
        std::make_unique<ConstExpr>(10),
        std::make_unique<ConstExpr>(30)
    );

    std::cout << "Expression de depart v1 : " << *expr << "\n";

    auto simplified = expr->simplify();
    std::cout << "Expression simplifiee v1 : " << *simplified << "\n";

    std::cout << "Valeur finale : " << simplified->eval() << "\n";
    // --- Tests pour l'itération 2 ---
    using std::make_unique;
    // (10 + 20) + (30 + x) --> 60 + x
    std::unique_ptr<Expression> test1 = make_unique<BinaryExpr>(
        OpType::Add,
        make_unique<BinaryExpr>(OpType::Add, make_unique<ConstExpr>(10), make_unique<ConstExpr>(20)),
        make_unique<BinaryExpr>(OpType::Add, make_unique<ConstExpr>(30), make_unique<VarExpr>("x"))
    );
    std::cout << "\n1ere Expression v2 : " << *test1 << "\n";
    auto simp_test1 = test1->simplify();
    std::cout << "1ere Expression simplifiee v2 :  " << *simp_test1 << "\n";

    // ((3+4) * 2 + a) / b  -> (a + 14) / b
    std::unique_ptr<Expression> test2 = make_unique<BinaryExpr>(
        OpType::Div,
        make_unique<BinaryExpr>(
            OpType::Add,
            make_unique<BinaryExpr>(OpType::Mul, make_unique<BinaryExpr>(OpType::Add, make_unique<ConstExpr>(3), make_unique<ConstExpr>(4)), make_unique<ConstExpr>(2)),
            make_unique<VarExpr>("a")
        ),
        make_unique<VarExpr>("b")
    );
    std::cout << "\n2eme Expression v2 : " << *test2 << "\n";
    auto simp_test2 = test2->simplify();
    std::cout << "2eme Expression simplifiee v2 :" << *simp_test2 << "\n\n";

    Constante c1(20.0);

    c1.afficher_classique();
    cout << endl;

    Constante c2(30.0);
    Addition add1(&c1, &c2);

    add1.afficher_classique(cout);
    cout << endl;

    add1.afficher_npi(cout);
    cout << endl;

    Constante c3(34.0);
    Multiplication m1(&c3, &add1);

    m1.afficher_classique(cout);
    cout << endl;

    m1.afficher_npi(cout);
    cout << endl;

    Constante c4(50.0);
    Constante c5(10.0);
    Soustraction s1(&c4, &c5);

    s1.afficher_classique(cout);
    cout << endl;

    s1.afficher_npi(cout);
    cout << endl;

    Division d1(&m1, &c5);

    d1.afficher_classique(cout);
    cout << endl;

    d1.afficher_npi(cout);
    cout << endl;

    return 0;
}

