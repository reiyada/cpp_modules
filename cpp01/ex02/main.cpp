/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:15:16 by ryada             #+#    #+#             */
/*   Updated: 2025/08/05 17:15:17 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

//A reference is an alias — another name for a variable.
//It must be initialized when declared.
//It cannot be null or changed to refer to another variable.

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    //Print memory addresses
    std::cout << "Memory address of brain    : " << &brain << std::endl;
    std::cout << "Memory address held by PTR : " << stringPTR << std::endl;
    std::cout << "Memory address held by REF : " << &stringREF << std::endl;

    //Print values
    std::cout << "Value of brain             : " << brain << std::endl;
    std::cout << "Value pointed by PTR       : " << *stringPTR << std::endl;
    std::cout << "Value referenced by REF    : " << stringREF << std::endl;
}