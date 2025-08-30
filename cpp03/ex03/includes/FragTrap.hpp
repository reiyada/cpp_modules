/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:50:24 by ryada             #+#    #+#             */
/*   Updated: 2025/08/30 09:02:49 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
#define FragTrap_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
public:
    FragTrap(void);//for canonical form
    FragTrap(std::string newName);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    void highFivesGuys(void);
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