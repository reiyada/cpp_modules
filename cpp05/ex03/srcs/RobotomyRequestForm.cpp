/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 08:42:05 by ryada             #+#    #+#             */
/*   Updated: 2025/10/29 13:30:41 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/define.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

RobotomyRequestForm::RobotomyRequestForm(): AForm::AForm("no name", 72, 45), _target("no target") {
    std::cout << B_LIME << "[ RobotomyRequestForm default constractor has been called ]" << RESET << std::endl;
    std::cout << *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string newTarget): AForm::AForm("no name", 72, 45), _target(newTarget) {
    std::cout << B_LIME << "[ RobotomyRequestForm constractor has been called ]" << RESET << std::endl;
    std::cout << *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string newTarget, std::string newName): AForm::AForm(newName, 72, 45), _target(newTarget) {
    std::cout << B_LIME << "[ RobotomyRequestForm constractor has been called ]" << RESET << std::endl;
    std::cout << *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), _target(other._target) {
    std::cout << B_LIME << "[ RobotomyRequestForm constractor(copy) has been called ]" << RESET << std::endl;
    std::cout << *this;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    std::cout << B_LIME << "[ RobotomyRequestForm operator has been assigned ]" << RESET << std::endl;
    std::cout << *this;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << B_LIME << "[ RobotomyRequestForm destructor has been called ]" << RESET << std::endl;
    std::cout << *this;
}

std::string RobotomyRequestForm::getTarget() const {
    return this->_target;
}

void RobotomyRequestForm::makeNoise() const{
    std::cout << B_LIME << "RobotomyRequestForm: " << this->getName() << " is making noise..." << std::endl
                << RESET << "BZZZZZZZZZZZZZT... VRRRRRRRRRRRR... DRRRRRRRRR" << std::endl;
}

void RobotomyRequestForm::inform() const{
    if (rand() % 2) {
        std::cout << B_LIME << "RobotomyRequestForm: " << this->getTarget()
                    << "has been robotomized successfully." << std::endl;
    }
    else {
        std::cout << B_LIME << "RobotomyRequestForm: " << this->getTarget()
                    << "has failed to get robotomized." << std::endl;
    }
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const{
    this->checkExec(executor);
    this->makeNoise();
    this->inform();
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& s) {
    os << "RobotomyRequestForm Name: "<<  s.getName() << std::endl
        << "Grade to sign: 72" << std::endl
        << "Grade to execute: 45" << std::endl
        << "Target: " << s.getTarget() << std::endl;
    return os;
}