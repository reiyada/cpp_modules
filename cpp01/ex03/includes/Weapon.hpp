#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
public:
    Weapon(std::string type);
    std::string getType();
    void setType(std::string newType);

private:
    std::string type;
};

#endif
