/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:55:49 by ryada             #+#    #+#             */
/*   Updated: 2025/08/21 17:16:11 by ryada            ###   ########.fr       */
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
    title("Create and Learn Materias");
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    title("Create Character and Equip");
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("unknown");
    if (!tmp) std::cout << "Tried to create unknown materia: failed \n";

    title("Create another Character");
    ICharacter* bob = new Character("bob");

    title("Use equipped materias");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(-1, *bob);
    me->use(42, *bob);

    title("Unequip and manage raw pointer");
    AMateria* toKeep = src->createMateria("cure");
    me->equip(toKeep);
    me->unequip(2);
    delete toKeep;

    title("Copy character deeply");
    Character copy = *(dynamic_cast<Character*>(me));
    copy.use(0, *bob);
    copy.use(1, *bob);

    title("Cleanup");
    delete src;
    delete me;
    delete bob;
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
