#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    if (!btc.init("data.csv")) {
        return 1;
    }
    
    {
        // map_data data = btc.get();
        // for (map_data::iterator it = data.begin(); it != data.end(); it++)
        //     std::cout << it->first << "," << it->second << std::endl;   
    }

    btc.processInputFile(av[1]);
    return 0;
}