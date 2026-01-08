#include "TestsRunner.h"

#include <iostream>
#include <sstream>
#include <cmath>      // std::fabs, std::isnan
#include <cstdio>     // std::remove

#include "ExpressionManager.h"

#include "Expression.h"   // sauvegarder_npi / charger_npi_fichier

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "Puissance.h"

#include "Carre.h"
#include "Oppose.h"
#include "RacineCarree.h"
#include "Inverse.h"
#include "ValeurAbsolue.h"
#include "LogNeperien.h"

using namespace std;

static bool float_eq(float a, float b, float eps = 1e-5f) {
    return std::fabs(a - b) <= eps;
}

void TestsRunner::print_header(const char* title) {
    cout << "\n[TEST " << title << "]" << endl;
}

void TestsRunner::print_result(const char* test_name, bool ok) {
    if (ok) cout << "OK  : " << test_name << endl;
    else    cout << "ERR : " << test_name << endl;
}

bool TestsRunner::test_expression() {
    print_header("Expression");

    Expression* expr = new Addition(new Constante(5), new Constante(3));

    ostringstream oss;
    expr->afficher_classique(oss);

    bool ok = (oss.str() == "5 + 3");
    print_result("Affichage classique simple", ok);

    delete expr; // libère tout l'arbre
    return ok;
}

bool TestsRunner::test_singleton() {
    print_header("Singleton (ExpressionManager)");

    Expression* e = new Constante(10);
    ExpressionManager::Instance().setExpression(e);

    bool ok = (ExpressionManager::Instance().getExpression() == e);
    print_result("Singleton stocke correctement l'expression", ok);

    ExpressionManager::Instance().clear();
    return ok;
}

