/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 08:48:38 by ryada             #+#    #+#             */
/*   Updated: 2025/08/22 15:21:35 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"
#include <iostream>

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void)
{
    std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
                << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money!"
                << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
                << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now."
                << std::endl;
}

void Harl::complain(std::string level)
{
    int code = -1;//init as invalid
    if (level == "DEBUG")
        code = 0;
    else if (level == "INFO")
        code = 1;
    else if (level == "WARNING")
        code = 2;
    else if (level == "ERROR")
        code = 3;

    switch (code) {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            debug();
            std::cout << std::endl;
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            info();
            std::cout << std::endl;
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            warning();
            std::cout << std::endl;
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            error();
            std::cout << std::endl;
            break;
        default:
            std::cout <<"[ Probably complaining about insignificant problems ]" <<std::endl;
    }
}

// void Harl::complain(std::string level)
// {
//     std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
//     void (Harl::*functions[])() = {
//         &Harl::debug,
//         &Harl::info,
//         &Harl::warning,
//         &Harl::error,
//     };

//     for(int i = 0; i < 4; i++)
//     {
//         if (level == levels[i])
//         {
//             for (; i < 4; i++)
//             {
//                 std::cout << "[ " << levels[i] << " ]" << std::endl;
//                 (this->*functions[i])();
//                 std::cout << std::endl;
//             }
//             return;
//         }
//     }
//     std::cout <<"[ Probably complaining about insignificant problems ]" <<std::endl;
// }
