#include <iostream>

#define LOUD_NOISE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

std::string toUpperCase(const std::string& str) {
    std::string upperCase = str;
    for (std::string::iterator it = upperCase.begin(); it != upperCase.end(); it++)
        *it = std::toupper(*it);
    return (upperCase);
}

int main(int ac, char **av) {

    if (ac == 1)
        std::cout << LOUD_NOISE << std::endl;
    else {
        for (int i = 1; i < ac; i++)
            std::cout << toUpperCase(av[i]);
        std::cout << std::endl;
    }
    return 0;
}