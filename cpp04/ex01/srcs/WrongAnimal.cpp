/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:09:24 by ryada             #+#    #+#             */
/*   Updated: 2025/08/16 15:46:56 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"
#include "../includes/define.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): _type("WrongAnimal") {
    std::cout << B_CYAN << "WrongAimal constructor has been called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): _type(other._type) {
    std::cout << B_CYAN << "WrongAimal constructor(copy) has been called" << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        this->_type = other._type;
    }
    std::cout << B_CYAN << "WrongAimal has been assinged" << RESET << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << B_CYAN << "WrongAimal destructor has been called" << RESET << std::endl;
    std::cout << std::endl;
}

void WrongAnimal::makeSound() const{
    std::cout << B_CYAN << "WrongAnimal noise" << RESET << std::endl;
}

const std::string& WrongAnimal::getType() const {
    return _type;
}