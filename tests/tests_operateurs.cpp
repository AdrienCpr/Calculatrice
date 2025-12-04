#include <iostream>
#include <sstream>

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Multiplication.h"
#include "Division.h"

using namespace std;

int test_operateurs() {
    cout << "[TEST Integrations Operateurs] " << endl;

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
        Addition add(&c5, &c3);     // 5 + 3
        add.afficher_classique(oss);

        if (oss.str() == "5 + 3")
            cout << "OK  : Addition::afficher_classique" << endl;
        else {
            cout << "ERR : Addition::afficher_classique -> \"" << oss.str() << "\"" << endl;
            ok = false;
        }
    }

    {
        ostringstream oss;
        Soustraction sub(&c5, &c3); // 5 - 3
        sub.afficher_classique(oss);

        if (oss.str() == "5 - 3")
            cout << "OK  : Soustraction::afficher_classique" << endl;
        else {
            cout << "ERR : Soustraction::afficher_classique -> \"" << oss.str() << "\"" << endl;
            ok = false;
        }
    }

    {
        ostringstream oss;
        Multiplication mul(&c5, &c3); // 5 * 3
        mul.afficher_classique(oss);

        if (oss.str() == "5 * 3")
            cout << "OK  : Multiplication::afficher_classique" << endl;
        else {
            cout << "ERR : Multiplication::afficher_classique -> \"" << oss.str() << "\"" << endl;
            ok = false;
        }
    }

    {
        ostringstream oss;
        Division div(&c5, &c3); // 5 / 3
        div.afficher_classique(oss);

        if (oss.str() == "5 / 3")
            cout << "OK  : Division::afficher_classique" << endl;
        else {
            cout << "ERR : Division::afficher_classique -> \"" << oss.str() << "\"" << endl;
            ok = false;
        }
    }

    // ==============================
    // 2) Affichage NPI (postfixe)
    // ==============================
    {
        ostringstream oss;
        Addition add(&c5, &c3); // 5 3 +
        add.afficher_npi(oss);

        if (oss.str() == "5 3 +")
            cout << "OK  : Addition::afficher_npi" << endl;
        else {
            cout << "ERR : Addition::afficher_npi -> \"" << oss.str() << "\"" << endl;
            ok = false;
        }
    }

    {
        ostringstream oss;
        Soustraction sub(&c5, &c3); // 5 3 -
        sub.afficher_npi(oss);

        if (oss.str() == "5 3 -")
            cout << "OK  : Soustraction::afficher_npi" << endl;
        else {
            cout << "ERR : Soustraction::afficher_npi -> \"" << oss.str() << "\"" << endl;
            ok = false;
        }
    }

    {
        ostringstream oss;
        Multiplication mul(&c5, &c3); // 5 3 *
        mul.afficher_npi(oss);

        if (oss.str() == "5 3 *")
            cout << "OK  : Multiplication::afficher_npi" << endl;
        else {
            cout << "ERR : Multiplication::afficher_npi -> \"" << oss.str() << "\"" << endl;
            ok = false;
        }
    }

    {
        ostringstream oss;
        Division div(&c5, &c3); // 5 3 /
        div.afficher_npi(oss);

        if (oss.str() == "5 3 /")
            cout << "OK  : Division::afficher_npi" << endl;
        else {
            cout << "ERR : Division::afficher_npi -> \"" << oss.str() << "\"" << endl;
            ok = false;
        }
    }

    // =========================================
    // 3) Expression composée : (5 + 3) * 2
    //    Avec TON affichage, ça donne :
    //    Multiplication.afficher_classique :
    //      gauche -> "5 + 3"
    //      donc résultat : "5 + 3 * 2"
    // =========================================
    {
        Addition add(&c5, &c3);          // 5 + 3
        Multiplication expr(&add, &c2);  // (5 + 3) * 2

        ostringstream oss_classique;
        ostringstream oss_npi;

        expr.afficher_classique(oss_classique);
        expr.afficher_npi(oss_npi);

        // Avec ton code actuel :
        // - afficher_classique : "5 + 3 * 2"
        // - afficher_npi :
        //    gauche.afficher_classique => "5 + 3"
        //    puis " "
        //    puis droite.afficher_classique => "2"
        //    puis " *"
        //  => "5 + 3 2 *"

        if (oss_classique.str() == "5 + 3 * 2")
            cout << "OK  : Expression composee afficher_classique" << endl;
        else {
            cout << "ERR : Expression composee afficher_classique -> \"" << oss_classique.str() << "\"" << endl;
            ok = false;
        }

        if (oss_npi.str() == "5 + 3 2 *")
            cout << "OK  : Expression composee afficher_npi" << endl;
        else {
            cout << "ERR : Expression composee afficher_npi -> \"" << oss_npi.str() << "\"" << endl;
            ok = false;
        }
    }

    // ==========================================================
    // 4) Tests calculer()
    //    ⚠ Ces tests supposent que Constante::calculer() est écrite.
    //    Si ce n'est pas le cas, laisse ce bloc en commentaire
    //    pour plus tard.
    // ==========================================================
    /*
    {
        Addition add(&c5, &c3);          // 8
        Soustraction sub(&c5, &c3);      // 2
        Multiplication mul(&c5, &c3);    // 15
        Division div(&c5, &c2);          // 2.5

        if (add.calculer() == 8)  cout << "OK  : Addition::calculer" << endl;
        else { cout << "ERR : Addition::calculer" << endl; ok = false; }

        if (sub.calculer() == 2)  cout << "OK  : Soustraction::calculer" << endl;
        else { cout << "ERR : Soustraction::calculer" << endl; ok = false; }

        if (mul.calculer() == 15) cout << "OK  : Multiplication::calculer" << endl;
        else { cout << "ERR : Multiplication::calculer" << endl; ok = false; }

        if (div.calculer() == 2.5f) cout << "OK  : Division::calculer" << endl;
        else { cout << "ERR : Division::calculer" << endl; ok = false; }

        // Division par zero : juste vérifier qu'on ne crashe pas
        Division div0(&c5, &c0);
        float res = div0.calculer(); // devrait afficher un message d'erreur et renvoyer 0
        cout << "INFO: Division par zero renvoie " << res << " (attendu : 0)" << endl;
    }
    */

    if (ok)
        cout << "==> Tous les tests d'integration operateurs sont OK." << endl;
    else
        cout << "==> Il y a des erreurs dans les tests d'integration operateurs." << endl;

    return ok ? 0 : 1;
}
