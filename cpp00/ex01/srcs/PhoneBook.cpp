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

int PhoneBook::getCount() const
{
    return count;
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

void PhoneBook::printShortContactlist() const
{
    int realIndex;
    int displayIndex;

    std::cout << "|" << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << "|" << std::endl;

    for (int i = 0; i < count && i < 8; i++)
    {
        realIndex = i % 8;
        if (count >= 8)
            displayIndex = (i + 8 - index) % 8;
        else
            displayIndex = i;

        contacts[realIndex].printShortContactInfo(displayIndex);
    }
}

void PhoneBook::destroyNewContact()
{
    contacts[getLastIndex()].clear();
    index--;
}

void PhoneBook::printContactByIndex(int i) const
{
    int realIndex;

    if (i < 0 || i >= count)
    {
        std::cout << "\033[1;31mInvalid index!\033[0m" << std::endl;
        return;
    }

    if (count >= 8)
        realIndex = (index + i) % 8;
    else
        realIndex = i;

    contacts[realIndex].printContactInfo();
}
