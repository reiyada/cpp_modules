/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:58:08 by ryada             #+#    #+#             */
/*   Updated: 2025/10/28 15:53:49 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Identifyer.hpp"
#include <ctime>
#include <cstdlib>

void title(std::string title) {
    std::cout << B_YELLOW << "====================== " << title << " ======================" << RESET << std::endl;
}

int main() {
    srand(time(NULL));//to set the different time each time when we call main()
    title("calling generate()");
    std::cout << B_MAGENTA << "[b1] " << RESET;
    Base* b1 = generate();
    std::cout << B_MAGENTA << "[b2] " << RESET;
    Base* b2 = generate();

    title("calling identify(*)");
    std::cout << B_MAGENTA << "[b1] " << RESET;
    identify(b1);
    std::cout << B_MAGENTA << "[b2] " << RESET;
    identify(b2);

    title("calling identify(&)");
    std::cout << B_MAGENTA << "[b1] " << RESET;
    identify(*b1);
    std::cout << B_MAGENTA << "[b1] " << RESET;
    identify(*b2);

    delete b1;
    delete b2;
    return 0;
}