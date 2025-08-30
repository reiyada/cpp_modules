/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:48:48 by ryada             #+#    #+#             */
/*   Updated: 2025/08/30 10:28:41 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/define.hpp"
#include <iostream>

ClapTrap::ClapTrap(): _name() {
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << B_GREEN << "ClapTrap default constructor has been called -----> " << RESET << this->_name << std::endl;
}

ClapTrap::ClapTrap(std::string newName): _name(newName), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << B_GREEN << "ClapTrap constructor has been called -----> " << RESET << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << B_GREEN << "ClapTrap (copy) constructor has been called -----> " << RESET << this->_name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << B_GREEN << "ClapTrap assined -----> " << RESET << this->_name << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << B_GREEN << "ClapTrap destructor has been called -----> " << RESET << this->_name << std::endl;
}


void    ClapTrap::attack(const std::string& target)
{
    if (this->noEnergy())
        return;
    this->_energyPoints--;

    std::cout << B_GREEN << "ClapTrap " << RESET 
                << this->_name
                << " attacks "
                << target
                << ", causing "
                << this->_attackDamage
                << " points of damage, now it has "
                << this->_hitPoints
                << " hit points and "
                << this->_energyPoints
                << " energy points! " << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->noEnergy())
        return;
    this->_hitPoints -= amount;

    std::cout << B_GREEN << "ClapTrap " << RESET 
                << this->_name
                << " received "
                << amount
                << " points of damage, now it has "
                << this->_hitPoints
                << " hit points and "
                << this->_energyPoints
                << " energy points! " << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->noEnergy())
        return;
    this->_hitPoints += amount;
    this->_energyPoints--;

    std::cout << B_GREEN << "ClapTrap " << RESET 
                << this->_name
                <<" cured "
                << amount
                << " points, now it has "
                << this->_hitPoints
                << " hit points and "
                << this->_energyPoints
                << " energy points! " << std::endl;
}

bool    ClapTrap::noEnergy()
{
    if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
    {
        std::cout << B_RED << "ClapTrap "
                    << this->_name
                    << " does not have points to make actions..." << RESET 
                    << std::endl;
        return true;
    }
    return false;
}