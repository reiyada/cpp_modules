/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:13:55 by ryada             #+#    #+#             */
/*   Updated: 2025/08/19 08:45:23 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include "../includes/Zombie.h"

int main()
{
    int count = 5;
    std::string newName = "Rei";
    Zombie* horde = zombieHorde(count, newName);

    std::cout <<"<< creating "<< count << " zombies >>" << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << "Zombie " << i << ": ";
        horde[i].annouce();
    }

    delete[] horde;//delete[] because we allocate with new[] --> this ensures the destructor is called once for each element in the array

    return 0;
}