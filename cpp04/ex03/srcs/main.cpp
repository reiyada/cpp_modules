/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:55:49 by ryada             #+#    #+#             */
/*   Updated: 2025/08/19 17:30:41 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/define.hpp"
#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"
#include <iostream>

void    title(std::string title) {
    std::cout << B_YELLOW << "====================<< " << title << " >>====================" << RESET << std::endl;
}

int main()
{
    title("Create and learn materials");
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());//must be ignored since it's 5th material

    title("Create character and equip");
    ICharacter* me = new Character("me");
    AMateria* tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
}

// int main()
// {
//     title("test from the subject");
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     ICharacter* me = new Character("me");

//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);

//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);

//     delete bob;
//     delete me;
//     delete src;

//     return 0;
// }


//                 +------------------+
//                 |   AMateria       |   <-- Abstract base class
//                 |------------------|
//                 | - _type          |
//                 |------------------|
//                 | + getType()      |
//                 | + clone() = 0    | <-- Pure virtual
//                 | + use()          |
//                 +--------▲---------+
//                         |
//         +---------------+---------------+
//         |                               |
// +-------------+                 +-------------+
// |    Ice      |                 |    Cure     |
// +-------------+                 +-------------+
// | clone()      |  <-- returns   | clone()      |
// | use()        |      new Ice   | use()        |
// +-------------+                 +-------------+

//                 +----------------------+
//                 |     ICharacter       |   <-- Interface
//                 +----------------------+
//                 | + getName() = 0      |
//                 | + equip(m) = 0       |
//                 | + unequip(i) = 0     |
//                 | + use(i, target) = 0 |
//                 +----------▲-----------+
//                             |
//                     +---------------+
//                     |   Character   |   <-- Concrete class
//                     |---------------|
//                     | - _name       |
//                     | - _inventory  |
//                     |               |
//                     +---------------+

//                 +------------------------+
//                 |   IMateriaSource       |  <-- Interface
//                 +------------------------+
//                 | + learnMateria() = 0   |
//                 | + createMateria() = 0  |
//                 +----------▲-------------+
//                             |
//                 +--------------------+
//                 |   MateriaSource    |   <-- Concrete class
//                 |--------------------|
//                 | - _storage[4]      |
//                 +--------------------+
