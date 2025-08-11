#include <iostream>

class Number
{
public:
    int n;
    Number(int set_n)
    {
        n = set_n;
    }
    Number operator+(const Number &numA)
    {
        // std::cout << "this->n:" << this->n << std::endl
        //             << "numA.n:" << numA.n << std::endl;
        return Number(this->n + numA.n);
    }
    bool operator==(const Number &numA)
    {
        if (this->n == numA.n)
            return true;
        else
            return false;
    }
};

int main()
{
    Number a(5);
    Number b(10);

    Number c = a + b;
    std::cout << "c.a:" << c.n << std::endl;

    if (a == c)
        std::cout << "a == c" << std::endl;
    else
        std::cout << "a != c" << std::endl;

    Number d(15);
    if (c == d)
        std::cout << "c == d" << std::endl;
    else
        std::cout << "c != d" << std::endl;
    return 0;
}