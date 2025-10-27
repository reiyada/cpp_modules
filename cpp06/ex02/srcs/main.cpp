/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:58:08 by ryada             #+#    #+#             */
/*   Updated: 2025/10/27 15:47:55 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Identifyer.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(NULL));//to set the different time each time when we call main()
    Base* b1 = generate();
    delete b1;
    return 0;
}