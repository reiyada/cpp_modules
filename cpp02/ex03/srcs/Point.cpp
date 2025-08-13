/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:33:22 by ryada             #+#    #+#             */
/*   Updated: 2025/08/11 16:41:36 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"
#include <iostream>

Point::Point():x(0), y(0){
}

Point::Point(const float xValue, const float yValue): x(xValue), y(yValue){
}

Point::Point(Point& other): x(other.x), y(other.y){
}

Point& Point::operator=(const Point& ori){

}