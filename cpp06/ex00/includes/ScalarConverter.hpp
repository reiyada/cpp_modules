#ifndef ScalarConverter_hpp
#define ScalarConverter_hpp

#include <string>

class ScalarConverter {
private:
    ScalarConverter();//to make it un-instantiable
    // ScalarConverter(const ScalarConverter& other);
    // ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

public:
    static char toChar(std::string const input);
    static int toInt(std::string const input);
    static float toFloat(std::string const input);
    static double toDouble(std::string const input);

    static void convert(std::string const input);
};

#endif