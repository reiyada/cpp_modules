/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifyer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:46:25 by ryada             #+#    #+#             */
/*   Updated: 2025/10/28 15:55:49 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Identifyer.hpp"
#include "../includes/define.hpp"
#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <cstdlib>
#include <iostream>

Base* generate(void) {
    Base* result = NULL;
    int randomNum = rand();
    if (DEBUG_MODE)
        std::cout << B_MAGENTA << "DEBUG randomNUm: " << randomNum << RESET << std::endl;
    if (randomNum % 3 == 0) {
        result = new C;
        std::cout << B_BLUE << "Instantiates C" << RESET << std::endl;
    } else if (randomNum % 2 == 0) {
        result = new B;
        std::cout << B_BLUE << "Instantiates B" << RESET << std::endl;
    } else {
        result = new A;
        std::cout << B_BLUE << "Instantiates A" << RESET << std::endl;
    }
    return result;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))//same as (A*)p in C
        std::cout << B_BLUE << "Class type A" << RESET << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << B_BLUE << "Class type B" << RESET << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << B_BLUE << "Class type C" << RESET << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << B_BLUE << "Class type A" << RESET << std::endl;
        return;
    } catch (std::exception& e) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << B_BLUE << "Class type B" << RESET << std::endl;
        return;
    } catch (std::exception& e) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << B_BLUE << "Class type C" << RESET << std::endl;
        return;
    } catch (std::exception& e) {}
}