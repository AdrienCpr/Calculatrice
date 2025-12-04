#include <iostream>
#include "Constante.h"
#include "Addition.h"

using namespace std;

int test_expression() {
    cout << "[TEST Expression] " << endl;

    Constante c1(5), c2(3);
    Addition add(&c1, &c2);

    cout << "Classique : ";
    add.afficher_classique(cout);
    cout << endl;

    return 0;
}
