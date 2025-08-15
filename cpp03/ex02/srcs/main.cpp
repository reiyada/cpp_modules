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
#include "../includes/FragTrap.hpp"
#include "../includes/define.hpp"
#include <iostream>

static void separator(const std::string& title) {
    std::cout << B_YELLOW <<std::endl << "========== " << title << " ==========" << RESET << std::endl;
}

int main()
{
    separator("Construction order");
    ClapTrap c1("Clappy");
    ScavTrap s1("Scavy");
    FragTrap f1("Frappy");

    separator("Basic attacks (different msg from Scavy)");
    c1.attack("training dummy 01");
    s1.attack("training dummy 02");
    f1.attack("training dummy 03");

    separator("High Five special ability");
    f1.highFivesGuys();

    separator("Damage & repair logic");
    f1.takeDamage(30);//expect HP to drop
    f1.beRepaired(20);//expect HP to rise

    separator("Energy depletion test");
    for (int i = 0; i < 101; ++i)
    {
        f1.attack("training dummy 03");
    }

    separator("Copy Frappy into a new FragTrap");
    FragTrap f2(f1);//copy construct
    f2.attack("copy-target");

    separator("Copy Frappy into a new  FragTrap / assing after construction");
    FragTrap f3("Fake Frappy");
    f3 = f1;//copy assign
    f3.attack("assign-target");

    separator("Destruction order");
    return 0;
}