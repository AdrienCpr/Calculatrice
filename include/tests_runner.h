#ifndef TESTS_RUNNER_H
#define TESTS_RUNNER_H

class TestsRunner {
public:
    // Lance tous les tests et retourne 0 si tout OK, 1 sinon
    static int run_all_tests();

private:
    static bool test_expression();
    static bool test_singleton();
    static bool test_operateurs();

    // Helpers
    static void print_header(const char* title);
    static void print_result(const char* test_name, bool ok);
};

#endif
