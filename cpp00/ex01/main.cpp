#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook myPhoneBook;

    myPhoneBook.displayWelcome();

    while (myPhoneBook.getRunning())
    {
        myPhoneBook.displayMenu();
        myPhoneBook.setCommand();

        if (myPhoneBook.getCommand() == "EXIT")
        {
            myPhoneBook.displayGoodbye();
            myPhoneBook.setRunning(false);
        }
        else if (myPhoneBook.getCommand() == "ADD") {
            myPhoneBook.inputContact();
        }
        else if (myPhoneBook.getCommand() == "SEARCH") {
            myPhoneBook.searchContact();
        } else {
            std::cout << "\n  " << RED << "✗ " << RESET << "Unknown command '" 
                    << myPhoneBook.getCommand() << "'. Please use ADD, SEARCH, or EXIT.\n";
            std::cout << CYAN << "  ─────────────────────────────────────────\n" << RESET;
        }
    }
} 