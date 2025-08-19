/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:13:58 by ryada             #+#    #+#             */
/*   Updated: 2025/08/19 08:40:03 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include "../includes/Zombie.h"

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
    std::cout << "DESTRUCTOR: ";
    std::cout << this->_name <<" has been destroyed" << std::endl;
}

void Zombie::setName(std::string newName)
{
    _name = newName;
}

void Zombie::annouce()
{
    std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}