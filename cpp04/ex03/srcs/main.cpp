/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:55:49 by ryada             #+#    #+#             */
/*   Updated: 2025/09/15 09:58:53 by ryada            ###   ########.fr       */
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
    title("Create and Learn Materias (try to learn more than 4 materials)");
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
    tmp = src->createMateria("unknown");//returns NULL
    if (!tmp) std::cout << B_RED << "Tried to create unknown materia: failed \n" << RESET;

    title("Create another Character");
    ICharacter* target = new Character("target");

    title("Use equipped materias");
    me->use(0, *target);
    me->use(1, *target);
    me->use(2, *target);//not equiped in the index 2
    me->use(-1, *target);//invalid index
    me->use(42, *target);//invalid index

    title("Unequip and manage raw pointer");
    AMateria* toKeep = src->createMateria("cure");
    me->equip(toKeep);
    me->unequip(2);
    delete toKeep;

    title("Copy character deeply");
    Character copy = *(dynamic_cast<Character*>(me));//a cast operator that converts data from one type to another type at runtime
    copy.use(0, *target);
    copy.use(1, *target);

    title("Cleanup");
    std::cout << "----- delete src -----" << std::endl;
    delete src;
    std::cout << "----- delete me -----" << std::endl;
    delete me;
    std::cout << "----- delete target -----" << std::endl;
    delete target;
    std::cout << "----- delete copy(me) -----" <<std::endl;
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

//     ICharacter* target = new Character("target");
//     me->use(0, *target);
//     me->use(1, *target);

//     delete target;
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
