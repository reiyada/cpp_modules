#include "../includes/Contact.hpp"
#include <cctype>
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <string>

/* -------------------------------------------------------------------------- */
/*                                   HELPER                                   */
/* -------------------------------------------------------------------------- */

bool checkEmpty(const std::string& str)
{
    if (str.empty())
    {
        std::cout << "Enter something, please!" << std::endl;
        return false;
    }
    return true;
}

bool isAlphaString(const std::string& str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isalpha(str[i]))
        {
            std::cout << "You can enter only characters!" << std::endl;
            return false;
        }
    }
    return true;
}

bool isDigitString(const std::string& str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            std::cout << "You can enter only digits!" << std::endl;
            return false;
        }
    }
    return true;
}

void    printUpTo10(const std::string& str)
{
    int space;
    if (str.length() < 10)
    {
        space =  10 - str.length();
        for(; space > 0; space--)
            std::cout << " ";
    }
    for (size_t i = 0; i < str.length() && i < 10; i++)
    {
        std::cout << str[i];
    }
}

/* -------------------------------------------------------------------------- */
/*                               CLASS FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

//maybe I can do like required info and not required ones
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