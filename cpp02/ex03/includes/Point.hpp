/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:19:02 by ryada             #+#    #+#             */
/*   Updated: 2025/08/13 08:03:49 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <string>

class Point
{
private:
    const Fixed x;
    const Fixed y;

public:
    Point();
    Point(const float a, const float b);
    Point(Point& other);
    Point& operator=(const Point& ori);
    ~Point();
};


#endif