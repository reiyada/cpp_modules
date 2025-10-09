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
    title("Construction");
    AForm* result1;
    AForm* result2;
    AForm* result3;
    AForm* result4;
    Intern intern1;
    Intern intern2;
    Intern intern3;
    Intern intern4;

    title("Making forms");
    result1 = intern1.makeForm("shrubbery creation", "SHHHH");
    result2 = intern2.makeForm("robotom request", "ROOOO");
    result3 = intern3.makeForm("presidential pardon", "PRRRRR");

    title("Try to make invalid form");
    result4 = intern4.makeForm("hahahaha creation","LOOOOL");

    title("Destruction");
    delete result1;
    delete result2;
    delete result3;
    delete result4;
}
