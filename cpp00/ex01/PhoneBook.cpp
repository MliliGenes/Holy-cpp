#include "PhoneBook.hpp"

void PhoneBook::displayWelcome() const
{
    std::cout << "\n";
    std::cout << CYAN << "  ╭─────────────────────────────────────────╮\n" << RESET;
    std::cout << CYAN << "  │" << BOLD << MAGENTA << "                                         " << RESET << CYAN << "│\n" << RESET;
    std::cout << CYAN << "  │" << BOLD << MAGENTA << "    🚀  Welcome to PhoneBook CLI  📞     " << RESET << CYAN << "│\n" << RESET;
    std::cout << CYAN << "  │" << BOLD << MAGENTA << "                                         " << RESET << CYAN << "│\n" << RESET;
    std::cout << CYAN << "  ╰─────────────────────────────────────────╯\n" << RESET;
    std::cout << GREEN << "    » Your personal contact management system\n" << RESET;
    std::cout << "\n";
}

void PhoneBook::displayGoodbye() const 
{
    std::cout << "\n";
    std::cout << YELLOW << "  ╭─────────────────────────────────────────╮\n" << RESET;
    std::cout << YELLOW << "  │" << BOLD << GREEN << "                                         " << RESET << YELLOW << "│\n" << RESET;
    std::cout << YELLOW << "  │" << BOLD << GREEN << "    👋  Thanks for using PhoneBook!      " << RESET << YELLOW << "│\n" << RESET;
    std::cout << YELLOW << "  │" << BOLD << GREEN << "           See you again soon! 😊        " << RESET << YELLOW << "│\n" << RESET;
    std::cout << YELLOW << "  │" << BOLD << GREEN << "                                         " << RESET << YELLOW << "│\n" << RESET;
    std::cout << YELLOW << "  ╰─────────────────────────────────────────╯\n" << RESET;
    std::cout << "\n";
}

void PhoneBook::displayMenu() const
{
    std::cout << "\n";
    std::cout << BLUE << "  ╭─────────────────────────────────────────╮\n" << RESET;
    std::cout << BLUE << "  │" << BOLD << WHITE << "               MAIN MENU                 " << RESET << BLUE << "│\n" << RESET;
    std::cout << BLUE << "  ╰─────────────────────────────────────────╯\n" << RESET;
    std::cout << "\n";
    
    std::cout << "    " << BOLD << GREEN << "▶ ADD" << RESET << "      Add a new contact to phonebook\n";
    std::cout << "    " << BOLD << YELLOW << "▶ SEARCH" << RESET << "   Find and display contact details\n";
    std::cout << "    " << BOLD << RED << "▶ EXIT" << RESET << "     Close application and save data\n";
    std::cout << "\n";
    
    std::cout << CYAN << "  ──────────────────────────────────────────\n" << RESET;
}

PhoneBook::PhoneBook()
{
    _contactCount = 0;
    _nextIndex = 0;
    _running = true;
}

PhoneBook::~PhoneBook()
{
    // big meow
}

PhoneBook::PhoneBook(const PhoneBook &other)
{
    _contactCount = other._contactCount;
    _nextIndex = other._nextIndex;

    for (int i = 0; i < 8; i++)
        _contacts[i] = other._contacts[i];
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
    if (this == &other)
        return *this;

    _contactCount = other._contactCount;
    _nextIndex = other._nextIndex;

    for (int i = 0; i < 8; i++)
        _contacts[i] = other._contacts[i];

    return *this;
}

void PhoneBook::pushContact(const Contact &contact)
{
    int index = _nextIndex % 8;
    _contacts[index] = contact;

    _nextIndex++;

    if (_contactCount < 8)
        _contactCount++;
}

void PhoneBook::setCommand()
{
    std::string command;

    std::cout << "  " << CYAN << "→ " << RESET << "Enter command " 
            << DIM << "(ADD/SEARCH/EXIT)" << RESET << ": ";
    
    if (!std::getline(std::cin, command)) {
        displayGoodbye();
        exit(1);
    }

    command.erase(0, command.find_first_not_of(" \t\n\r\f\v"));
    command.erase(command.find_last_not_of(" \t\n\r\f\v") + 1);

    _command = command;
}

std::string PhoneBook::getCommand(void) const
{
    return _command;
}

void PhoneBook::setRunning(bool state)
{
    _running = state;
}

bool PhoneBook::getRunning(void) const
{
    return _running;
}

std::string PhoneBook::getValidInput(const std::string& fieldName) 
{
    std::string input;
    
    while (true) 
    {
        std::cout << "    " << CYAN << "→ " << RESET << fieldName << ": ";

        if (!std::getline(std::cin, input)) 
        {
            std::cout << "\n  " << YELLOW << "⚠ " << RESET << "EOF detected. Canceling input...\n";
            return "";
        }

        input.erase(0, input.find_first_not_of(" \t"));
        input.erase(input.find_last_not_of(" \t") + 1);

        if (!input.empty())
            return input;

        std::cout << "  " << RED << "✗ " << RESET << "Field cannot be empty. Please try again.\n";
        std::cout << "\n";
    }
}

