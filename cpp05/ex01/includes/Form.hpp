/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:45:28 by ryada             #+#    #+#             */
/*   Updated: 2025/08/25 17:48:33 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Form
{
private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeSign;
    const int           _gradeExec;

public:
    Form();

};


#endif