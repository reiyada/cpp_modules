#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int count;
    int index;

public:
    PhoneBook()//constructor
    {
        count = 0;
        index = 0;
    };
    int getIndex() const;
    void addContact();
    void printNewContact() const;
    void printShortContactlist() const;
    void destroyNewContact();
};

#endif
