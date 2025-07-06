#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <ostream>
#include <iomanip> 

void    PhoneBook::addContact()
{
    contacts[index].setContactInfo();

    index = (index + 1) % 8;
    if (count < 8)
        count++;
}

void PhoneBook::printNewContact() const
{
    int i;
    i = index - 1;
    contacts[i].printContactInfo();
}

void PhoneBook::printShortContactlist()const
{
    std::cout << "|" << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << "|" << std::endl;
    for(int i = 0; i < index; i++)
    {
        contacts[i].printShortContactInfo(i);
    }
}