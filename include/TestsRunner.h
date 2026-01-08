#ifndef TESTSRUNNER_H
#define TESTSRUNNER_H

class TestsRunner {
public:
    static int run_all_tests();

private:
    static bool test_expression();
    static bool test_singleton();
    static bool test_operateurs();

    static void print_header(const char* title);
    static void print_result(const char* test_name, bool ok);
};

#endif // TESTSRUNNER_H
