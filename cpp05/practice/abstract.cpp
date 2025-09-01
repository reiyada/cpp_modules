#include <iostream>

// https://www.youtube.com/watch?v=wE0_F4LpGVc
// https://www.geeksforgeeks.org/cpp/pure-virtual-functions-and-abstract-classes/


//Abstract class: it must have at least one pure virtual function
//we cannot make an instance of an abstract class
//All the drived class needs to override the pure virtual member function of the abstract class
class Shape
{
public:
    virtual double area() = 0;//PURE VIRTUAL FUNCTION
};

class Square: public Shape
{
private:
    double _side;

public:
    Square(double newSide): _side(newSide) {}
    double area() {
        return this->_side * this->_side;
    }
};

class Triangle: public Shape
{
private:
    double _base;
    double _height;

public:
    Triangle(double newBase, double newheight): _base(newBase), _height(newheight) {}
    double area() {
        return this->_base * this->_height / 2;
    }
};

int main() {
    // Shape shape;//WE CANNOT DO THIS
    Shape* shapes[] {
        new Square(5),
        new Triangle(2, 5),
        new Square(10),
        new Triangle(3, 4),
    };
    for(int i = 0; i < 4; i++) {
        std::cout << "Shape" << i << ": " << shapes[i]->area() << std::endl;
    }
    return 0;
}