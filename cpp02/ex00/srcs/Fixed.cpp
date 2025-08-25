/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 08:48:38 by ryada             #+#    #+#             */
/*   Updated: 2025/08/06 11:44:30 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

//A special constructor used
//when a new object is created as a copy of an existing object
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& ori)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &ori)
        this->_value = ori.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" <<std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}


