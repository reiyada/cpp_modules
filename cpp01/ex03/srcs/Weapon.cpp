/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:17:26 by ryada             #+#    #+#             */
/*   Updated: 2025/08/19 08:51:37 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type):_type(type)
{
    
}

Weapon::~Weapon()
{
    
}

std::string Weapon::getType()
{
    return _type;
}

void Weapon::setType(std::string newType)
{
    _type = newType;
}