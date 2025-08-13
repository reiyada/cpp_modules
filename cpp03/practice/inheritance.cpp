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

//https://www.youtube.com/watch?v=rJlJ8qqVm3k

#include <iostream>

class MenueItem//parent class
{
public:
    std::string _name;
    double _calories;

    void print()
    {
        std::cout << _name << " (" << _calories << " cal)" << std::endl;
    }
};

class Drink: public MenueItem//child class
{
};

int main()
{
    MenueItem rice;
    rice._name = "Rice";
    rice._calories = 100;
    rice.print();

    Drink   beer;
    beer._name = "Beer";
    beer._calories = 200;
    beer.print();

    MenueItem *ptr;
    ptr = &beer;
    ptr->print();
    return 0;
}