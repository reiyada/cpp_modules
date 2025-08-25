/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:18:28 by ryada             #+#    #+#             */
/*   Updated: 2025/08/11 15:55:02 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main( void ) {

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}

// //test min and max
// int main() {
//     //when both arguments are non-const, we call non-const overload
//     Fixed a;
//     Fixed b;
//     Fixed& r1 = Fixed::min(a, b);

//     //If any argument is const, we call const overload
//     const Fixed c;
//     Fixed d;
//     const Fixed& r2 = Fixed::max(c, d);

//     //if any argument is a temporary, we call the const overload
//     Fixed e;
//     Fixed r3 = Fixed::min(e, Fixed(2));

//     //Both arguments are const, we call const
//     const Fixed f;
//     const Fixed g;
//     const Fixed& r4 = Fixed::max(f, g);

//     (void)r1;
//     (void)r2;
//     (void)r3;
//     (void)r4;

//     return 0;
// }


