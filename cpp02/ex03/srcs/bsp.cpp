/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:50:49 by ryada             #+#    #+#             */
/*   Updated: 2025/08/25 14:31:39 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

// positive: counter-clockwise rotation => "left turn"
// negative: clockwise => "right turn"
// zero: vectors are aligned (on the same line) => edge case
Fixed areaSign(Point const& a, Point const& b, Point const& c)
{
    Fixed ab_x = b.getX() - a.getX();
    Fixed ab_y = b.getY() - a.getY();
    Fixed ac_x = c.getX() - a.getX();
    Fixed ac_y = c.getY() - a.getY();

    Fixed area = (ab_x * ac_y) - (ab_y * ac_x);
    return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaAB = areaSign(point, a, b);
    Fixed areaBC = areaSign(point, b, c);
    Fixed areaCA = areaSign(point, c, a);

    if (areaAB == Fixed(0) || areaBC == Fixed(0) || areaCA == Fixed(0))//edge case
        return false;

    bool posi = (areaAB > Fixed(0) || areaBC > Fixed(0) || areaCA > Fixed(0));
    bool nega = (areaAB < Fixed(0) || areaBC < Fixed(0) || areaCA < Fixed(0));
    
    //if all area are positive or all are negative => inside
    //if signs are mized => outside
    //if signs are the same => inside
    return !(posi && nega);
}


//about bsp
///https://youtu.be/HYAgJN3x4GA?feature=shared