/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:34:37 by ryada             #+#    #+#             */
/*   Updated: 2025/08/30 10:22:43 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/define.hpp"
#include <iostream>

static void separator(const std::string& title) {
    std::cout << B_YELLOW <<std::endl << "============================== " << title << " ==============================" << RESET << std::endl;
}

int main()
{
    separator("Construction order");
    ClapTrap  c1("Clappy");
    ScavTrap  s1("Scavy");//should show ClapTrap-then-ScavTrap construction messages

    separator("Basic attacks (different messages)");
    c1.attack("training dummy 01");//ClapTrap message
    s1.attack("training dummy 02");//ScavTrap message (overridden)

    separator("Guard Gate");
    s1.guardGate();

    separator("Damage & repair");
    s1.takeDamage(30);//expect HP to drop
    s1.beRepaired(20);//expect HP to rise

    separator("No energy");
    for (int i = 0; i < 51; i++) {
        s1.attack("training dummy 03");
    }
    for (int i = 0; i < 10; i++) {
        c1.attack("training dummy 04");
    }

    separator("Copy Scavy into a new ScavTrap");
    ScavTrap s2(s1);//copy construct
    s2.attack("copy-target");

    separator("Copy Scavy into a new  ScavTrap / assing after construction");
    ScavTrap s3("Other");
    s3 = s1;//copy assign
    s3.attack("assign-target");

    separator("Virtual test");
    ClapTrap* s4 = new ScavTrap("Scat");
    s4->attack("TARGET");
    delete s4;

    separator("Destruction order");

    return 0;
}