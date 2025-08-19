/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:17:08 by ryada             #+#    #+#             */
/*   Updated: 2025/08/19 09:10:26 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();

    void attack();

private:
    std::string _name;
    Weapon& _weapon;
};


#endif