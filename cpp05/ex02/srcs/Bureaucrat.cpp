/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:46:19 by ryada             #+#    #+#             */
/*   Updated: 2025/10/29 13:05:55 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/define.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(): _name("no_name"), _grade(150) {
    std::cout << B_CYAN << "[ Bureaucrat default constractor has been called ]" << RESET << std::endl;
    std::cout << *this;
}

Bureaucrat::Bureaucrat(std::string newName, int startGrade): _name(newName), _grade(startGrade) {
    //check if you initialize the valid grade
    if (startGrade < 1)
        throw GradeTooHighException();
    else if (startGrade > 150)
        throw GradeTooLowException();

    std::cout << B_CYAN << "[ Bureaucrat constractor has been called ]" << RESET << std::endl;
    std::cout << *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {
    std::cout << B_CYAN << "[ Bureaucrat constractor(copy) has been called ]" << RESET << std::endl;
    std::cout << *this;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->_grade = other._grade;
        //_name is const so we cannot set the same as other
    }
    std::cout << B_CYAN << "[ Bureaucrat operator has been assigned ]" << RESET << std::endl;
    std::cout << *this;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << B_CYAN << "[ Bureaucrat destructor has been called ]" << RESET << std::endl;
    std::cout << *this;
}


std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incGrade() {
    //if the grade is not 1 (highest)
    if (this->_grade <= 1)
        throw GradeTooHighException();
    this->_grade--;
    std::cout << B_CYAN << "[ Bureaucrat grade has been increased ]" << RESET << std::endl;
    std::cout << *this;
}

void Bureaucrat::decGrade() {
    //if the grade is not 150 (lowest)
    if (this->_grade >= 150)
        throw GradeTooLowException();
    this->_grade++;
    std::cout << B_CYAN << "[ Bureaucrat grade has been decreased ]" << RESET << std::endl;
    std::cout << *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return os;
}

void Bureaucrat::signForm(AForm& f) {
    try
    {
        f.beSigned(*this);
        std::cout << this->_name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << B_RED << this->_name << " couldn't sign " << f.getName() << " because "
                    << e.what() << RESET << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
    try
    {
        form.execute(*this);
        std::cout << B_CYAN << "Bureaucrat: " << this->_name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << B_RED << "Bureaucrat: " << this->_name << " couldn't execute " << form.getName() << " because "
                    << e.what() << RESET << std::endl;
    }
}
