/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:33:01 by ryada             #+#    #+#             */
/*   Updated: 2025/08/19 16:07:51 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(std::string const& type): _type(type) {}

AMateria::AMateria(const AMateria& other) {
    this->_type = other._type;
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other)
    {
        this->_type = other._type;
    }

    return *this;
}

AMateria::~AMateria() {}




std::string const& AMateria::getType() const {
    return this->_type;
}


void AMateria::use(ICharacter& target) {
    (void) target;
}

