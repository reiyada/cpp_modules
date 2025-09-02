/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:27:18 by ryada             #+#    #+#             */
/*   Updated: 2025/09/02 15:19:12 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/define.hpp"
#include <iostream>

void title(std::string title) {
    std::cout << B_YELLOW << "<<<<<<<<<<<<<<<<<<<< " << title << " >>>>>>>>>>>>>>>>>>>>" << RESET << std::endl;
}

int main() {
    title("Construction");
    ShrubberyCreationForm* sForm1 = new ShrubberyCreationForm("file1", "sForm1", 10, 20);

    title("Construction with invalid grades");
    try
    {
        ShrubberyCreationForm* sForm2 = new ShrubberyCreationForm("file2", "sForm2", 0, 140);
        delete sForm2;
    }
    catch(const std::exception& e)
    {
        std::cerr << B_RED << e.what() << RESET << '\n';
    }
    

    title("Destruction");
    delete sForm1;
    return 0;
}

// int main() {
//     title("Construction");
//     Bureaucrat* rei = new Bureaucrat("Rei", 50);
//     Bureaucrat* reiYada = new Bureaucrat("Rei Yada", 60);
//     Bureaucrat* test1 = new Bureaucrat("test1", 1);
//     Bureaucrat* test2 = new Bureaucrat("test2", 150);
//     Form* stage = new Form("Stage", 60, 70);
//     Form* visa = new Form("Visa", 10, 80);

//     title("Construction with invalid grade");
//     try
//     {
//         Bureaucrat* test3 = new Bureaucrat("test3", 0);
//         delete test3;
//     }
//     catch (std::exception& e)
//     {
//         std::cerr << B_RED << e.what() << RESET << std::endl;
//     }
//     try
//     {
//         Bureaucrat* test4 = new Bureaucrat("test4", 151);
//         delete test4;
//     }
//     catch (std::exception& e)
//     {
//         std::cerr << B_RED << e.what() << RESET << std::endl;
//     }
//     try
//     {
//         Form* test5 = new Form("test5", 1, 151);
//         delete test5;
//     }
//     catch (std::exception& e)
//     {
//         std::cerr << B_RED << e.what() << RESET << std::endl;
//     }
//     try
//     {
//         Form* test6 = new Form("test6", 0, 140);
//         delete test6;
//     }
//     catch (std::exception& e)
//     {
//         std::cerr << B_RED << e.what() << RESET << std::endl;
//     }

//     title("Default construction");
//     Form* noName = new Form();

//     title("Copy construction");
//     Form* clone = new Form(*stage);

//     title("Increase test");
//     try
//     {
//         test1->incGrade();
//     }
//     catch (std::exception& e)
//     {
//         std::cerr << B_RED << e.what() << RESET << std::endl;
//     }

//     title("Decrease test");
//     try
//     {
//         test2->decGrade();
//     }
//     catch (std::exception& e)
//     {
//         std::cerr << B_RED << e.what() << RESET << std::endl;
//     }

//     title("Test to sign");
//     rei->signForm(*stage);
//     std::cout << "Has " << stage->getName() << " been signed?: ";
//     (stage->getSigned() == true) ? (std::cout << "Yes"): (std::cout << "No");
//     std::cout << std::endl;

//     title("Grade too low to sign");
//     try
//     {
//         reiYada->signForm(*visa);
//     }
//     catch (std::exception& e)
//     {
//         std::cerr << B_RED << e.what() << RESET << std::endl;
//     }
//     std::cout << "Has visa been signed?: ";
//     (visa->getSigned() == true) ? (std::cout << "Yes"): (std::cout << "No");
//     std::cout << std::endl;

//     title("Destruction");
//     delete rei;
//     delete reiYada;
//     delete clone;
//     delete test1;
//     delete test2;
//     delete stage;
//     delete visa;
//     delete noName;
//     return 0;
// }
