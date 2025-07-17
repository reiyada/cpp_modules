#include "../includes/Zombie.hpp"
#include "../includes/Zombie.h"

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
    std::cout << "DESTRUCTOR: ";
    std::cout << this->name <<" has been destroyed" << std::endl;
}

void Zombie::setName(std::string newName)
{
    name = newName;
}

void Zombie::annouce()
{
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}