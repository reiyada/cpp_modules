/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:33:22 by ryada             #+#    #+#             */
/*   Updated: 2025/08/13 10:51:25 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point():x(0), y(0){
}

Point::Point(const float xValue, const float yValue): x(xValue), y(yValue){
}

Point::Point(Point& other): x(other.x), y(other.y){
}

Point& Point::operator=(const Point& ori){
    (void)ori;//we cant do anything since the member is const
    return *this;
}

Point::~Point() {}

Fixed   Point::getX() const
{
    return x;
}

Fixed   Point::getY() const
{
    return y;
}
