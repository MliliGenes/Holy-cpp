#include "Harl.hpp"

enum Level { DEBUG_L, INFO_L, WARNING_L, ERROR_L, UNKNOWN_L };

static Level getLevelIndex(const std::string &level) {
    if (level == "DEBUG")   return DEBUG_L;
    if (level == "INFO")    return INFO_L;
    if (level == "WARNING") return WARNING_L;
    if (level == "ERROR")   return ERROR_L;
    return UNKNOWN_L;
}

void Harl::complain(std::string level) {
    void (Harl::*funcs[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    switch (getLevelIndex(level)) {
        case DEBUG_L:
            std::cout << "[ " << levels[0] << " ]\n";
            (this->*funcs[0])();
            // [[fallthrough]];
        case INFO_L:
            std::cout << "[ " << levels[1] << " ]\n";
            (this->*funcs[1])();
            // [[fallthrough]];
        case WARNING_L:
            std::cout << "[ " << levels[2] << " ]\n";
            (this->*funcs[2])();
            // [[fallthrough]];
        case ERROR_L:
            std::cout << "[ " << levels[3] << " ]\n";
            (this->*funcs[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            break;
    }
}

void Harl::debug() {

    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;

}

void Harl::info() {
   
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;

}

void Harl::warning() {
   
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;

}

void Harl::error() {
    
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;

}
