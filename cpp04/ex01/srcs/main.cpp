/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:34:37 by ryada             #+#    #+#             */
/*   Updated: 2025/08/18 16:54:43 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
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
    title("Brain test");
    Animal* animals[10];
    for (int i = 0; i < 10; i++) {
        if (i < 5)
            animals[i] = new Dog;
        else
            animals[i] = new Cat;
        std::cout << std::endl;
    }
    std::cout << std::endl;

    title("Idea set");
    Dog d1;
    d1.getBrain()->setIdea(0, "Sleep all day");
    Cat c1;
    c1.getBrain()->setIdea(0, "Chase mouse");
    std::cout << "Dog's idea: " << d1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat's idea: " << c1.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    title("Copy constructor");
    Dog d2(d1);
    Cat c2(c1);
    std::cout << "Original dog's idea: " << d1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog's idea: " << d2.getBrain()->getIdea(0) << std::endl;
    std::cout << "Original cat's idea: " << c1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied cat's idea: " << c2.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    title("Assigned operator");
    Dog d3 = d1;
    Cat c3 = c1;
    std::cout << "Original dog's idea: " << d1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Assigned dog's idea: " << d3.getBrain()->getIdea(0) << std::endl;
    std::cout << "Original cat's idea: " << c1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Assigned cat's idea: " << c3.getBrain()->getIdea(0) << std::endl;


    title("Destruction");
    for (int i = 0; i < 10; i++) {
        delete animals[i];
    }

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