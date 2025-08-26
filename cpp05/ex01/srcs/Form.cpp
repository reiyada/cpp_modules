/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:07:10 by ryada             #+#    #+#             */
/*   Updated: 2025/08/26 17:39:48 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/define.hpp"
#include <iostream>

Form::Form(std::string newName,  int gradeSign, int gradeExec):_name(newName), _reason(), _signed(false),
                                                                _gradeSign(gradeSign), _gradeExec(gradeExec) {
    
    std::cout << B_GREEN << "[ Form constractor has been called ]" << RESET << std::endl;
    std::cout << "Name: " << this->getName() << std::endl
                << "Grade to sign: " << this->getGradeSign() << std::endl
                << "Grade to execute: " << this->getGradeExec() << std::endl;
                
    if (gradeSign < 1 || gradeExec < 1) {
        this->_reason = "Grade too high";
        throw GradeTooHighException();
    }
    else if (gradeSign > 150 || gradeExec > 150) {
        this->_reason = "Grade too low";
        throw GradeTooLowException();
    }
}

Form::Form(const Form& other): _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {
    *this = other;//initialize bool _signed

    std::cout << B_GREEN << "[ Form constractor(copy) has been called ]" << RESET << std::endl;
    std::cout << "Name: " << this->getName() << std::endl
                << "Grade to sign: " << this->getGradeSign() << std::endl
                << "Grade to execute: " << this->getGradeExec() << std::endl;
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_reason = other._reason;
        this->_signed = other._signed;
    }

    std::cout << B_GREEN << "[ Form operator has been assigned ]" << RESET << std::endl;
    std::cout << "Name: " << this->getName() << std::endl
                << "Grade to sign: " << this->getGradeSign() << std::endl
                << "Grade to execute: " << this->getGradeExec() << std::endl;
    //_name, _gradeSign, _gradeExec are const -> they are initialized already with the constructor
    return *this;
}

Form::~Form() {
    std::cout << B_GREEN << "[ Form destructor has been called ]" << RESET << std::endl;
    std::cout << "Name: " << this->getName() << std::endl
                << "Grade to sign: " << this->getGradeSign() << std::endl
                << "Grade to execute: " << this->getGradeExec() << std::endl;
}


std::string Form::getName() const {
    return this->_name;
}

std::string Form::getReason() const {
    return this->_reason;
}

bool    Form::getSigned() const {
    return this->_signed;
}

int Form::getGradeSign() const {
    return this->_gradeSign;
}

int Form::getGradeExec() const {
    return this->_gradeExec;
}


void    Form::beSigned(const Bureaucrat& b) {
    //change bool _signed if the Bureaucrat's grade is higher than _gradeSign
    if (b.getGrade() <= this->_gradeSign)
        this->_signed = true;
    else {
        throw GradeTooLowException();
        this->_reason = "Grade too low";
    }
}


const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}


std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName() << std::endl
        << "Grade to sign: " << f.getGradeSign() << std::endl
        << "Grade to execute: " << f.getGradeExec() << std::endl;
    return os;
}