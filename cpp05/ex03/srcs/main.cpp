/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:27:18 by ryada             #+#    #+#             */
/*   Updated: 2025/10/29 13:36:08 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"
#include "../includes/define.hpp"
#include <exception>
#include <iostream>

void title(std::string title) {
    std::cout << B_YELLOW << "<<<<<<<<<<<<<<<<<<<< " << title << " >>>>>>>>>>>>>>>>>>>>" << RESET << std::endl;
}

// "shrubbery creation"
// "robotom request"
// "presidential pardon"

int main() {
    try {
    title("Construction");
    Intern intern;
    Bureaucrat boss("Boss", 1);
    Bureaucrat lowGuy("InternSupport", 150);

    title("Intern creates forms");
    AForm* sForm = intern.makeForm("shrubbery creation", "Home");
    AForm* rForm = intern.makeForm("robotomy request", "Bender");
    AForm* pForm = intern.makeForm("presidential pardon", "Ford Prefect");
    AForm* invalid = intern.makeForm("nonsense form", "Nowhere");

    title("Signing forms");
    boss.signForm(*sForm);
    boss.signForm(*rForm);
    boss.signForm(*pForm);

    title("Executing forms");
    boss.executeForm(*sForm);
    boss.executeForm(*rForm);
    boss.executeForm(*pForm);
    
    title("Destruction");
    delete invalid;
    delete sForm;
    delete rForm;
    delete pForm;
    } catch (std::exception& e) {
        std::cerr << B_RED << "Exception: " << e.what() << RESET << std::endl;
    }
    return 0;
}
