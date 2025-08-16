/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:09:24 by ryada             #+#    #+#             */
/*   Updated: 2025/08/16 16:25:16 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/define.hpp"
#include <iostream>

Cat::Cat(): Animal() {
    _type = "Cat";
    std::cout << B_MAGENTA << "Cat constructor has been called" << RESET << std::endl;
}

Cat::Cat(const Cat& other): Animal(other) {
    std::cout << B_MAGENTA << "Cat constructor(copy) has been called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << B_MAGENTA << "Cat has been assinged" << RESET << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << B_MAGENTA << "Cat destructor has been called" << RESET << std::endl;
}

void Cat::makeSound() const {
    std::cout << B_MAGENTA << "🐱Meow Meow🐱" << RESET << std::endl;
}