/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:45:28 by ryada             #+#    #+#             */
/*   Updated: 2025/09/01 10:43:51 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form
{
private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeSign;
    const int           _gradeExec;

public:
    Form();
    Form(std::string newName, int gradeSign, int gradeExec);
    Form(const Form& other);
    Form& operator=(const Form&other);
    ~Form();

    std::string         getName() const;
    bool                getSigned() const;
    int                 getGradeSign() const;
    int                 getGradeExec() const;

    void                beSigned(const Bureaucrat& b);

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

std::ostream& operator<<(std::ostream& os, const Form& f);



#endif