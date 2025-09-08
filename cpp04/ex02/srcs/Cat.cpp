/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:09:24 by ryada             #+#    #+#             */
/*   Updated: 2025/08/18 16:48:44 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/define.hpp"
#include <iostream>

Cat::Cat(): AAnimal() {
    _type = "Cat";
    this->_brain = new Brain;
    std::cout << B_MAGENTA << "Cat constructor has been called" << RESET << std::endl;
}

Cat::Cat(const Cat& other): AAnimal(other) {
    this->_brain = new Brain(*other._brain);
    std::cout << B_MAGENTA << "Cat constructor(copy) has been called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    std::cout << B_MAGENTA << "Cat has been assinged" << RESET << std::endl;
    return *this;
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << B_MAGENTA << "Cat destructor has been called" << RESET << std::endl;
}

void Cat::makeSound() const {
    std::cout << B_MAGENTA << "🐱Meow Meow🐱" << RESET << std::endl;
}

Brain* Cat::getBrain() {
    return this->_brain;
}

//*other._brain — This dereferences the pointer to get the actual Brain object.