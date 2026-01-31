#include "RPN.hpp"
#include <iostream>
#include <sstream>

// int main(int ac, char **av) {
//     if (ac != 2) {
//         std::cerr << "Error" << std::endl;
//         return 1;
//     }

//     RPN rpn;

//     rpn.setFormatStr(av[1]);
//     rpn.eval();

//     return 0;
// }

int main(int ac, char **av) {
    if (ac == 2) {
        RPN rpn;
        rpn.setFormatStr(av[1]);
        rpn.eval();
        return 0;
    }

    struct Test {
        const char* input;
        int expected;
    };

    Test tests[] = {
        {"3 4 +", 7},
        {"9 2 -", 7},
        {"3 5 *", 15},
        {"8 2 /", 4},
        {"3 4 + 2 *", 14},
        {"5 1 2 + 4 * + 3 -", 14},
        {"2 3 + 4 5 + *", 45},
        {"9 3 / 2 +", 5},
        {"7 2 - 3 *", 15},
        {"8 4 / 2 /", 1},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;

    for (int i = 0; i < num_tests; i++) {
        RPN rpn;
        rpn.setFormatStr(tests[i].input);

        std::streambuf* old = std::cout.rdbuf();
        std::ostringstream stream;
        std::cout.rdbuf(stream.rdbuf());

        rpn.eval();

        std::cout.rdbuf(old);

        int result = std::stoi(stream.str());

        if (result == tests[i].expected) {
            std::cout << "PASS: \"" << tests[i].input << "\" = " << result << std::endl;
            passed++;
        } else {
            std::cout << "FAIL: \"" << tests[i].input << "\" expected " << tests[i].expected << " but got " << result << std::endl;
        }
    }

    std::cout << passed << "/" << num_tests << " tests passed" << std::endl;

    return passed != num_tests ? 1 : 0;
}