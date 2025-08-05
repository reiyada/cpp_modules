/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:12:07 by ryada             #+#    #+#             */
/*   Updated: 2025/08/05 17:12:07 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include "../includes/Zombie.h"

void Zombie::annouce()
{
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string newName)
{
    this->name = newName;
}

Zombie::~Zombie()
{
    std::cout << "DESTRUCTOR: ";
    std::cout << this->name <<" has been destroyed" << std::endl;
}