#include "../includes/utils.hpp"

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
    size_t i;
    if (str.length() < 10)
    {
        space =  10 - str.length();
        for(; space > 0; space--)
            std::cout << " ";
    }
    for (i = 0; i < str.length() && i < 9; i++)
    {
        std::cout << str[i];
    }
    if (str.length() == 10)
        std::cout << str[i];
    if (str.length() > 10)
        std::cout << ".";
}