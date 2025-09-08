/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:09:24 by ryada             #+#    #+#             */
/*   Updated: 2025/08/18 16:42:56 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/define.hpp"
#include <iostream>

Dog::Dog(): AAnimal() {
    _type = "Dog";
    this->_brain = new Brain;
    std::cout << B_BLUE << "Dog constructor has been called" << RESET << std::endl;
}

Dog::Dog(const Dog& other): AAnimal(other) {
    this->_brain = new Brain(*other._brain);
    std::cout << B_BLUE << "Dog constructor(copy) has been called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    std::cout << B_BLUE << "Dog has been assinged" << RESET << std::endl;
    return *this;
}

Dog::~Dog() {
    delete this->_brain;
    std::cout << B_BLUE << "Dog destructor has been called" << RESET << std::endl;
}

void Dog::makeSound() const {
    std::cout << B_BLUE << "🐶Woof Woof🐶" << RESET << std::endl;
}

Brain* Dog::getBrain() {
    return this->_brain;
}
