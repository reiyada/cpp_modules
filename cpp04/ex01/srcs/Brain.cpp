/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:25:22 by ryada             #+#    #+#             */
/*   Updated: 2025/08/18 16:51:15 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"
#include "../includes/define.hpp"
#include <iostream>

Brain::Brain() {
    std::cout << B_CYAN << "Brain constructor has been called" << RESET << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << B_CYAN << "Brain constructor(copy) has been called" << RESET << std::endl;
    for (int i = 0; i < 100; i++) {
        this->_ideas[i] = other._ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->_ideas[i] = other._ideas[i];
        }
    }
    std::cout << B_CYAN << "Brain has been assinged" << RESET << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << B_CYAN << "Brain destructor has been called" << RESET << std::endl;
}

void Brain::setIdea(int index, std::string newIdea) {
    if (index >= 0 && index < 100)
        this->_ideas[index] = newIdea;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return this->_ideas[index];
    else
        return NULL;
}