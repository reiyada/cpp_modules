/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:07:10 by ryada             #+#    #+#             */
/*   Updated: 2025/09/01 11:32:02 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/define.hpp"
#include <iostream>

AForm::AForm(): _name("no_name"), _gradeSign(150), _gradeExec(150){
    std::cout << B_GREEN << "[ AForm default constractor has been called ]" << RESET << std::endl;
    std::cout << *this;
}

AForm::AForm(std::string newName,  int gradeSign, int gradeExec):_name(newName), _signed(false),
                                                                _gradeSign(gradeSign), _gradeExec(gradeExec) {
    if (gradeSign < 1 || gradeExec < 1) {
        throw GradeTooHighException();
    }
    else if (gradeSign > 150 || gradeExec > 150) {
        throw GradeTooLowException();
    }
    std::cout << B_GREEN << "[ AForm constractor has been called ]" << RESET << std::endl;
    std::cout << *this;
}

AForm::AForm(const AForm& other): _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {
    *this = other;//initialize bool _signed

    std::cout << B_GREEN << "[ AForm constractor(copy) has been called ]" << RESET << std::endl;
    std::cout << *this;
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->_signed = other._signed;
    }

    std::cout << B_GREEN << "[ AForm operator has been assigned ]" << RESET << std::endl;
    std::cout << *this;
    //_name, _gradeSign, _gradeExec are const -> they are initialized already with the constructor
    return *this;
}

AForm::~AForm() {
    std::cout << B_GREEN << "[ AForm destructor has been called ]" << RESET << std::endl;
    std::cout << *this; 
}


std::string AForm::getName() const {
    return this->_name;
}

bool    AForm::getSigned() const {
    return this->_signed;
}

int AForm::getGradeSign() const {
    return this->_gradeSign;
}

int AForm::getGradeExec() const {
    return this->_gradeExec;
}

void    AForm::beSigned(const Bureaucrat& b) {
    //change bool _signed if the Bureaucrat's grade is higher than _gradeSign
    if (b.getGrade() <= this->_gradeSign)
        this->_signed = true;
    else {
        throw GradeTooHighException();
    }
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}


std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "AForm Name: "<<  f.getName() << std::endl
        << "Grade to sign: " << f.getGradeSign() << std::endl
        << "Grade to execute: " << f.getGradeExec() << std::endl;
    return os;
}


bool AForm::checkExec(const Bureaucrat& executor) const {
    if (!this->getSigned()) {
        std::cerr << B_RED << "The form " << this->getName() << " has not been signed!" << RESET << std::endl;
        return false;
    }   
    if (executor.getGrade() > this->getGradeExec()) {
        throw GradeTooLowException();
        return false;
    }
    return true;
}