/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:50:20 by ryada             #+#    #+#             */
/*   Updated: 2025/08/16 11:24:14 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"
#include "../includes/ClapTrap.hpp"
#include "../includes/define.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap(), _name() {
    std::cout << B_CYAN << "DiamondTrap default constructor has been called" << RESET << "---> " << _name << std::endl;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string newName): ClapTrap(newName + "_clap_name") , ScavTrap(newName), FragTrap(newName), _name(newName){
    std::cout << B_CYAN << "DiamondTrap constructor has been called" << RESET << "---> " << _name << std::endl;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
};

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other) , ScavTrap(other), FragTrap(other), _name(other._name) {
    std::cout << B_CYAN << "DiamondTrap (copy) constructor has been called" << RESET << "----->" << this->_name<< std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        _name = other._name;
    }
    std::cout << B_CYAN << "DiamondTrap assined" << RESET << "----->" << this->_name<< std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap(){
std::cout << B_CYAN << "DiamondTrap destructor has been called" << RESET << "---> " << _name << std::endl;
}

void DiamondTrap::whoAmI() const
{
    std::cout << "I am " << B_CYAN << this->_name << " (Diamond name) " << RESET
                << "and " << B_GREEN << ClapTrap::_name << " (Calp name) " << RESET << std::endl;
}


std::string DiamondTrap::getType() const {
    return "DiamondTrap";
}
