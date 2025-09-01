/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:02:34 by ryada             #+#    #+#             */
/*   Updated: 2025/09/01 15:02:37 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm
{
private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeSign;
    const int           _gradeExec;

public:
    AForm();
    AForm(std::string newName, int gradeSign, int gradeExec);
    AForm(const AForm& other);
    AForm& operator=(const AForm&other);
    ~AForm();

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

std::ostream& operator<<(std::ostream& os, const AForm& f);



#endif