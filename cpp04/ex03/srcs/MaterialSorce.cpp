/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MaterialSorce.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:48:49 by ryada             #+#    #+#             */
/*   Updated: 2025/08/19 16:33:05 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        this->_storage[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const& other) {
    for (int i = 0; i < 4; i++) {
        if (other._storage[i])
            this->_storage[i] = other._storage[i]->clone();
        else
            this->_storage[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (this->_storage[i]) {
                delete this->_storage[i];
                this->_storage[i] = NULL;
            }
            if (other._storage[i])
                this->_storage[i] = other._storage[i]->clone();
        }
    }

    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (this->_storage[i])
            delete this->_storage[i];
    }
}

void MateriaSource::learnMateria(AMateria* ptr) {
    if (!ptr)
        return ;
    for (int i = 0; i < 4; i++) {
        if (this->_storage[i] == NULL) {
            this->_storage[i] = ptr->clone();
            delete ptr;
            return ;
        }
    }
    delete ptr;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    for (int i = 0; i < 4; i++) {
        if (this->_storage[i] && this->_storage[i]->getType() == type)
            return this->_storage[i]->clone();
    }
    return 0;
}