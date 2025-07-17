#include "../includes/Zombie.hpp"
#include "../includes/Zombie.h"

Zombie* newZombie(std::string name)
{
    Zombie* newZombie;

    newZombie = new Zombie(name);
    return newZombie;
}