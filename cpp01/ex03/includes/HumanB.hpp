/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:17:11 by ryada             #+#    #+#             */
/*   Updated: 2025/08/05 17:17:12 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
public:
    HumanB(std::string name);
    void setWeapon(Weapon& w);
    void attack();

private:
    std::string name;
    Weapon* weapon;//reference cannot be null so we use a pointer for B incase it does not have weapons
};


#endif