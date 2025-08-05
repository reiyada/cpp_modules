/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:32:22 by ryada             #+#    #+#             */
/*   Updated: 2025/08/05 17:09:04 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"
#include "../includes/utils.hpp"


void    Contact::setContactInfo()
{
    do {
        std::cout << "Enter First Name: ";
        std::getline(std::cin, firstName);
    } while (!isAlphaString(firstName) || !checkEmpty(firstName));

    do {
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, lastName);
    } while (!isAlphaString(lastName) || !checkEmpty(lastName));

    do {
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, nickname);
    } while (!isAlphaString(nickname) || !checkEmpty(nickname));

    do {
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, phoneNumber);
    } while (!isDigitString(phoneNumber) || !checkEmpty(phoneNumber));

    do {
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, darkestSecret);
    } while (!checkEmpty(darkestSecret));
}

void Contact::printContactInfo() const
{
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void Contact::printShortContactInfo(int index) const
{
    std::cout << "|";
    std::cout << std::setw(10) << index << "|" ;
    printUpTo10(firstName);
    std::cout << "|";
    printUpTo10(lastName);
    std::cout << "|";
    printUpTo10(nickname);
    std::cout << "|" << std::endl;
}

void Contact:: clear()
{
    firstName = "";
    lastName = "";
    nickname = "";
    phoneNumber = "";
    darkestSecret = "";
}