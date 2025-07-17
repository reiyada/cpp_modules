#include "../includes/Weapon.hpp"
#include "../includes/HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name):name(name)
{

}

void HumanB::setWeapon(Weapon& w)
{
    weapon = &w;
}

void HumanB::attack()
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon!" << std::endl;;
}