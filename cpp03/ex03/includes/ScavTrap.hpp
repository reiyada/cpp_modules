/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:50:24 by ryada             #+#    #+#             */
/*   Updated: 2025/08/30 09:03:01 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
public:
    ScavTrap(void);//for canonical form
    ScavTrap(std::string newName);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();

    void        attack(const std::string& target);

    void        guardGate();
};

#endif

//it needs to be like this;
//       ClapTrap
//        /    \
//  ScavTrap  FragTrap
//        \    /
//     DiamondTrap

//but without virtual, both Scav and Frag inherit their own separate copy of clap
//so when Diamond inherits from both, it ends up with two Clap subobjects like this;
// DiamondTrap
// ├── ScavTrap
// │   └── ClapTrap (1)
// └── FragTrap
//     └── ClapTrap (2)