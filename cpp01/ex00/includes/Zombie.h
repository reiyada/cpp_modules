/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:11:45 by ryada             #+#    #+#             */
/*   Updated: 2025/08/05 17:11:46 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../includes/Zombie.hpp"
#include <iostream>
#include <string>

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif