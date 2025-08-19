/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:58:46 by ryada             #+#    #+#             */
/*   Updated: 2025/08/16 15:46:23 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGWrongANIMAL_HPP
#define WRONGWrongANIMAL_HPP

#include <string>

class WrongAnimal
{
protected:
    std::string _type;

public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    virtual ~WrongAnimal();

    virtual void makeSound() const;
    const std::string& getType() const;
};

#endif


///Polymorphism-> object-oriented programming (OOP) that
// allows objects of different classes to be treated as
// objects of a common base class