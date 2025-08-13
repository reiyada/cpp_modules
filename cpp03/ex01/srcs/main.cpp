/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:34:37 by ryada             #+#    #+#             */
/*   Updated: 2025/08/13 13:54:46 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main()
{
    // ClapTrap rei("Rei");
    // // ClapTrap louis("Louis");

    // rei.attack("Louis");
    // rei.takeDamage(3);
    // rei.takeDamage(3);
    // rei.takeDamage(3);
    // rei.beRepaired(5);
    // rei.attack("Louis");

    // return 0;

    ClapTrap ct1("Alpha");
    ClapTrap ct2("Bravo");

    ct1.attack("Bravo");
    ct2.takeDamage(0);  // Alpha's attack damage is 0 by default

    ct2.beRepaired(5);
    ct1.takeDamage(3);

    ct1.attack("Bravo");
    ct1.beRepaired(2);

    // Exhausting energy points
    for (int i = 0; i < 10; ++i) {
        ct1.attack("Bravo");
    }

    ct1.attack("Bravo");  // Should fail due to no energy left

    return 0;
}