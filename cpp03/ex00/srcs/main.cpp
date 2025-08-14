/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:34:37 by ryada             #+#    #+#             */
/*   Updated: 2025/08/13 16:56:34 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main()
{
    ClapTrap ct1("Alpha");
    ClapTrap ct2("Bravo");

    ct1.attack("Bravo");
    ct2.takeDamage(0);

    ct2.beRepaired(5);
    ct1.takeDamage(3);

    ct1.attack("Bravo");
    ct1.beRepaired(2);

    for (int i = 0; i < 10; ++i) {
        ct1.attack("Bravo");
    }

    ct1.attack("Bravo");

    ClapTrap ct3(ct1);
    ClapTrap ct4("Lemon");
    ct4 = ct2;

    return 0;
}