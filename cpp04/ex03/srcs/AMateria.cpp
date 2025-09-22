/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:33:01 by ryada             #+#    #+#             */
/*   Updated: 2025/09/20 12:09:32 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/define.hpp"
#include <iostream>

AMateria::AMateria(): _type("unknown type") {
    std::cout << B_BLUE << "[DEFAULT] Creating a new Material\n" << RESET;
}

AMateria::AMateria(std::string const& type): _type(type) {
    std::cout << B_BLUE << "Creating a new Material\n" << RESET;
}

AMateria::AMateria(const AMateria& other) {
    this->_type = other._type;
    std::cout << BLUE << "Copying " << this->_type << "\n" << RESET;
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other)
    {
        this->_type = other._type;
    }

    return *this;
}

AMateria::~AMateria() {
    std::cout << B_BLUE << "Destroying a Material type " << this->_type << std::endl << RESET;
}


std::string const& AMateria::getType() const {
    return this->_type;
}


void AMateria::use(ICharacter& target) {
    (void) target;
}

