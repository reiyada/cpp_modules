/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 08:29:26 by ryada             #+#    #+#             */
/*   Updated: 2025/09/22 08:31:51 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
    std::string _target;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string newTarget, std::string newName);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    std::string getTarget() const;

    void inform() const;

    void execute(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& s);

#endif