bool TestsRunner::test_operateurs() {
    print_header("Operateurs + unaires + NPI + calcul");

    bool ok = true;

    // ===== Affichage classique binaire =====
    {
        Expression* e = new Addition(new Constante(5), new Constante(3));
        ostringstream oss; e->afficher_classique(oss);
        bool t = (oss.str() == "5 + 3");
        print_result("Addition::afficher_classique", t);
        ok = ok && t;
        delete e;
    }
    {
        Expression* e = new Soustraction(new Constante(5), new Constante(3));
        ostringstream oss; e->afficher_classique(oss);
        bool t = (oss.str() == "5 - 3");
        print_result("Soustraction::afficher_classique", t);
        ok = ok && t;
        delete e;
    }
    {
        Expression* e = new Multiplication(new Constante(5), new Constante(3));
        ostringstream oss; e->afficher_classique(oss);
        bool t = (oss.str() == "5 * 3");
        print_result("Multiplication::afficher_classique", t);
        ok = ok && t;
        delete e;
    }
    {
        Expression* e = new Division(new Constante(5), new Constante(3));
        ostringstream oss; e->afficher_classique(oss);
        bool t = (oss.str() == "5 / 3");
        print_result("Division::afficher_classique", t);
        ok = ok && t;
        delete e;
    }

    // ===== Affichage NPI binaire =====
    {
        Expression* e = new Addition(new Constante(5), new Constante(3));
        ostringstream oss; e->afficher_npi(oss);
        bool t = (oss.str() == "5 3 +");
        print_result("Addition::afficher_npi", t);
        ok = ok && t;
        delete e;
    }
    {
        Expression* e = new Soustraction(new Constante(5), new Constante(3));
        ostringstream oss; e->afficher_npi(oss);
        bool t = (oss.str() == "5 3 -");
        print_result("Soustraction::afficher_npi", t);
        ok = ok && t;
        delete e;
    }
    {
        Expression* e = new Multiplication(new Constante(5), new Constante(3));
        ostringstream oss; e->afficher_npi(oss);
        bool t = (oss.str() == "5 3 *");
        print_result("Multiplication::afficher_npi", t);
        ok = ok && t;
        delete e;
    }
    {
        Expression* e = new Division(new Constante(5), new Constante(3));
        ostringstream oss; e->afficher_npi(oss);
        bool t = (oss.str() == "5 3 /");
        print_result("Division::afficher_npi", t);
        ok = ok && t;
        delete e;
    }

    // ===== Expression composée : (5 + 3) * 2 =====
    {
        Expression* expr = new Multiplication(
            new Addition(new Constante(5), new Constante(3)),
            new Constante(2)
            );

        ostringstream oss_classique, oss_npi;
        expr->afficher_classique(oss_classique);
        expr->afficher_npi(oss_npi);

        bool t1 = (oss_classique.str() == "5 + 3 * 2");
        bool t2 = (oss_npi.str() == "5 3 + 2 *");

        print_result("Expression composee afficher_classique", t1);
        print_result("Expression composee afficher_npi", t2);

        ok = ok && t1 && t2;
        delete expr;
    }

    // ===== Calculs =====
    {
        Expression* add = new Addition(new Constante(5), new Constante(3));
        Expression* sub = new Soustraction(new Constante(5), new Constante(3));
        Expression* mul = new Multiplication(new Constante(5), new Constante(3));
        Expression* div = new Division(new Constante(5), new Constante(2));

        bool t1 = (add->calculer() == 8.0f);
        bool t2 = (sub->calculer() == 2.0f);
        bool t3 = (mul->calculer() == 15.0f);
        bool t4 = float_eq(div->calculer(), 2.5f);

        print_result("Addition::calculer", t1);
        print_result("Soustraction::calculer", t2);
        print_result("Multiplication::calculer", t3);
        print_result("Division::calculer", t4);

        ok = ok && t1 && t2 && t3 && t4;

        delete add;
        delete sub;
        delete mul;
        delete div;
    }

    // Division par zéro
    {
        Expression* div0 = new Division(new Constante(5), new Constante(0));
        float res = div0->calculer();
        bool t = (res == 0.0f);
        print_result("Division par zero renvoie 0", t);
        ok = ok && t;
        delete div0;
    }

    // ===== Puissance =====
    {
        Expression* p = new Puissance(new Constante(2), new Constante(3));
        bool t1 = float_eq(p->calculer(), 8.0f);
        ostringstream oss; p->afficher_npi(oss);
        bool t2 = (oss.str() == "2 3 ^");
        print_result("Puissance::calculer(2^3)", t1);
        print_result("Puissance::afficher_npi", t2);
        ok = ok && t1 && t2;
        delete p;
    }

    // ===== Unaires =====
    {
        Expression* e = new Carre(new Constante(4));
        bool t = float_eq(e->calculer(), 16.0f);
        print_result("Carre::calculer", t);
        ok = ok && t;
        delete e;
    }
    {
        Expression* e = new Oppose(new Constante(5));
        bool t = float_eq(e->calculer(), -5.0f);
        print_result("Oppose::calculer", t);
        ok = ok && t;
        delete e;
    }
    {
        Expression* e = new RacineCarree(new Constante(9));
        bool t = float_eq(e->calculer(), 3.0f);
        print_result("RacineCarree::calculer(sqrt(9))", t);
        ok = ok && t;
        delete e;
    }
    {
        Expression* e = new RacineCarree(new Constante(-1));
        bool t = std::isnan(e->calculer());
        print_result("RacineCarree::calculer(sqrt(-1)) => NaN", t);
        ok = ok && t;
        delete e;
    }
    {
        Expression* e = new Inverse(new Constante(4));
        bool t = float_eq(e->calculer(), 0.25f);
        print_result("Inverse::calculer(inv(4))", t);
        ok = ok && t;
        delete e;
    }
    {
        Expression* e = new Inverse(new Constante(0));
        bool t = std::isnan(e->calculer());
        print_result("Inverse::calculer(inv(0)) => NaN", t);
        ok = ok && t;
        delete e;
    }
    {
        Expression* e = new ValeurAbsolue(new Constante(-5));
        bool t = float_eq(e->calculer(), 5.0f);
        print_result("ValeurAbsolue::calculer(abs(-5))", t);
        ok = ok && t;
        delete e;
    }
    {
        Expression* e = new LogNeperien(new Constante(1));
        bool t = float_eq(e->calculer(), 0.0f);
        print_result("LogNeperien::calculer(ln(1))", t);
        ok = ok && t;
        delete e;
    }
    {
        Expression* e = new LogNeperien(new Constante(0));
        bool t = std::isnan(e->calculer());
        print_result("LogNeperien::calculer(ln(0)) => NaN", t);
        ok = ok && t;
        delete e;
    }

    // ===== Sauvegarde / Chargement NPI (feature ancien code) =====
    {
        const char* fname = "test_expr_npi.txt";

        Expression* expr = new Soustraction(
            new Multiplication(
                new Addition(new Constante(20), new Constante(30)),
                new Constante(2)
                ),
            new Constante(5)
            ); // valeur attendue = 95

        bool t_save = true;
        try {
            sauvegarder_npi(*expr, fname);
        } catch (...) {
            t_save = false;
        }
        print_result("Sauvegarder NPI", t_save);
        ok = ok && t_save;

        bool t_load = true;
        if (t_save) {
            try {
                Expression* loaded = charger_npi_fichier(fname);
                t_load = float_eq(loaded->calculer(), 95.0f);
                delete loaded;
            } catch (...) {
                t_load = false;
            }
        }
        print_result("Charger NPI + calcul", t_load);
        ok = ok && t_load;

        delete expr;
        std::remove(fname);
    }

    if (ok) cout << "==> Tous les tests sont OK." << endl;
    else    cout << "==> Il y a des erreurs dans les tests." << endl;

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
