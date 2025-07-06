#include <iostream>
#include <ostream>
#include <string>
#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"

bool    newContactConfirm(PhoneBook phoneBook)
{
    std::string yn;

    std::cout << std::endl;
    std::cout << "Are you sure to add this contact?" << std::endl;
    phoneBook.printNewContact();
    std::cout << std::endl;

    while (true)
    {
        std::cout << "(YES/NO): ";
        std::getline(std::cin, yn);
        if (yn == "YES")
        {
            std::cout << "The new contact has been successfully added to your Phone Book!" << std::endl;
            return true;
        }
        else if (yn == "NO")
            return false;
        else
            std::cout << "Enter 'YES' or 'NO', please!" << std::endl;
    }
}

int    runPhoneBook()
{
    PhoneBook newPhoneBook;
    std::string cmd;

    while (true)
    {
        std::cout << "Enter command (ADD/SEARCH/EXIT): ";
        std::getline(std::cin, cmd);
    
        if (cmd == "ADD")
        {
            newPhoneBook.addContact();
            if (!newContactConfirm(newPhoneBook))
                return 0;//remove the new contact
        }
        else if (cmd == "SEARCH")
        {
            newPhoneBook.printShortContactlist();
            //Ask for the index
        }
        else if (cmd == "EXIT")
        {
            //make sure if they really wanna exit
            break;
        }
    }
    return 1;
}

int main()
{
    if (runPhoneBook())
        return 0;
    else
        return 1;
}