/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:50:24 by ryada             #+#    #+#             */
/*   Updated: 2025/08/30 09:02:30 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
    std::string _name;

public:
    DiamondTrap(void);//for canonical form
    DiamondTrap(std::string newName);
    explicit DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

    using ScavTrap::attack;

    void whoAmI() const;
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

