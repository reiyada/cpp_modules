/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inheritance.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:19:33 by ryada             #+#    #+#             */
/*   Updated: 2025/08/13 16:41:27 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://www.youtube.com/watch?v=sswTE0u0r7g

#include <iostream>

class BaseClass1
{
public:
    int value;
    void function1()
    {
        std::cout << "Function1 BaseClass1" << std::endl;
    }
};

class BaseClass2
{
public:
    int value;
    void function1()
    {
        std::cout << "Function1 BaseClass2" << std::endl;
    }
};

class DrivedClass: public BaseClass1, public BaseClass2
{
public:
    //     void function1()
    // {
    //     std::cout << "Function1 DerivedClass" << std::endl;//this is override
    // }

    void function1()
    {
        BaseClass1::function1();
    }
};

int main()
{
    DrivedClass drived;
    drived.BaseClass1::function1();
    drived.BaseClass2::function1();
    drived.function1();

    drived.BaseClass1::value = 20;

    return 0;
}