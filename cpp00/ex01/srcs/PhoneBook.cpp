/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:32:32 by ryada             #+#    #+#             */
/*   Updated: 2025/08/05 17:08:56 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <ostream>
#include <iomanip> 

int PhoneBook::getIndex() const
{
    return index;
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
        realIndex = (index + i) % 8;
        displayIndex = i;
        contacts[realIndex].printShortContactInfo(displayIndex);
    }
}

void PhoneBook::destroyNewContact()
{
    contacts[getLastIndex()].clear();
    index--;
    count--;
}

bool PhoneBook::printContactByIndex(int i) const
{
    int realIndex;

    if (i < 0 || i >= count)
    {
        std::cout << "\033[1;31mInvalid index!\033[0m" << std::endl;
        return false;
    }
    realIndex = (index + i) % 8;
    contacts[realIndex].printContactInfo();
    return true;
}
