/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:12:01 by ryada             #+#    #+#             */
/*   Updated: 2025/08/05 17:12:02 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include "../includes/Zombie.h"

Zombie* newZombie(std::string name)
{
    Zombie* newZombie;

    newZombie = new Zombie(name);
    return newZombie;
}