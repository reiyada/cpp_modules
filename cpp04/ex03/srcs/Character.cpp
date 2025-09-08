/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:10:53 by ryada             #+#    #+#             */
/*   Updated: 2025/08/19 16:27:23 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(std::string const& name): _name(name) {
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
}

Character::Character(const Character& other) {
    this->_name = other._name;
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone();
    }
}

Character& Character::operator=(const Character& other){
    if (this != &other) {
        this->_name = other._name;
    }
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i]) {
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone();
    }

    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i]) 
            delete this->_inventory[i];
    }
}


std::string const& Character::getName() const {
    return this->_name;
}

void Character::equip(AMateria* m) {
    if (!m)
        throw std::bad_alloc() ;

    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i] == m)
            return ;
    }

    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i] == NULL) {
            this->_inventory[i] = m->clone();
            return ;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3)
        return ;//use throw
    this->_inventory[idx] = NULL; 
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx > 3)
        return ;
    if (this->_inventory[idx])
        this->_inventory[idx]->use(target);
}