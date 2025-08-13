/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:34:37 by ryada             #+#    #+#             */
/*   Updated: 2025/08/13 17:22:58 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/define.hpp"


//to see the msg both from Scav and Clap
// int main()
// {
//     ScavTrap scav("Scav");
//     scav.attack("Bug");

//     return 0;
// }

//to see a Clap and a Scav
int main()
{
    ClapTrap rei("Rei");
    ScavTrap louis("Louis");

    rei.attack("Ramen");
    louis.attack("Pizza");

    return 0;
}