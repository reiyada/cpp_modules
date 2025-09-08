/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:09:24 by ryada             #+#    #+#             */
/*   Updated: 2025/08/18 14:18:51 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"
#include "../includes/define.hpp"
#include <iostream>

AAnimal::AAnimal(): _type("AAnimal") {
    std::cout << B_GREEN << "Aimal constructor has been called" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& other): _type(other._type) {
    std::cout << B_GREEN << "Aimal constructor(copy) has been called" << RESET << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) {
        this->_type = other._type;
    }
    std::cout << B_GREEN << "Aimal has been assinged" << RESET << std::endl;
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << B_GREEN << "Aimal destructor has been called" << RESET << std::endl;
    std::cout << std::endl;
}

void AAnimal::makeSound() const{
    std::cout << B_GREEN << "AAnimal noise" << RESET << std::endl;
}

const std::string& AAnimal::getType() const {
    return _type;
}