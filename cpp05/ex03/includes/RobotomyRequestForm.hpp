/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 08:29:26 by ryada             #+#    #+#             */
/*   Updated: 2025/09/22 08:31:51 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
    std::string _target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string newTarget);
    RobotomyRequestForm(std::string newTarget, std::string newName);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    std::string getTarget() const;

    void makeNoise() const;
    void inform() const;

    void execute(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& s);

#endif