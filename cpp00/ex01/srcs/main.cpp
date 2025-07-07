
#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"
#include "../includes/utils.hpp"
#include <ostream>
#include <string>

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
            std::cout << "The new contact has been successfully added to your Phone Book!" << std::endl << std::endl;
            return true;
        }
        else if (yn == "NO")
        {
            std::cout << "You go back to the menu." << std::endl << std::endl;
            return false;
        }
            
        else
            std::cout << "Enter 'YES' or 'NO', please!" << std::endl;
    }
}

void    searchByIndex(PhoneBook phoneBook)
{
    int index;
    std::string input;

    while (true)
    {
        std::cout << "Enter the index to see full information: ";
        std::getline(std::cin, input);
        if (!checkEmpty(input))
            continue;
        if (!isDigitString(input))
        {
            std::cout << "Index must be a digit!" << std::endl;
            continue;
        }
        else
            break;
    }
    index = std::atoi(input.c_str());
    std::cout << std::endl;
    phoneBook.printContactByIndex(index);
    std::cout << std::endl;
}

int exitPhoneBook()
{
    std::string input;

    while (true)
    {
        std::cout << "Are you sure to exit your phone book? (YES/NO):";
        std::getline(std::cin, input);
        if (input == "YES")
        {
            std::cout << "Thank you for using the phone book! We reset the data." << std::endl;
            return 1;
        }
        else if (input == "NO")
        {
            std::cout << "You go back to the menu." << std::endl << std::endl;
            return 0;
        }
        else
            std::cout << "Enter 'YES' or 'NO', please!" << std::endl;
    }
}

void    runPhoneBook()
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