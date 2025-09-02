/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:32:26 by ryada             #+#    #+#             */
/*   Updated: 2025/09/02 16:53:15 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"
#include "../includes/utils.hpp"
#include <iostream>
#include <ostream>
#include <string>

bool    newContactConfirm(PhoneBook phoneBook)
{
    std::string yn;

    std::cout << std::endl;
    if (phoneBook.getCount() > 8)
        std::cout << "\033[1;31mSince you are trying to add more than 8 contacts," << std::endl 
                    << "we need to delete the oldest contact to add the new one.\033[0m" << std::endl;
    std::cout << "\033[32mAre you sure to add this contact?\033[0m " << std::endl;
    phoneBook.printNewContact();
    std::cout << std::endl;

    while (true)
    {
        std::cout << "\033[32m(YES/NO): \033[0m";
        std::getline(std::cin, yn);
        if (!checkEmpty(yn))
            continue;
        if (yn == "YES")
        {
            std::cout << "\033[32mThe new contact has been successfully added to your Phone Book!\033[0m" << std::endl << std::endl;
            return true;
        }
        else if (yn == "NO")
        {
            //need to set null for the new contact
            std::cout << "\033[32mYou go back to the menu.\033[0m" << std::endl << std::endl;
            return false;
        }
            
        else
            std::cout << "\033[1;31mEnter 'YES' or 'NO', please!\033[0m" << std::endl;
    }
}

void    searchByIndex(PhoneBook phoneBook)
{
    int index;
    std::string input;

    while (true)
    {
        if (phoneBook.getCount() == 0)
        {
            std::cout << "\033[32mThere is no contact on the phonebook yet.\033[0m" << std::endl;
            return ;
        }
        std::cout << "\033[32mEnter the index to see full information: \033[0m";
        std::getline(std::cin, input);
        if (!checkEmpty(input))
            continue;
        if (!isDigitString(input))
        {
            std::cout << "\033[1;31mIndex must be a digit!\033[0m" << std::endl;
            continue;
        }
        else
        {
            index = std::atoi(input.c_str());
            std::cout << std::endl;
            if (phoneBook.printContactByIndex(index))
            {
                std::cout << std::endl;
                break;
            }
        }
    }
}

int exitPhoneBook()
{
    std::string input;

    while (true)
    {
        std::cout << "\033[32mAre you sure to exit your phone book? (YES/NO):\033[0m";
        std::getline(std::cin, input);
        if (!checkEmpty(input))
            continue;
        if (input == "YES")
        {
            std::cout << "\033[32mThank you for using the phone book! We reset the data.\033[0m" << std::endl;
            return 1;
        }
        else if (input == "NO")
        {
            std::cout << "\033[32mYou go back to the menu.\033[0m" << std::endl << std::endl;
            return 0;
        }
        else
            std::cout << "\033[1;31mEnter 'YES' or 'NO', please!\033[0m" << std::endl;
    }
}

void    runPhoneBook()
{
    PhoneBook newPhoneBook;
    std::string cmd;

    while (true)
    {
        std::cout << "\033[1;32mEnter command (ADD/SEARCH/EXIT):\033[0m ";
        if (!std::getline(std::cin, cmd))
            break;
        if (cmd == "ADD")
        {
            newPhoneBook.addContact();
            if (!newContactConfirm(newPhoneBook))
                newPhoneBook.destroyNewContact();//remove the new contact
        }
        else if (cmd == "SEARCH")
        {
            newPhoneBook.printShortContactlist();
            std::cout << std::endl;
            //Ask for the index
            searchByIndex(newPhoneBook);
        }
        else if (cmd == "EXIT")
        {
            if (exitPhoneBook())
                break;
        }
    }
}

int main()
{
    runPhoneBook();
    return 0;
}