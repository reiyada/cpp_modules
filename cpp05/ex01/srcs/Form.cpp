/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:07:10 by ryada             #+#    #+#             */
/*   Updated: 2025/09/01 10:44:00 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/define.hpp"
#include <iostream>

Form::Form(): _name("no_name"), _gradeSign(150), _gradeExec(150){
    std::cout << B_GREEN << "[ Form default constractor has been called ]" << RESET << std::endl;
    std::cout << *this;
}

Form::Form(std::string newName,  int gradeSign, int gradeExec):_name(newName), _signed(false),
                                                                _gradeSign(gradeSign), _gradeExec(gradeExec) {
    if (gradeSign < 1 || gradeExec < 1) {
        throw GradeTooHighException();
    }
    else if (gradeSign > 150 || gradeExec > 150) {
        throw GradeTooLowException();
    }
    std::cout << B_GREEN << "[ Form constractor has been called ]" << RESET << std::endl;
    std::cout << *this;
}

Form::Form(const Form& other): _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {
    *this = other;//initialize bool _signed

    std::cout << B_GREEN << "[ Form constractor(copy) has been called ]" << RESET << std::endl;
    std::cout << *this;
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_signed = other._signed;
    }

    std::cout << B_GREEN << "[ Form operator has been assigned ]" << RESET << std::endl;
    std::cout << *this;
    //_name, _gradeSign, _gradeExec are const -> they are initialized already with the constructor
    return *this;
}

Form::~Form() {
    std::cout << B_GREEN << "[ Form destructor has been called ]" << RESET << std::endl;
    std::cout << *this; 
}


std::string Form::getName() const {
    return this->_name;
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
    }
}


const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}


std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Name: "<<  f.getName() << std::endl
        << "Grade to sign: " << f.getGradeSign() << std::endl
        << "Grade to execute: " << f.getGradeExec() << std::endl;
    return os;
}