#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define DIM     "\033[2m"
#define WHITE   "\033[37m"

#include "Contact.hpp"

class PhoneBook {
    private:
        std::string _command;
        bool _running;
        int _contactCount;
        int _nextIndex;
        Contact _contacts[8];   
    
    public:
        PhoneBook();
        PhoneBook(const PhoneBook &other);
        PhoneBook &operator=(const PhoneBook &other);
        ~PhoneBook();

        std::string getValidInput(const std::string& prompt);

        void pushContact(const Contact &contact);
        void inputContact(void);
        void searchContact(void) const;
        std::string formatColumn(const std::string& text) const;

        void displayWelcome(void) const;
        void displayGoodbye(void) const;
        void displayMenu(void) const;

        void setCommand(void);
        std::string getCommand(void) const;

        void setRunning(bool state);
        bool getRunning(void) const;

};

#endif