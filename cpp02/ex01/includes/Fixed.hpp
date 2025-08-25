/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:18:13 by ryada             #+#    #+#             */
/*   Updated: 2025/08/06 13:06:07 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
#define Fixed_HPP

#include <iostream>

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
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, Fixed const& value);

#endif
