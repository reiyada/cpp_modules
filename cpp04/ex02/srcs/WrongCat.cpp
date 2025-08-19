/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:09:24 by ryada             #+#    #+#             */
/*   Updated: 2025/08/16 15:48:30 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/define.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal() {
    _type = "WrongCat";
    std::cout << B_RED << "WrongCat constructor has been called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other) {
    std::cout << B_RED << "WrongCat constructor(copy) has been called" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    std::cout << B_RED << "WrongCat has been assinged" << RESET << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << B_RED << "WrongCat destructor has been called" << RESET << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << B_RED << "🐯Grrrrrrrrrr!!!🐯" << RESET << std::endl;
}