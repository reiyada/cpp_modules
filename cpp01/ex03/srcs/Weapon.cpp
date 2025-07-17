#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type):type(type)
{
    
}

std::string Weapon::getType()
{
    return type;
}

void Weapon::setType(std::string newType)
{
    type = newType;
}