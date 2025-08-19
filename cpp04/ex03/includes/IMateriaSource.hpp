/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:38:17 by ryada             #+#    #+#             */
/*   Updated: 2025/08/19 16:19:44 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
public:
    IMateriaSource() {}
    virtual ~IMateriaSource() {}

    virtual void learnMateria(AMateria* ptr) = 0;
    virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif