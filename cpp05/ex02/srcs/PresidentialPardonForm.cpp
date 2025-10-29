/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 08:42:05 by ryada             #+#    #+#             */
/*   Updated: 2025/09/22 09:28:57 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/define.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

PresidentialPardonForm::PresidentialPardonForm(): AForm::AForm("no name", 25, 5), _target("no target") {
    std::cout << B_BEIGE << "[ PresidentialPardonForm default constractor has been called ]" << RESET << std::endl;
    std::cout << *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string newTarget, std::string newName): AForm::AForm(newName, 25, 5), _target(newTarget) {
    std::cout << B_BEIGE << "[ PresidentialPardonForm constractor has been called ]" << RESET << std::endl;
    std::cout << *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), _target(other._target) {
    std::cout << B_BEIGE << "[ PresidentialPardonForm constractor(copy) has been called ]" << RESET << std::endl;
    std::cout << *this;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    std::cout << B_BEIGE << "[ PresidentialPardonForm operator has been assigned ]" << RESET << std::endl;
    std::cout << *this;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << B_BEIGE << "[ PresidentialPardonForm destructor has been called ]" << RESET << std::endl;
    std::cout << *this;
}

std::string PresidentialPardonForm::getTarget() const {
    return this->_target;
}

void PresidentialPardonForm::inform() const{
    std::cout << "Target: " << this->getTarget() << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const{
    this->checkExec(executor);
    this->inform();
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& s) {
    os << "PresidentialPardonForm Name: "<<  s.getName() << std::endl
        << "Grade to sign: 25" << std::endl
        << "Grade to execute: 5" << std::endl
        << "Target: " << s.getTarget() << std::endl;
    return os;
}