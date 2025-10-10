#include "../includes/ScalarConverter.hpp"
#include "../includes/define.hpp"
#include <cctype>
#include <cmath>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <limits> 

ScalarConverter::ScalarConverter() {
    std::cout << B_BLUE << "[ ScalarConverter default constructor called ]" << RESET << std::endl;
}

// ScalarConverter::ScalarConverter(const ScalarConverter& other) {
//     std::cout << B_BLUE << "[ ScalarConverter copy constructor called ]" << RESET << std::endl;
// }

// ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
//     std::cout << B_BLUE << "[ ScalarConverter operator called ]" << RESET << std::endl;
//     return *this;
// }

ScalarConverter::~ScalarConverter() {
    std::cout << B_BLUE << "[ ScalarConverter destructor called ]" << RESET << std::endl;
}

char ScalarConverter::toChar(std::string const input) {
    double dValue;

    //single char like 'a', non digit
    if (input.length() == 1  && !std::isdigit(input[0]))
        return input[0];

    //try to convert it into double
    try {
        dValue = strtod(input.c_str(), NULL);
    } catch (...) {
        throw std::runtime_error("impossible");
    }

    //check the range
    if (dValue < std::numeric_limits<char>::min() ||
        dValue > std::numeric_limits<char>::max() ||
        std::isnan(dValue))//nan = Not A Number
        throw std::runtime_error("impossible");
    
    char cResult = static_cast<char>(dValue);

    if (!std::isprint(cResult))
        throw  std::runtime_error("Non displayable");

    return cResult;
}

int ScalarConverter::toInt(const std::string input) {
    int iValue;
    double dValue;

    //single char 
    if (input.length() == 1 && std::isdigit(input[0])) {
        iValue = static_cast<int>(input[0]);
        return iValue;
    }

    //convert it into double
    dValue = strtod(input.c_str(), NULL);

    //check for nan and inf
    if (std::isnan(dValue) || std::isinf(dValue))
        throw std::runtime_error("impossible");

    //check the range
    if (dValue < std::numeric_limits<int>::min() ||
        dValue > std::numeric_limits<int>::max())
        throw std::runtime_error("impossible");
    
    iValue = static_cast<int>(dValue);
    return iValue;
}

void ScalarConverter::convert(const std::string input) {
    try {
        char c = toChar(input);
        std::cout << B_GREEN << "char: " << RESET
                    << "'" << c << "'" << std::endl;
    } catch (std::exception &e) {
        std::cout << B_GREEN << "char: " << RESET
                    << B_RED << e.what() << RESET << std::endl;
    }
    
    try {
        int i = toInt(input);
        std::cout << B_GREEN << "int: " << RESET
                    << i << std::endl;
    } catch (std::exception &e) {
        std::cout << B_GREEN << "int: " << RESET
                    << B_RED << e.what() << RESET << std::endl;
    }
}