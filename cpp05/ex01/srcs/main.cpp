/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:27:18 by ryada             #+#    #+#             */
/*   Updated: 2025/08/26 17:56:51 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/define.hpp"
#include <iostream>

void title(std::string title) {
    std::cout << B_YELLOW << "<<<<<<<<<<<<<<<<<<<<" << title << ">>>>>>>>>>>>>>>>>>>>" << RESET << std::endl;
}

int main() {
    title("Construction");
    Bureaucrat* rei = new Bureaucrat("Rei", 50);
    Bureaucrat* reiYada = new Bureaucrat("Rei Yada", 60);
    Form* stage = new Form("Stage", 60, 70);
    Form* visa = new Form("Visa", 10, 80);
    try
    {
        Form* test1 = new Form("Test1", 0, 100);
        std::cout << "Reason: " << test1->getReason();//this is not printing
    }
    catch(const std::exception& e)
    {
        std::cerr << B_RED << e.what() << RESET << std::endl;
    }
    try
    {
        Form* test2 = new Form("Test2", 10, 160);
        std::cout << "Reason: " << test2->getReason();//this is not printing
    }
    catch(const std::exception& e)
    {
        std::cerr << B_RED << e.what() << RESET << std::endl;
    }

    title("Copy construction");
    Form* clone = new Form(*stage);

    title("Test to sign");
    rei->signForm(*stage);//maybe I can try to print the info inside of signForm()
    std::cout << "Has stage been signed?: ";
    (stage->getSigned() == true) ? (std::cout << "Yes"): (std::cout << "No");
    std::cout << std::endl;


    title("Grade too low to sign");
    try
    {
        reiYada->signForm(*visa);
    }
    catch (std::exception& e)
    {
        std::cerr << B_RED << e.what() << RESET << std::endl;
    }
    std::cout << "Has visa been signed?: ";
    (visa->getSigned() == true) ? (std::cout << "Yes"): (std::cout << "No");
    std::cout << std::endl;

    title("Destruction");
    delete rei;
    delete reiYada;
    delete clone;
    delete stage;
    delete visa;
    return 0;
}
