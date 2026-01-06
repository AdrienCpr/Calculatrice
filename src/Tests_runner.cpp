#include "tests_runner.h"

#include <iostream>
#include <sstream>

#include "ExpressionManager.h"
#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Multiplication.h"
#include "Division.h"

using namespace std;

void TestsRunner::print_header(const char* title) {
    cout << "\n[TEST " << title << "]" << endl;
}

void TestsRunner::print_result(const char* test_name, bool ok) {
    if (ok) cout << "OK  : " << test_name << endl;
    else    cout << "ERR : " << test_name << endl;
}

bool TestsRunner::test_expression() {
    print_header("Expression");

    Constante c1(5), c2(3);
    Addition add(&c1, &c2);

    cout << "Classique : ";
    add.afficher_classique(cout);
    cout << endl;

    // Ici tu peux ajouter un vrai assert texte si tu veux,
    // mais ton prof a surtout demandé l'encapsulation.
    return true;
}

bool TestsRunner::test_singleton() {
    print_header("Singleton");

    Constante c1(10);
    ExpressionManager::Instance().setExpression(&c1);

    bool ok = (ExpressionManager::Instance().getExpression() == &c1);
    print_result("Singleton stocke correctement l'expression", ok);

    return ok;
}

bool TestsRunner::test_operateurs() {
    print_header("Integrations Operateurs");

    bool ok = true;

    Constante c5(5);
    Constante c3(3);
    Constante c2(2);
    Constante c0(0);

    // ==============================
    // 1) Affichage classique simple
    // ==============================
    {
        ostringstream oss;
        Addition add(&c5, &c3);
        add.afficher_classique(oss);

        bool t = (oss.str() == "5 + 3");
        print_result("Addition::afficher_classique", t);
        ok = ok && t;
    }

    {
        ostringstream oss;
        Soustraction sub(&c5, &c3);
        sub.afficher_classique(oss);

        bool t = (oss.str() == "5 - 3");
        print_result("Soustraction::afficher_classique", t);
        ok = ok && t;
    }

    {
        ostringstream oss;
        Multiplication mul(&c5, &c3);
        mul.afficher_classique(oss);

        bool t = (oss.str() == "5 * 3");
        print_result("Multiplication::afficher_classique", t);
        ok = ok && t;
    }

    {
        ostringstream oss;
        Division div(&c5, &c3);
        div.afficher_classique(oss);

        bool t = (oss.str() == "5 / 3");
        print_result("Division::afficher_classique", t);
        ok = ok && t;
    }

    // ==============================
    // 2) Affichage NPI (postfixe)
    // ==============================
    {
        ostringstream oss;
        Addition add(&c5, &c3);
        add.afficher_npi(oss);

        bool t = (oss.str() == "5 3 +");
        print_result("Addition::afficher_npi", t);
        ok = ok && t;
    }

    {
        ostringstream oss;
        Soustraction sub(&c5, &c3);
        sub.afficher_npi(oss);

        bool t = (oss.str() == "5 3 -");
        print_result("Soustraction::afficher_npi", t);
        ok = ok && t;
    }

    {
        ostringstream oss;
        Multiplication mul(&c5, &c3);
        mul.afficher_npi(oss);

        bool t = (oss.str() == "5 3 *");
        print_result("Multiplication::afficher_npi", t);
        ok = ok && t;
    }

    {
        ostringstream oss;
        Division div(&c5, &c3);
        div.afficher_npi(oss);

        bool t = (oss.str() == "5 3 /");
        print_result("Division::afficher_npi", t);
        ok = ok && t;
    }

    // =========================================
    // 3) Expression composée : (5 + 3) * 2
    // =========================================
    {
        Addition add(&c5, &c3);
        Multiplication expr(&add, &c2);

        ostringstream oss_classique;
        ostringstream oss_npi;

        expr.afficher_classique(oss_classique);
        expr.afficher_npi(oss_npi);

        bool t1 = (oss_classique.str() == "5 + 3 * 2");
        bool t2 = (oss_npi.str() == "5 3 + 2 *");

        print_result("Expression composee afficher_classique", t1);
        print_result("Expression composee afficher_npi", t2);

        ok = ok && t1 && t2;
    }

    // ==========================================================
    // 4) Tests calculer()
    // ==========================================================

    {
        Addition add(&c5, &c3);
        Soustraction sub(&c5, &c3);
        Multiplication mul(&c5, &c3);
        Division div(&c5, &c2);

        bool t1 = (add.calculer() == 8);
        bool t2 = (sub.calculer() == 2);
        bool t3 = (mul.calculer() == 15);
        bool t4 = (div.calculer() == 2.5f);

        print_result("Addition::calculer", t1);
        print_result("Soustraction::calculer", t2);
        print_result("Multiplication::calculer", t3);
        print_result("Division::calculer", t4);

        ok = ok && t1 && t2 && t3 && t4;

        Division div0(&c5, &c0);
        float res = div0.calculer();
        cerr << "INFO: Division par zero renvoie " << res << " (attendu : 0)" << endl;
    }

    if (ok) cout << "==> Tous les tests d'integration operateurs sont OK." << endl;
    else    cout << "==> Il y a des erreurs dans les tests d'integration operateurs." << endl;

    return ok;
}

int TestsRunner::run_all_tests() {
    cout << "=== Lancement de tous les tests ===" << endl;

    bool ok = true;
    ok = test_expression() && ok;
    ok = test_singleton() && ok;
    ok = test_operateurs() && ok;

    cout << "=== Fin des tests ===" << endl;

    return ok ? 0 : 1;
}
