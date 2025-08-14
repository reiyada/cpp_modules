/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:50:20 by ryada             #+#    #+#             */
/*   Updated: 2025/08/13 17:28:09 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include "../includes/define.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string newName): ClapTrap(newName) {
    std::cout << B_MAGENTA << "ScavTrap constructor has been called" << RESET << "---> " << _name << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
};

ScavTrap::~ScavTrap(){
std::cout << B_MAGENTA << "ScavTrap destructor has been called" << RESET << "---> " << _name << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->noEnergy())
        return;
    this->_energyPoints--;

    std::cout << B_MAGENTA << "ScavTrap " << RESET
                << "<" << this->getName() <<  "> "
                << "attacks "
                << "<" << target << ">, "
                << "causing "
                << "<" << this->getAttackPoints() << "> "
                << "points of damage, now it has "
                << "<" << this->getHitPoints() << "> "
                << "hit points and "
                << "<" << this->getEnergyPoints() << "> "
                << "energy points! " << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << B_MAGENTA << "ScaTrap " << RESET
                << "<" << this->getName() <<  "> "
                << "is now on Gate keeper mode!" << std::endl;
}