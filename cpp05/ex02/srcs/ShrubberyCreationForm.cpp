/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:33:35 by ryada             #+#    #+#             */
/*   Updated: 2025/09/02 17:02:00 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/define.hpp"
#include <iostream>
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("no_name", 145, 137), _target("no_target") {
    std::cout << B_MAGENTA << "[ ShrubberyCreationForm default constractor has been called ]" << RESET << std::endl;
    std::cout << *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget, std::string newName): AForm(newName, 145, 137), _target(newTarget) {
    std::cout << B_MAGENTA << "[ ShrubberyCreationForm constractor has been called ]" << RESET << std::endl;
    std::cout << *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), _target(other._target) {
    std::cout << B_MAGENTA << "[ ShrubberyCreationForm constractor(copy) has been called ]" << RESET << std::endl;
    std::cout << *this;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    std::cout << B_MAGENTA << "[ ShrubberyCreationForm operator has been assigned ]" << RESET << std::endl;
    std::cout << *this;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << B_MAGENTA << "[ ShrubberyCreationForm destructor has been called ]" << RESET << std::endl;
    std::cout << *this;
}

std::string ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

void    ShrubberyCreationForm::execute(const Bureaucrat& executor) {
    if (this->checkExec(executor)) {
        std::string filename = this->_target + "_shrubbery";
        std::ofstream outfile((filename).c_str());
        if (!outfile) {
            std::cerr << B_RED << "ERROR: cannot open outfile." << RESET << std::
        }
    }
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& s) {
    os << "ShrubberyCreationForm Name: "<<  s.getName() << std::endl
        << "Grade to sign: " << s.getGradeSign() << std::endl
        << "Grade to execute: " << s.getGradeExec() << std::endl
        << "Target: " << s.getTarget() << std::endl;
    return os;
}

