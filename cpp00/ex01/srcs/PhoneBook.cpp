/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:32:32 by ryada             #+#    #+#             */
/*   Updated: 2025/08/13 09:28:40 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <ostream>
#include <iomanip> 

PhoneBook::PhoneBook(): _count(0), _curIndex(0){
}

int PhoneBook::getIndex() const
{
    return _curIndex;
}

int PhoneBook::getCount() const
{
    return _count;
}

int PhoneBook::getLastIndex() const
{
    return _curIndex - 1;
}

void    PhoneBook::addContact()
{
    if (_count < 8)
    {
        contacts[_curIndex].setContactInfo();
        _curIndex++;
        _count++;
    }
    else
    {
        updateIndex();
        contacts[_curIndex].setContactInfo();
        _count++;
    }
}

void PhoneBook::updateIndex()
{
    for (int i = 1; i < 8; i++)
    {
        contacts[i - 1].setFirstName(contacts[i].getFirstName());
        contacts[i - 1].setLastName(contacts[i].getLastName());
        contacts[i - 1].setNickname(contacts[i].getNickname());
        contacts[i - 1].setPhoneNumber(contacts[i].getPhoneNumber());
        contacts[i - 1].setDarkestSecret(contacts[i].getDarkestSecret());
    }
    _curIndex = 7;
}

void PhoneBook::printNewContact() const
{
    int i;
    i = getLastIndex();
    contacts[i].printContactInfo();
}

void PhoneBook::printShortContactlist() const
{
    std::cout << "|" << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << "|" << std::endl;

    for (int i = 0; i < _count && i < 8; i++)
    {
        contacts[i].printShortContactInfo(i);
    }
}

void PhoneBook::destroyNewContact()
{
    contacts[getLastIndex()].clear();
    _curIndex--;
    _count--;
}

bool PhoneBook::printContactByIndex(int i) const
{
    if (i < 0 || i >= 8 || i > _curIndex)
    {
        std::cout << "\033[1;31mInvalid index!\033[0m" << std::endl;
        return false;
    }
    contacts[i].printContactInfo();
    return true;
}

