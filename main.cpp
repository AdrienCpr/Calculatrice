#include <iostream>
#include <exception>
#include <memory>

using namespace std;

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Multiplication.h"
#include "Expression.h"
#include "ExpressionManager.h"
#include "tests_runner.h"

#include "ConstExpr.h"
#include "BinaryExpr.h"

#include "Puissance.h"
#include "RacineCarre.h"
#include "Inverse.h"
#include "ValeurAbsolue.h"
#include "LogNeperien.h"

int main() {
    try {
        run_all_tests();

        std::unique_ptr<Expression> expr_new =
            std::make_unique<BinaryExpr>(
                OpType::Add,
                std::make_unique<ConstExpr>(10),
                std::make_unique<ConstExpr>(30)
            );

        std::cout << "Expression de depart : " << *expr_new << "\n";

        auto simplified = expr_new->simplify();
        std::cout << "Expression simplifiee : " << *simplified << "\n";
        std::cout << "Valeur : " << simplified->eval() << "\n";

        Constante c1(20.0);
        c1.afficher_classique(cout);
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

        // Enregistrement de l'expression d1 dans le Singleton
        ExpressionManager::Instance().setExpression(&d1);

        cout << "--- Expression via Singleton ---" << endl;

        Expression* e = ExpressionManager::Instance().getExpression();
        e->afficher_classique(cout);
        cout << endl;
        e->afficher_npi(cout);
        cout << endl;

        cout << "\n--- Expression complexe ((20 + 30) * 2) - 5 ---" << endl;

        Constante e1(20.0f), e2(30.0f), e3(2.0f), e4(5.0f);
        Addition add(&e1, &e2);
        Multiplication mul(&add, &e3);
        Soustraction expr(&mul, &e4);

        cout << "Classique: ";
        expr.afficher_classique(cout);
        cout << '\n';

        cout << "NPI: ";
        expr.afficher_npi(cout);
        cout << '\n';

        cout << "Valeur: " << expr.calculer() << '\n';

        // Sauvegarde / Rechargement avec gestion d'erreur locale
        try {
            sauvegarder_npi(expr, "expression.txt");
            cout << "Sauvegarde OK" << endl;

            Expression* expr_chargee = charger_npi_fichier("expression.txt");
            cout << "Chargement OK" << endl;

            cout << "\nAprès chargement depuis le fichier :" << '\n';

            cout << "Classique: ";
            expr_chargee->afficher_classique(cout);
            cout << '\n';

            cout << "NPI: ";
            expr_chargee->afficher_npi(cout);
            cout << '\n';

            cout << "Valeur: " << expr_chargee->calculer() << '\n';

            delete expr_chargee;
        }
        catch (const std::exception& ex) {
            cerr << "ERREUR pendant sauvegarde/chargement : " << ex.what() << endl;
        }

        cout << "\n inv(sqrt((20+10)^2)) * ln(abs(-5)) ---" << endl;

        Constante n1(20.0f);
        Constante n2(10.0f);
        Constante nNeg(-5.0f);
        Constante nPow(2.0f);

        Addition nAdd(&n1, &n2);             // (20 + 10)
        Puissance nP(&nAdd, &nPow);          // (20 + 10) ^ 2
        RacineCarree nR(&nP);                // sqrt( (20+10)^2 )
        Inverse nInv(&nR);                   // inv( sqrt(...) )
        ValeurAbsolue nAbs(&nNeg);           // abs(-5)
        LogNeperien nLn(&nAbs);              // ln(abs(-5))
        Multiplication nExpr(&nInv, &nLn);   // inv(...) * ln(...)

        cout << "Affichage classique : ";
        nExpr.afficher_classique(cout);
        cout << endl;

        cout << "Affichage NPI : ";
        nExpr.afficher_npi(cout);
        cout << endl;

        cout << "Resultat du calcul : " << nExpr.calculer() << endl;

        return 0;
    }
    catch (const std::exception& ex) {
        cerr << "ERREUR globale (exception non gérée) : " << ex.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "ERREUR globale : exception inconnue" << endl;
        return 1;
    }
}
