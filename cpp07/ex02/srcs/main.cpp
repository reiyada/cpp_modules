/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:17:25 by ryada             #+#    #+#             */
/*   Updated: 2025/10/29 14:24:57 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "../includes/Array.hpp"

void putTitle(std::string str) {
    std::cout << "============================= " << str << " =============================" << std::endl;
}

int main() {
    putTitle("Empty array");
    Array<int> empty;
    std::cout << "Size: " << empty.size() << std::endl;
    try {
        empty[0] = 42;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    putTitle("Array of ints");
    Array<int> intArr(5);
    for (unsigned int i = 0; i < intArr.size(); i++) 
        intArr[i] = i;
    for (unsigned int i = 0; i < intArr.size(); i++) 
        std::cout << "intArr[" << i << "]: " << intArr[i] << std::endl;
    std::cout << "Size: " << intArr.size() << std::endl;
    std::cout << std::endl;

    putTitle("Copy constructor");
    Array<int> copy(intArr);
    for (unsigned int i = 0; i < copy.size(); i++) 
        std::cout << "copy[" << i << "]: " << intArr[i] << std::endl;
    std::cout << "Size: " << copy.size() << std::endl;
    std::cout << std::endl;

    putTitle("Modify the copy");
    copy[0] = 99;
    for (unsigned int i = 0; i < copy.size(); i++) 
        std::cout << "copy[" << i << "]: " << intArr[i] << std::endl;
    std::cout << "Size: " << copy.size() << std::endl;
    for (unsigned int i = 0; i < intArr.size(); i++) 
        std::cout << "intArr[" << i << "]: " << intArr[i] << std::endl;
    std::cout << "Size: " << intArr.size() << std::endl;
    std::cout << std::endl;

    putTitle("Aiignment operator");
    Array<int> assign;
    assign = intArr;
    for (unsigned int i = 0; i < assign.size(); i++) 
        std::cout << "assign[" << i << "]: " << intArr[i] << std::endl;
    std::cout << "Size: " << copy.size() << std::endl;
    for (unsigned int i = 0; i < intArr.size(); i++) 
        std::cout << "intArr[" << i << "]: " << intArr[i] << std::endl;
    std::cout << "Size: " << intArr.size() << std::endl;
    std::cout << std::endl;

    putTitle("Out of the range");
    try {
        std::cout << intArr[6] << std::endl;
    } catch(std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}


// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }