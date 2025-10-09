#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "define.hpp"
#include <exception>
#include <iostream>

class Intern {
private:

public:
    Intern();
    // Intern(const Intern& other);
    // Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(std::string const formName, std::string const formTarget);
};


#endif