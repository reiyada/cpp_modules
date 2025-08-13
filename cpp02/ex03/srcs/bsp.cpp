/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:50:49 by ryada             #+#    #+#             */
/*   Updated: 2025/08/13 11:06:23 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

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

    if (areaAB == 0 || areaBC == 0 || areaCA == 0)//edge case
        return false;

    bool posi = (areaAB > 0 || areaBC > 0 || areaCA > 0);
    bool nega = (areaAB < 0 || areaBC < 0 || areaCA < 0);
    
    if ((posi && nega) || (!posi && !nega))//if all area are positive or all are negative => inside
        return true;
    else
        return false;
}


//about bsp
///https://youtu.be/HYAgJN3x4GA?feature=shared