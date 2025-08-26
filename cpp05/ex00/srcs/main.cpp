/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:27:18 by ryada             #+#    #+#             */
/*   Updated: 2025/08/26 16:37:16 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/define.hpp"
#include <iostream>

void title(std::string title) {
    std::cout << B_YELLOW << "<<<<<<<<<<<<<<<<<<<<" << title << ">>>>>>>>>>>>>>>>>>>>" << std::endl;
}

int main() {
    title("Construction");
    Bureaucrat* rei = new Bureaucrat("Rei", 50);
    Bureaucrat* test1 = new Bureaucrat("Test1", 5);
    Bureaucrat* test2 = new Bureaucrat("Test2", 145);

    title("Copy construction");
    Bureaucrat* clone = new Bureaucrat(*rei);

    title("Grade increase");
    std::cout << B_CYAN << "Bureaucrat* rei " << RESET;
    rei->incGrade();
    std::cout << B_CYAN << "Bureaucrat* clone " << RESET;
    clone->incGrade();
    std::cout << B_CYAN << "Bureaucrat* test1 " << RESET;
    test1->incGrade();
    std::cout << B_CYAN << "Bureaucrat* test2 " << RESET;
    test2->incGrade();

    title("Grade decreese");
    std::cout << B_CYAN << "Bureaucrat* rei " << RESET;
    rei->decGrade();
    std::cout << B_CYAN << "Bureaucrat* clone " << RESET;
    clone->decGrade();
    std::cout << B_CYAN << "Bureaucrat* test1 " << RESET;
    test1->decGrade();
    std::cout << B_CYAN << "Bureaucrat* test2 " << RESET;
    test2->decGrade();

    title("Exception test");
    while (true) {
        try
        {
            test1->incGrade();
        }
        catch(const std::exception& e)
        {
            std::cerr << B_RED << e.what() << RESET << std::endl;
            break;
        }
    }
    while (true) {
        try
        {
            test2->decGrade();
        }
        catch(const std::exception& e)
        {
            std::cerr << B_RED << e.what() << RESET << std::endl;
            break;
        }
    }

    title("Destruction");
    delete rei;
    delete test1;
    delete test2;
    delete clone;
    return 0;
}