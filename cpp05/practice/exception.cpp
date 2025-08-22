#include <iostream>
#include <string>

//https://www.youtube.com/watch?v=5nCXSDv6e4I
//https://cplusplus.com/reference/ostream/ostream/


class custom_exception: public std::exception
{
    virtual const char* what() const noexcept
    {
        return "Custom Exception\n";
    }
};


int main() {
    std::string word = "four";
    try 
    {
        // std::cout << word.at(4) << std::endl;//.at(i) prints the i-th character of the string?
        // int* array = new int[999999999999];
        throw custom_exception();

    }
    catch (std::out_of_range& e)//type of the exepction
    {
        //e ---> the object we pass in try
        std::cout << "First catch: " << e.what() << std::endl;
    }
    catch (std::bad_alloc& e)
    {
        std::cout << "Second catch: " << e.what() << std::endl;
    }
    return 0;
}