void PhoneBook::inputContact(void) 
{
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
    
    std::cout << "\n";
    std::cout << BLUE << "  ╭─────────────────────────────────────────╮\n" << RESET;
    std::cout << BLUE << "  │" << BOLD << WHITE << "             ADD NEW CONTACT             " << RESET << BLUE << "│\n" << RESET;
    std::cout << BLUE << "  ╰─────────────────────────────────────────╯\n" << RESET;
    std::cout << "\n";
    
    std::cout << "    " << DIM << "Please fill in all contact details:\n" << RESET;
    std::cout << "\n";
    
    firstName = getValidInput("First Name");
    lastName = getValidInput("Last Name");
    nickname = getValidInput("Nickname");
    phoneNumber = getValidInput("Phone Number");
    darkestSecret = getValidInput("Darkest Secret");

    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
    {
        std::cout << "\n  " << RED << "✗ " << RESET << "Contact creation cancelled. Some fields were left empty.\n";
        std::cout << CYAN << "  ─────────────────────────────────────────\n" << RESET;
        return;
    }

    Contact tmp;
    tmp.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    pushContact(tmp);

    std::cout << "\n";
    std::cout << "  " << GREEN << "✓ " << RESET << "Contact information saved successfully!\n";
    std::cout << CYAN << "  ─────────────────────────────────────────\n" << RESET;
}

std::string PhoneBook::formatColumn(const std::string& text) const {
    if (text.length() > 10) {
        return text.substr(0, 9) + ".";
    }
    
    std::string result = text;
    while (result.length() < 10) {
        result = " " + result;
    }
    return result;
}

void PhoneBook::searchContact(void) const {
    if (_contactCount == 0) {
        std::cout << "\n";
        std::cout << BLUE << "  ╭─────────────────────────────────────────╮\n" << RESET;
        std::cout << BLUE << "  │" << BOLD << WHITE << "            SEARCH CONTACTS              " << RESET << BLUE << "│\n" << RESET;
        std::cout << BLUE << "  ╰─────────────────────────────────────────╯\n" << RESET;
        std::cout << "\n";
        std::cout << "  " << YELLOW << "⚠ " << RESET << "No contacts available in phonebook.\n";
        std::cout << CYAN << "  ─────────────────────────────────────────\n" << RESET;
        return;
    }

    std::cout << "\n";
    std::cout << BLUE << "  ╭─────────────────────────────────────────╮\n" << RESET;
    std::cout << BLUE << "  │" << BOLD << WHITE << "            SEARCH CONTACTS              " << RESET << BLUE << "│\n" << RESET;
    std::cout << BLUE << "  ╰─────────────────────────────────────────╯\n" << RESET;
    std::cout << "\n";

    std::cout << "  " << BOLD << CYAN;
    std::cout << formatColumn("Index") << "│" 
              << formatColumn("First Name") << "│"
              << formatColumn("Last Name") << "│" 
              << formatColumn("Nickname") << RESET << "\n";
    
    std::cout << "   " << CYAN << "──────────────────────────────────────────" << RESET << "\n";

    for (int i = 0; i < _contactCount; i++) {
        std::stringstream ss;
        ss << i;
        std::cout << "  ";
        std::cout << formatColumn(ss.str()) << "│"
                  << formatColumn(_contacts[i].getFirstName()) << "│"
                  << formatColumn(_contacts[i].getLastName()) << "│"
                  << formatColumn(_contacts[i].getNickname()) << "\n";
    }

    std::cout << "   " << CYAN << "──────────────────────────────────────────" << RESET << "\n";
    std::cout << "\n";

    std::string input;
    std::cout << "    " << CYAN << "→ " << RESET << "Enter contact index: ";
    
    if (!std::getline(std::cin, input)) {
        std::cout << "\n  " << YELLOW << "⚠ " << RESET << "Input cancelled.\n";
        return;
    }

    input.erase(0, input.find_first_not_of(" \t"));
    input.erase(input.find_last_not_of(" \t") + 1);

    if (input.empty()) {
        std::cout << "  " << RED << "✗ " << RESET << "No index entered.\n";
        std::cout << CYAN << "  ─────────────────────────────────────────\n" << RESET;
        return;
    }

    for (std::string::iterator c = input.begin() ; c != input.end() ; c++) {
        if (!std::isdigit(*c)) {
            std::cout << "  " << RED << "✗ " << RESET << "Invalid index. Please enter a number.\n";
            std::cout << CYAN << "  ─────────────────────────────────────────\n" << RESET;
            return;
        }
    }

    std::stringstream ss(input);
    int index;
    ss >> index;
    
    if (index >= 0 && index < _contactCount) {
        std::cout << "\n";
        std::cout << GREEN << "  ╭─────────────────────────────────────────╮\n" << RESET;
        std::cout << GREEN << "  │" << BOLD << WHITE << "            CONTACT DETAILS              " << RESET << GREEN << "│\n" << RESET;
        std::cout << GREEN << "  ╰─────────────────────────────────────────╯\n" << RESET;
        std::cout << "\n";
        _contacts[index].displagety();
        std::cout << CYAN << "  ─────────────────────────────────────────\n" << RESET;
    } else {
        std::cout << "  " << RED << "✗ " << RESET << "Invalid index. Please enter a number between 0 and " 
                << (_contactCount - 1) << ".\n";
        std::cout << CYAN << "  ─────────────────────────────────────────\n" << RESET;
    }
}
