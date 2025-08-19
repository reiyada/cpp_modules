/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:11:57 by ryada             #+#    #+#             */
/*   Updated: 2025/08/19 08:38:26 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include "../includes/Zombie.h"

//stack: pc makes the memory space for variables etc autmatically
//heap: makes the memory space dynamically by using new, malloc etc

int main()
{
    std::cout <<"<<Creating a zombie named Foo by calling newZombie>>" << std::endl;
    Zombie newZombie("Foo");
    newZombie.annouce();
    std::cout << std::endl;

    std::cout <<"<<Creating a zombie named Hoo by calling randomChump>>" << std::endl;
    randomChump("Hoo");

    return 0;
}