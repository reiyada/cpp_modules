/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:18:13 by ryada             #+#    #+#             */
/*   Updated: 2025/08/11 15:40:56 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
#define Fixed_HPP

#include <string>

class Fixed
{
private:
    int _rawBits;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed(const int value);
    Fixed(const float value);

    ~Fixed();

    Fixed& operator=(const Fixed& ori);
    bool operator>(const Fixed& other)const;
    bool operator<(const Fixed& other)const;
    bool operator>=(const Fixed& other)const;
    bool operator<=(const Fixed& other)const;
    bool operator==(const Fixed& other)const;
    bool operator!=(const Fixed& other)const;
    Fixed operator+(const Fixed& other)const;
    Fixed operator-(const Fixed& other)const;
    Fixed operator*(const Fixed& other)const;
    Fixed operator/(const Fixed& other)const;
    Fixed& operator++();
    Fixed& operator--();
    Fixed operator++(int);//post
    Fixed operator--(int);//post

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, Fixed const& value);

#endif
