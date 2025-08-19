/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:00:45 by ryada             #+#    #+#             */
/*   Updated: 2025/08/19 16:21:37 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/define.hpp"
#include <iostream>


Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice& other): AMateria(other) {}

Ice& Ice:: operator=(const Ice& other) {
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

Ice::~Ice() {}


AMateria* Ice::clone() const {
    Ice* cloneIce = new Ice(*this);
    return cloneIce;
}

void Ice::use(ICharacter& target) {
    std::cout << B_CYAN << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}