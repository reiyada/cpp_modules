/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:50:20 by ryada             #+#    #+#             */
/*   Updated: 2025/08/16 12:39:36 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include "../includes/define.hpp"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap() {
    std::cout << B_MAGENTA << "ScavTrap default constructor has been called" << RESET << "---> " << _name << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(std::string newName): ClapTrap(newName) {
    std::cout << B_MAGENTA << "ScavTrap constructor has been called" << RESET << "---> " << _name << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {
    std::cout << B_MAGENTA << "ScavTrap (copy) constructor has been called" << RESET << "----->" << this->_name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << B_MAGENTA << "ScavTrap assined" << RESET << "----->" << this->_name << std::endl;
    return *this;
}

ScavTrap::~ScavTrap(){
std::cout << B_MAGENTA << "ScavTrap destructor has been called" << RESET << "---> " << _name << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << B_MAGENTA << "ScaTrap " << RESET
                << this->_name
                << " is now on Gate keeper mode!" << std::endl;
}

std::string ScavTrap::getType() const
{
    return "ScavTrap";
}