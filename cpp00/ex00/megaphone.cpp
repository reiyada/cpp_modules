/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:29:47 by ryada             #+#    #+#             */
/*   Updated: 2025/08/05 14:29:54 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>//input/output data flow, like <stdio.h> in c
#include <cctype> //For std::toupper

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            for (int j = 0; argv[i][j]; j++)
            {
                std::cout << (char)std::toupper(argv[i][j]);
            }
        }
        std::cout << std::endl;
    }
    return 0;
}

//std:: << "hello" << std::endl; == printf("hello\n");
//std is namespace
//-> std::cout is for printing
//-> std::cin is for input
//-> std::endl is for a newline
//-> std::cerr is for an error msg


