/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:34:37 by ryada             #+#    #+#             */
/*   Updated: 2025/08/16 13:54:47 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"
#include "../includes/define.hpp"
#include <iostream>

static void separator(const std::string& title) {
    std::cout << B_YELLOW <<std::endl << "========== " << title << " ==========" << RESET << std::endl;
}

int main()
{
    separator("Construction order");
    ClapTrap    c1("Clappy");
    ScavTrap    s1("Scavy");//should not reinitialize
    FragTrap    f1("Frappy");//should not reinitialize
    DiamondTrap d1("Diam");

    separator("Basic attacks (different msg from Scavy)");
    c1.attack("training dummy 01");
    s1.attack("training dummy 02");
    f1.attack("training dummy 03");
    d1.attack("training dummy 04");

    separator("High Five special ability");
    f1.highFivesGuys();

    separator("Damage & repair logic");
    d1.takeDamage(30);//expect HP to drop
    d1.beRepaired(20);//expect HP to rise

    separator("Energy depletion test");
    for (int i = 0; i < 101; ++i)
    {
        d1.attack("training dummy 03");
    }

    separator("Copy Diam into a new DiamondTrap");
    DiamondTrap d2(d1);//copy construct
    d2.attack("copy-target");

    separator("Copy Diam into a new  DiamondTrap / assing after construction");
    DiamondTrap d3("FakeDiam");
    d3 = d1;//copy assign
    d3.attack("assign-target");

    separator("Virtual test");
    ClapTrap* s2 = new DiamondTrap("Diammmmmmmmmm");
    s2->attack("TARGET");
    delete s2;

    separator("Destruction order");
    return 0;
}