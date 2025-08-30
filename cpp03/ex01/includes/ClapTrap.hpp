/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:44:24 by ryada             #+#    #+#             */
/*   Updated: 2025/08/30 10:21:30 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
protected://not reachable from the outside of the class but reachable from its child class
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;

    virtual std::string getType() const;//for bool noEnergy

public:
    ClapTrap(void);//for canonical form
    ClapTrap(std::string newName);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    virtual ~ClapTrap();

    void        attack(const std::string& target);
    void        takeDamage(unsigned int amount);
    void        beRepaired(unsigned int amount);

    bool        noEnergy();
};

#endif