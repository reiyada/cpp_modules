/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 08:48:38 by ryada             #+#    #+#             */
/*   Updated: 2025/08/11 15:50:40 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _rawBits(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called" << std::endl;
    _rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    // std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" <<std::endl;
}

Fixed &Fixed::operator=(const Fixed &ori)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &ori)
        this->_rawBits = ori.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &other)const
{
    if (this->getRawBits() > other.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator<(const Fixed &other)const
{
    if (this->getRawBits() < other.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator>=(const Fixed &other)const
{
    if (this->getRawBits() >= other.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator<=(const Fixed &other)const
{
    if (this->getRawBits() <= other.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator==(const Fixed& other)const
{
    if (this->getRawBits() == other.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator!=(const Fixed& other)const
{
    if (this->getRawBits() != other.getRawBits())
        return true;
    else
        return false;
}

Fixed Fixed::operator+(const Fixed& other)const
{
    // Fixed temp;
    // temp.setRawBits(this->_rawBits + other._rawBits);
    // return temp;

    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other)const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other)const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other)const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
    _rawBits++;
    return *this;
}

Fixed& Fixed::operator--()
{
    _rawBits--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    _rawBits++;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    _rawBits--;
    return temp;
}

//gonna use the operators directly!
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    else
        return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    else
        return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    else
        return b;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
    this->_rawBits = raw;
}

float Fixed::toFloat(void) const
{
    return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _rawBits >> _fractionalBits;
}


std::ostream& operator<<(std::ostream& out, Fixed const& value) {
    out << value.toFloat();//use toFloat() to convert to float for printing
    return out;
}

