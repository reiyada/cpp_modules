/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:18:28 by ryada             #+#    #+#             */
/*   Updated: 2025/08/06 09:06:12 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"
#include <iostream>

void calComplain(Harl harl)
{
    std::cout << "<<DEBUG>>" << std::endl;
    harl.complain("DEBUG");
    std::cout << "<<INFO>>" << std::endl;
    harl.complain("INFO");
    std::cout << "<<WARNING>>" << std::endl;
    harl.complain("WARNING");
    std::cout << "<<ERROR>>" << std::endl;
    harl.complain("ERROR");
}

int main()
{
    Harl newHarl;

    calComplain(newHarl);
    return 0;
}