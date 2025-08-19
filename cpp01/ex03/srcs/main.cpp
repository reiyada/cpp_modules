/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:17:23 by ryada             #+#    #+#             */
/*   Updated: 2025/08/19 09:07:16 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

int main()
{
    {
        Weapon w1("bow & arrow");

        HumanA bob("Bob", w1);
        bob.attack();
        w1.setType("gun");
        bob.attack();
    }

    {
        Weapon w2("bow & arrow");

        HumanB jim("Jim");
        jim.setWeapon(w2);
        jim.attack();
        w2.setType("gun");
        jim.attack();
    }

    //Human B without setting a weapon
    {
        Weapon w3("bow & arrow");

        HumanB ken("Ken");
        // ken.setWeapon(w3);
        ken.attack();
        w3.setType("gun");
        ken.attack();
    }
    return 0;
}