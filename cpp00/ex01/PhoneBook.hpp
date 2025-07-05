#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
public:
    Contact contacts[8];
    int count;
    int nextIndex;
};

#endif