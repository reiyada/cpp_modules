#include <iostream>
#include <string>

class Rectangle
{
private:
    double length;
    double width;
    double area()
    {
        return length * width;
    }

public:
    void set_dimensions(double l, double w)
    {
        length = l;
        width = w;
    }
    void print_area()
    {
        std::cout << "Area: " << area() << std::endl;
    }
    double perimeter();
};

double Rectangle::perimeter()
{
    return (2 * (length + width));
}

int main()
{
    Rectangle rectangle1;
    rectangle1.set_dimensions(10,20);
    std::cout << "Perimeter: " << rectangle1.perimeter() << std::endl;
    rectangle1.print_area();
    return 0;
}