/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:46:19 by ryada             #+#    #+#             */
/*   Updated: 2025/08/21 17:51:21 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string newName, int startGrade): _name(newName), _grade(startGrade) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_grade = other._grade;
    }
}