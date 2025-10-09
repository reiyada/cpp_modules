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
