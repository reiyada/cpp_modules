/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:32:22 by ryada             #+#    #+#             */
/*   Updated: 2025/08/13 08:57:34 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"
#include "../includes/utils.hpp"

std::string Contact::getFirstName()
{
    return _firstName;
}

std::string Contact::getLastName()
{
    return _lastName;
}

std::string Contact::getNickname()
{
    return _nickname;
}

std::string Contact::getDarkestSecret()
{
    return _darkestSecret;
}

std::string Contact::getPhoneNumber()
{
    return _phoneNumber;
}

void    Contact::setFirstName(std::string newName)
{
    _firstName = newName;
}

void    Contact::setLastName(std::string newName)
{
    _lastName = newName;
}

void    Contact::setNickname(std::string newName)
{
    _nickname = newName;
}

void    Contact::setPhoneNumber(std::string newNum)
{
    _phoneNumber = newNum;
}

void    Contact::setDarkestSecret(std::string newSec)
{
    _darkestSecret = newSec;
}

void    Contact::setContactInfo()
{
    do {
        std::cout << "Enter First Name: ";
        std::getline(std::cin, _firstName);
    } while (!isAlphaString(_firstName) || !checkEmpty(_firstName));

    do {
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, _lastName);
    } while (!isAlphaString(_lastName) || !checkEmpty(_lastName));

    do {
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, _nickname);
    } while (!isAlphaString(_nickname) || !checkEmpty(_nickname));

    do {
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, _phoneNumber);
    } while (!isDigitString(_phoneNumber) || !checkEmpty(_phoneNumber));

    do {
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, _darkestSecret);
    } while (!checkEmpty(_darkestSecret));
}

void Contact::printContactInfo() const
{
    std::cout << "First Name: " << _firstName << std::endl;
    std::cout << "Last Name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone Number: " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}

void Contact::printShortContactInfo(int index) const
{
    std::cout << "|";
    std::cout << std::setw(10) << index << "|" ;
    printUpTo10(_firstName);
    std::cout << "|";
    printUpTo10(_lastName);
    std::cout << "|";
    printUpTo10(_nickname);
    std::cout << "|" << std::endl;
}

void Contact:: clear()
{
    _firstName = "";
    _lastName = "";
    _nickname = "";
    _phoneNumber = "";
    _darkestSecret = "";
}