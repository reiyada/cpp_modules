/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:17:20 by ryada             #+#    #+#             */
/*   Updated: 2025/08/19 09:10:58 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name):_name(name)
{

}

HumanB::~HumanB()
{
    
}

void HumanB::setWeapon(Weapon& w)
{
    _weapon = &w;
}

void HumanB::attack()
{
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " has no weapon!" << std::endl;;
}