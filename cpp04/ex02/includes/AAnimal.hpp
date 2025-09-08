/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:58:46 by ryada             #+#    #+#             */
/*   Updated: 2025/08/19 09:58:31 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
protected:
    std::string _type;

public:
    AAnimal();
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal();

    const std::string& getType() const;

    virtual void makeSound() const = 0;
    //Pure virtual function ---> cannot be called by the base class
    //every subclass must provide this funcition
};

#endif


///Polymorphism-> object-oriented programming (OOP) that
// allows objects of different classes to be treated as
// objects of a common base class