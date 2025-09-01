/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:38:06 by ryada             #+#    #+#             */
/*   Updated: 2025/09/01 10:43:49 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <string>

class Form;

class Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade;//1 --> highest; 150 --> lowest

public:
    Bureaucrat();
    Bureaucrat(const std::string newName, int startGrade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string getName() const;
    int         getGrade() const;

    void        incGrade();
    void        decGrade();

    void        signForm(Form& f);

    class GradeTooHighException: public std::exception
    {
    public:
        const char* what() const throw();//override
    };
    class GradeTooLowException: public std::exception
    {
    public:
        const char* what() const throw();//override
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif