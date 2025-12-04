#include <iostream>

using namespace std;

int test_expression();
int test_singleton();
int test_operateurs();

int run_all_tests() {
    cout << "=== Lancement de tous les tests ===" << endl;

    test_expression();
    test_singleton();
    test_operateurs();

    cout << "=== Fin des tests ===" << endl;

    return 0;
}
