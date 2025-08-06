/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:18:13 by ryada             #+#    #+#             */
/*   Updated: 2025/08/06 11:33:02 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
#define Fixed_HPP

#include <string>

class Fixed
{
private:
    int _value;
    static const int _fractionalBits;

public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &ori);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
