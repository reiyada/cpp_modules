/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:18:28 by ryada             #+#    #+#             */
/*   Updated: 2025/08/06 09:38:40 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    Harl newHarl;

    if (argc != 2)
    {
        std::cerr << "Invalid argument number." << std::endl;
        return 1;
    }
    newHarl.complain(argv[1]);
    return 0;
}