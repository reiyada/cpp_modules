/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:34:37 by ryada             #+#    #+#             */
/*   Updated: 2025/08/19 10:12:54 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/define.hpp"
#include <iostream>

void    title(std::string title) {
    std::cout << B_YELLOW << "====================<< " << title << " >>====================" << RESET << std::endl;
}

int main()
{
    // AAnimal *test = new AAnimal;
    title("Calling makeSound() from child classes");
    AAnimal* a1 = new Dog();
    a1->makeSound();
    AAnimal* a2 = new Cat();
    a2->makeSound();

    title("Calling makeSound() by using reference");
    AAnimal* a3 = new Dog();
    AAnimal& ref = *a3;
    ref.makeSound();

    title("Calling makeSound() from WrongAAnimal and WrongCat");
    WrongAnimal* a4 = new WrongCat();
    a4->makeSound();
    WrongAnimal a5;
    a5.makeSound();//this works for wrong Aanimal bc it is just a virtual function

    title("Destruction");
    delete a1;
    delete a2;
    delete a3;
    delete a4;

    return 0;
}
