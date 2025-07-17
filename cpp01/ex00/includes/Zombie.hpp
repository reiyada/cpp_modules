#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
    Zombie(std::string newName);//constructor
    ~Zombie();//destructor
    void annouce();

private:
    std::string name;
};

#endif