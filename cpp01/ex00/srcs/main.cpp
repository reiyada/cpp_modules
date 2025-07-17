#include "../includes/Zombie.hpp"
#include "../includes/Zombie.h"

//stack: pc makes the memory space for variables etc autmatically
//heap: makes the memory space dynamically by using new, malloc etc

int main()
{
    std::cout <<"<<Creating a zombie by calling newZombie>>" << std::endl;
    Zombie newZombie("Foo");
    newZombie.annouce();
    std::cout << std::endl;

    std::cout <<"<<Creating a zombie by calling randomChump>>" << std::endl;
    randomChump("Hoo");

    return 0;
}