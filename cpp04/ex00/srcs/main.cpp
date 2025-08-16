/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:34:37 by ryada             #+#    #+#             */
/*   Updated: 2025/08/16 16:43:40 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/define.hpp"
#include <iostream>

void    title(std::string title) {
    std::cout << B_YELLOW << "====================<< " << title << " >>====================" << RESET << std::endl;
}

int main()
{
    title("Construction");
    const Animal* a1 = new Animal();
    std::cout << std::endl;
    const Animal* a2 = new Dog();
    std::cout << std::endl;
    const Animal* a3 = new Cat();
    std::cout << std::endl;
    const WrongAnimal* w1 = new WrongAnimal();
    std::cout << std::endl;
    const WrongAnimal* w2 = new WrongCat();
    std::cout << std::endl;

    title("Type check");
    std::cout << "Normal Animal: " << a1->getType() << std::endl;
    std::cout << "Normal Dog: " << a2->getType() << std::endl;
    std::cout << "Normal Cat: " << a3->getType() << std::endl;
    std::cout << "Wrong Animal: " << w1->getType() << std::endl;
    std::cout << "Wrong Cat: " << w2->getType() << std::endl;

    title("Sound check");
    std::cout << "Normal Animal: ";
    a1->makeSound();
    std::cout << "Noral Dog: ";
    a2->makeSound();
    std::cout << "Normal Cat: ";
    a3->makeSound();
    std::cout << "Wrong Animal: ";
    w1->makeSound();
    std::cout << "Wrong Cat: ";
    w2->makeSound();

    title("Copy constructor");
    const Animal* copiedDog = new Dog(*(Dog*)a2);
    copiedDog->makeSound();
    std::cout << "Copied dog: " << copiedDog->getType() << std::endl;
    delete copiedDog;

    title("Assignment operator");
    Dog d1;
    Dog d2;
    d1 = d2;
    d2.makeSound();

    title("Array of animals");
    const Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();
    for (int i = 0; i < 4; i++) {
        animals[i]->makeSound();
    }
    for (int i = 0; i < 4; i++) {
        delete animals[i];
    }

    title("Destruction");
    delete a1;
    delete a2;
    delete a3;
    delete w1;
    delete w2;

    return 0;
}

// int main()
// {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();
//     return 0;
// }