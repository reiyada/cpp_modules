#include "../includes/Intern.hpp"
#include <iostream>

Intern::Intern(){
    std::cout << B_BLUE << "[ Intern default constractor has been called ]" << RESET << std::endl;
}

Intern::~Intern(){
    std::cout << B_BLUE << "[ Intern default destructor has been called ]" << RESET << std::endl;
}


AForm* Intern::makeForm(std::string const formName, std::string const formTarget) {
    std::string names[3]= {
        "shrubbery creation",
        "robotom request",
        "presidential pardon"
    };
    AForm* forms[3] = {
        new ShrubberyCreationForm(formTarget),
        new RobotomyRequestForm(formTarget),
        new PresidentialPardonForm(formTarget)
    };
    for (int i = 0; i < 3; i++) {
        if (formName == names[i]) {
            for ( int j = 0; j < 3; j++) {
                if (i != j)
                    delete forms[j];
            }
            std::cout << B_BLUE << "Intern creates " << names[i] << RESET << std::endl;
            return forms[i];
        }
    }
    for ( int j = 0; j < 3; j++)
        delete forms[j];
    std::cerr << B_RED << "Form name didn't mach with any form" << RESET << std::endl;
    return NULL;
}