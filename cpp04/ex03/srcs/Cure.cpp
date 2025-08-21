/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:54:41 by ryada             #+#    #+#             */
/*   Updated: 2025/08/21 17:20:25 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/define.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure& other): AMateria(other) {}

Cure& Cure:: operator=(const Cure& other) {
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

Cure::~Cure() {}


AMateria* Cure::clone() const {
    Cure* cloneCure = new Cure(*this);
    std::cout << GREEN << "Cloning Cure" << RESET << std::endl;
    return cloneCure;
}

void Cure::use(ICharacter& target) {
    std::cout << B_GREEN << "* heals " << target.getName() << "'s wonds *" << RESET << std::endl;
}