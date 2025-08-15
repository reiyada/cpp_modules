/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:50:20 by ryada             #+#    #+#             */
/*   Updated: 2025/08/13 17:28:09 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"
#include "../includes/define.hpp"
#include <iostream>

FragTrap::FragTrap(std::string newName): ClapTrap(newName) {
    std::cout << B_BLUE << "FragTrap constructor has been called" << RESET << "---> " << _name << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
};

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) {
    std::cout << B_GREEN << "FragTrap (copy) constructor has been called" << RESET << "----->" << this->getName() << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << B_GREEN << "FragTrap assined" << RESET << "----->" << this->getName() << std::endl;
    return *this;
}

FragTrap::~FragTrap(){
std::cout << B_BLUE << "FragTrap destructor has been called" << RESET << "---> " << _name << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << B_BLUE << "ClapTrap " << RESET
                << "<" << this->getName() <<  "> "
                << "is giving a high five!!" << std::endl;
}
