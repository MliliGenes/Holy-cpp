#include "PmergeMe.hpp"

int main(int ac, char** av) {

    PmergeMe pm;

    if (!pm.initialize(ac, av))
        return 1;
    
    pm.sort();
}