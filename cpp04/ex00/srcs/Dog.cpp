/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:09:24 by ryada             #+#    #+#             */
/*   Updated: 2025/08/16 16:25:11 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/define.hpp"
#include <iostream>

Dog::Dog(): Animal() {
    _type = "Dog";
    std::cout << B_BLUE << "Dog constructor has been called" << RESET << std::endl;
}

Dog::Dog(const Dog& other): Animal(other) {
    std::cout << B_BLUE << "Dog constructor(copy) has been called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << B_BLUE << "Dog has been assinged" << RESET << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << B_BLUE << "Dog destructor has been called" << RESET << std::endl;
}

void Dog::makeSound() const {
    std::cout << B_BLUE << "🐶Woof Woof🐶" << RESET << std::endl;
}
