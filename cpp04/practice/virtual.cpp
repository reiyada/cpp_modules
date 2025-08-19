#include <iostream>


class A {
public: 
    A* clone() const { std::cout << "Clone A\n"; return new A(*this);}
    virtual A* virtualClone() const { std::cout << "Clone A\n"; return new A(*this);}
};

class B: public A {
public: 
    B* clone() const { std::cout << "Clone B\n"; return new B(*this);}
    B* virtualClone() const { std::cout << "Clone B\n"; return new B(*this);}
};


int main()
{
    A* a = new B();
    std::cout << "Calling the normal clone" << std::endl;
    a->clone();

    std::cout << "Calling the virtual clone" << std::endl;
    a->virtualClone();
}