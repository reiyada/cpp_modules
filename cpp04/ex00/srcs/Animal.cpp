/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:09:24 by ryada             #+#    #+#             */
/*   Updated: 2025/08/16 16:37:33 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/define.hpp"
#include <iostream>

Animal::Animal(): _type("Animal") {
    std::cout << B_GREEN << "Aimal constructor has been called" << RESET << std::endl;
}

Animal::Animal(const Animal& other): _type(other._type) {
    std::cout << B_GREEN << "Aimal constructor(copy) has been called" << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        this->_type = other._type;
    }
    std::cout << B_GREEN << "Aimal has been assinged" << RESET << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << B_GREEN << "Aimal destructor has been called" << RESET << std::endl;
    std::cout << std::endl;
}

void Animal::makeSound() const{
    std::cout << B_GREEN << "Animal noise" << RESET << std::endl;
}

const std::string& Animal::getType() const {
    return _type;
}