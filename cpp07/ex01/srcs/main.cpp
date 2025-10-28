/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:26:44 by ryada             #+#    #+#             */
/*   Updated: 2025/10/28 17:00:19 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include "../includes/define.hpp"

template<typename T>
void printElement(const T& t) {
    std::cout << t << std::endl;
}

template<typename T>
void iterateElement(T& t) {
    t++;
    printElement(t);
}

template<typename T>
void addElement(T& t) {
    t += 'X';
    printElement(t);
}

void title(std::string str) {
    std::cout << B_YELLOW << "================= " << str << " =================" << RESET << std::endl;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"Hello", "I am Rei", "HAHAHA"};

    title("try iter() with printElemnt() for intArray");
    iter(intArray, 5, printElement<int>);

    title("try iter() with printElemnt() for strArray");
    iter(strArray, 3, printElement<std::string>);

    title("try iter() with iterateElement() for intArray");
    iter(intArray, 5, iterateElement<int>);

    title("try iter() with addElement() for strArray");
    iter(strArray, 3, addElement<std::string>);

    return 0;
}