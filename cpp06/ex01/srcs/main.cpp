/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:27:18 by ryada             #+#    #+#             */
/*   Updated: 2025/09/01 09:13:40 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/define.hpp"
#include <iostream>

void title(std::string title) {
    std::cout << B_YELLOW << "<<<<<<<<<<<<<<<<<<<< " << title << " >>>>>>>>>>>>>>>>>>>>" << std::endl;
}

void printData(const Data& data) {
    std::cout << B_MAGENTA << "[NAME] " << RESET << data.name << std::endl;
    std::cout << B_MAGENTA << "[AGE] " << RESET << data.age << std::endl;
}

int main() {
    title("Data init");
    Data data;
    data.name = "Rei";
    data.age = 26;
    printData(data);

    title("Try serialize()");
    uintptr_t rawAdr = Serializer::serialize(&data);
    std::cout << B_MAGENTA << "[Raw Address] " << RESET << rawAdr << std::endl;

    title("Try deserialize()");
    Data* ptr = Serializer::deserialize(rawAdr);
    std::cout << B_MAGENTA << "[Pointer] " << RESET << ptr << std::endl;

    return 0;
}