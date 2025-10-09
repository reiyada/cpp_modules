/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:27:18 by ryada             #+#    #+#             */
/*   Updated: 2025/09/22 09:31:37 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/define.hpp"
#include <exception>
#include <iostream>

void title(std::string title) {
    std::cout << B_YELLOW << "<<<<<<<<<<<<<<<<<<<< " << title << " >>>>>>>>>>>>>>>>>>>>" << RESET << std::endl;
}

//SH: 145 to sign, 137 to exec
//ROB: 72 to sign, 45 to exec
//PRE: 25 to sign, 5 to exec
int main() {
    try {
        title("Bureaucrat Construction");
        Bureaucrat* bureauGood = new Bureaucrat("bureauGood", 3);
        Bureaucrat* bureauBad = new Bureaucrat("bureauBad", 70);

        title("Form Construction");
        ShrubberyCreationForm* sForm = new ShrubberyCreationForm("sTarget", "sForm");
        RobotomyRequestForm* rForm = new RobotomyRequestForm("rTarget", "rFrom");
        PresidentialPardonForm* pForm = new PresidentialPardonForm("pTarget", "pForm");

        title("bureauGood try to sign Forms");//all good
        bureauGood->signForm(*sForm);
        bureauGood->signForm(*rForm);
        bureauGood->signForm(*pForm);

        title("bureauBad try to sign Forms");
        bureauBad->signForm(*sForm);//good
        bureauBad->signForm(*rForm);//good
        bureauBad->signForm(*pForm);//bad

        title("bureauGood try to execute");//all good
        bureauGood->executeForm(*sForm);
        bureauGood->executeForm(*rForm);
        bureauGood->executeForm(*pForm);

        title("bureauBad try to execute");
        bureauBad->executeForm(*sForm);//good
        bureauBad->executeForm(*rForm);//bad
        bureauBad->executeForm(*pForm);//bad

        title("Destruction");
        delete bureauGood;
        delete bureauBad;
        delete sForm;
        delete rForm;
        delete pForm;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}

// int main() {
//     title("Construction");
//     Bureaucrat* b1 = new Bureaucrat("b1", 10);
//     Bureaucrat* b2 = new Bureaucrat("b2", 147);
//     ShrubberyCreationForm* sForm1 = new ShrubberyCreationForm("sTarget1", "sForm1");
//     ShrubberyCreationForm* sForm2 = new ShrubberyCreationForm("sTarget2", "sForm2");
//     RobotomyRequestForm* rForm1 = new RobotomyRequestForm("rTarget1", "rForm1");
//     RobotomyRequestForm* rForm2 = new RobotomyRequestForm("rTarget2", "rForm2");
//     PresidentialPardonForm* pForm1 = new PresidentialPardonForm("pTarget1", "pForm1");
//     PresidentialPardonForm* pForm2 = new PresidentialPardonForm("pTarget2", "pForm2");

//     title("Sign sForm1 with good grade");
//     b1->signForm(*sForm1);
//     std::cout << "Has " << sForm1->getName() << " been signed?: ";
//     (sForm1->getSigned() == true) ? (std::cout << "Yes"): (std::cout << "No");
//     std::cout << std::endl;

//     title("Try to sign sForm1 with low grade");
//     b2->signForm(*sForm1);
//     std::cout << "Has " << sForm1->getName() << " been signed?: ";
//     (sForm2->getSigned() == true) ? (std::cout << "Yes"): (std::cout << "No");
//     std::cout << std::endl;

//     title("Execute sForm1");
//     sForm1->execute(*b1);
//     b1->executeForm(*sForm1);

//     title("Execute sForm2 without signing");
//     sForm2->execute(*b1);
//     b1->executeForm(*sForm2);

//     title("Destruction");
//     delete b1;
//     delete b2;
//     delete sForm1;
//     delete sForm2;
//     delete rForm1;
//     delete rForm2;
//     delete pForm1;
//     delete pForm2;
//     return 0;
// }

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
