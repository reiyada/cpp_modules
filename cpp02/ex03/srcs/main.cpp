/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:18:28 by ryada             #+#    #+#             */
/*   Updated: 2025/08/13 11:16:24 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"
#include <iostream>

int main() {
    //Test triangle
    Point a(0, 0);
    Point b(4, 0);
    Point c(0, 4);

    Point p1(1, 1);
    Point p2(5, 1);
    Point p3(2, 0);

    std::cout << "Point (1, 1) is inside triangle?: " << (bsp(a, b, c, p1) ? "Yes" : "No") << std::endl;
    std::cout << "Point (5, 1) is inside triangle?: " << (bsp(a, b, c, p2) ? "Yes" : "No") << std::endl;
    std::cout << "Point (2, 0) is inside triangle?: " << (bsp(a, b, c, p3) ? "Yes" : "No") << std::endl;

    return 0;
}


//https://www.youtube.com/watch?v=2gIxbTn7GSc

