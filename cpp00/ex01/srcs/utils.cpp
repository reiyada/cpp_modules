/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:32:36 by ryada             #+#    #+#             */
/*   Updated: 2025/08/05 15:32:36 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.hpp"

bool checkEmpty(const std::string& str)
{
    if (str.empty())
    {
        std::cout << "\033[1;31mEnter something, please!\033[0m" << std::endl;
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
            std::cout << "\033[1;31mYou can enter only characters!\033[0m" << std::endl;
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
            std::cout << "\033[1;31mYou can enter only digits!\033[0m" << std::endl;
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