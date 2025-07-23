#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook myPhoneBook;

    for (int i = 0; i < 8; i++)
    {
        Contact* contact = &myPhoneBook._contacts[i];
        contact->display();
    }
}