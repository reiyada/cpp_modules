/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:48:48 by ryada             #+#    #+#             */
/*   Updated: 2025/08/13 17:25:05 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/define.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string newName): _name(newName), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << B_GREEN << "ClapTrap constructor has been called" << RESET << "---> " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage){
    std::cout << B_GREEN << "ClapTrap (copy) constructor has been called" << RESET << "----->" << this->getName() << std::endl;
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
    std::cout << B_GREEN << "ClapTrap assined" << RESET << "----->" << this->getName() << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << B_GREEN << "ClapTrap destructor has been called" << RESET << "---> " << _name << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->noEnergy())
        return;
    this->_energyPoints--;

    std::cout << B_GREEN << "ClapTrap " << RESET
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

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->noEnergy())
        return;
    this->_hitPoints -= amount;

    std::cout << B_GREEN << "ClapTrap " << RESET
                << "<" << this->getName() <<  "> "
                << "received "
                << "<" << amount << "> "
                << "points of damage, now it has "
                << "<" << this->getHitPoints() << "> "
                << "hit points and "
                << "<" << this->getEnergyPoints() << "> "
                << "energy points! " << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->noEnergy())
        return;
    this->_hitPoints += amount;
    this->_energyPoints--;

    std::cout << B_GREEN << "ClapTrap " << RESET
                << "<" << this->getName() <<  "> "
                <<"cured "
                << "<" << amount << "> "
                << "points, now it has "
                << "<" << this->getHitPoints() << "> "
                << "hit points and "
                << "<" << this->getEnergyPoints() << "> "
                << "energy points! " << std::endl;
}

std::string ClapTrap::getName()
{
    return _name;
}

int ClapTrap::getHitPoints()
{
    return _hitPoints;
}

int ClapTrap::getEnergyPoints()
{
    return _energyPoints;
}

int ClapTrap::getAttackPoints()
{
    return _attackDamage;
}

bool    ClapTrap::noEnergy()
{
    if (this->getEnergyPoints() <= 0 || this->getHitPoints() <= 0)
    {
        std::cout << B_RED <<"<" << this->getName() <<  "> " << RESET
                    << "does not have points to make actions..."
                    << std::endl;
        return true;
    }
    return false;
}