/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:34:37 by ryada             #+#    #+#             */
/*   Updated: 2025/08/30 09:52:39 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/define.hpp"
#include <iostream>

static void separator(const std::string& title) {
    std::cout << B_YELLOW <<std::endl << "============================== " << title << " ==============================" << RESET << std::endl;
}

int main()
{
    separator("Construction (without name)");
    ClapTrap ct0 = ClapTrap();

    separator("Construction (with name)");
    ClapTrap ct1("Rei");

    separator("Copy construction");
    ClapTrap clone(ct1);

    separator("Calling operator equal");
    ClapTrap equal("test");
    equal = ct1;

    separator("Attack");
    ct1.attack("Louis");

    separator("Take damage");
    ct1.takeDamage(2);

    separator("Repair");
    ct1.beRepaired(1);

    separator("No energy");
    for (int i = 0; i < 10; i++) {
        ct1.takeDamage(1);
    }

    separator("Destruction");//automatically call the destructor
    return 0;
}

// int main()
// {
//     ClapTrap ct1("Alpha");
//     ClapTrap ct2("Bravo");

//     ct1.attack("Bravo");
//     ct2.takeDamage(0);

//     ct2.beRepaired(5);
//     ct1.takeDamage(3);

//     ct1.attack("Bravo");
//     ct1.beRepaired(2);

//     for (int i = 0; i < 10; ++i) {
//         ct1.attack("Bravo");
//     }

//     ct1.attack("Bravo");

//     ClapTrap ct3(ct1);
//     ClapTrap ct4("Lemon");
//     ct4 = ct2;

//     return 0;
// }