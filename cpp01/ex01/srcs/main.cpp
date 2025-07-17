#include "../includes/Zombie.hpp"
#include "../includes/Zombie.h"


int main()
{
    int count = 7;
    std::string newName = "Rei";
    Zombie* horde = zombieHorde(count, newName);

    std::cout <<"<< creating "<< count << " zombies >>" << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << "Zombie " << i << ": ";
        horde[i].annouce();
    }
    delete[] horde;
    return 0;
}