#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <ostream>
#include <iomanip> 

int PhoneBook::getIndex() const
{
    return index - 1;
}

int PhoneBook::getLastIndex() const
{
    if (count == 0)
        return -1;
    return (index == 0) ? 7 : index - 1;
}

void    PhoneBook::addContact()
{
    contacts[index].setContactInfo();
    index = (index + 1) % 8;
    count++;
}

void PhoneBook::printNewContact() const
{
    int i;
    i = getLastIndex();
    contacts[i].printContactInfo();
}

void PhoneBook::printShortContactlist()const
{
    int fixedIndex;

    std::cout << "|" << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << "|" << std::endl;
    for(int i = 0; i < count && i < 8; i++)
    {
        fixedIndex = i % 8;
        contacts[fixedIndex].printShortContactInfo(i);
    }
}

void PhoneBook::destroyNewContact()
{
    // int index;

    // index = getIndex();
    contacts[getLastIndex()].clear();
    index--;
}

void PhoneBook::printContactByIndex(int i) const
{
    int fixedIndex;

    if (i < 0 || i > count || i >= 8)
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    fixedIndex = i % 8;
    contacts[fixedIndex].printContactInfo();
}
