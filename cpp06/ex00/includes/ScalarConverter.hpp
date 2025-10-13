#ifndef ScalarConverter_hpp
#define ScalarConverter_hpp

#include <string>

class ScalarConverter {
private:
    ScalarConverter();//to make it un-instantiable
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

public:
    static void convert(std::string const input);
};

#endif