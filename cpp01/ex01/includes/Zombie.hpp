#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
    Zombie();
    ~Zombie();//destructor
    
    void setName(std::string newName);
    void annouce();

private:
    std::string name;
};

#endif