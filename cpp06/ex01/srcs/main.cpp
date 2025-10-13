/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:27:18 by ryada             #+#    #+#             */
/*   Updated: 2025/09/01 09:13:40 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include "../includes/define.hpp"
#include <iostream>

void title(std::string title) {
    std::cout << B_YELLOW << "<<<<<<<<<<<<<<<<<<<< " << title << " >>>>>>>>>>>>>>>>>>>>" << std::endl;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << B_RED << "wrong argument: ./ex00 input" << RESET << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}