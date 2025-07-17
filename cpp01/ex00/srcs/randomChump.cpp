#include "../includes/Zombie.hpp"
#include "../includes/Zombie.h"

void randomChump(std::string name)
{
    Zombie newZombie(name);
    newZombie.annouce();
}