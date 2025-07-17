#include "../includes/Zombie.hpp"
#include "../includes/Zombie.h"

void Zombie::annouce()
{
    std::string zombieName;

    zombieName = this->name;
    std::cout << zombieName << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string newName)
{
    this->name = newName;
}

Zombie::~Zombie()
{
    std::cout << this->name <<" is destroyed" << std::endl;
}