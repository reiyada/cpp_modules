#include "../includes/ScalarConverter.hpp"
#include "../includes/define.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <limits> 
#include <iomanip> 

ScalarConverter::ScalarConverter() {
    // std::cout << B_BLUE << "[ ScalarConverter default constructor called ]" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    // std::cout << B_BLUE << "[ ScalarConverter copy constructor called ]" << RESET << std::endl;
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    // std::cout << B_BLUE << "[ ScalarConverter operator called ]" << RESET << std::endl;
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {
    // std::cout << B_BLUE << "[ ScalarConverter destructor called ]" << RESET << std::endl;
}

static char toChar(std::string const input) {
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

static int toInt(const std::string input) {
    int iValue;
    double dValue;

    //single char 
    if (input.length() == 1 && !std::isdigit(input[0])) {
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

//                      float       |       double
//Positive infinity     +inff       |       +inf
//Negative infinity     -inff       |       -inf
//Not A Number          nanf        |       nan

static float toFloat(std::string const input) {
    std::string temp = input;
    if (temp.length() > 1 && temp[temp.length() - 1] == 'f' && temp.find('.') != std::string::npos)
        temp.erase(temp.length() - 1);

    //if it is a single char and not digit
    if (input.length() == 1 && !std::isdigit(input[0]))
        return static_cast<float>(input[0]);

    //pseudo literals
    if (input == "-inff" || input == "-inf")
        return -std::numeric_limits<float>::infinity();
    if (input == "+inff" || input == "+inf")
        return std::numeric_limits<float>::infinity();
    if (input == "nanf" || input == "nan")
        return std::numeric_limits<float>::quiet_NaN();

    double dValue = std::strtod(temp.c_str(), NULL);

    //check the range
    if (dValue > std::numeric_limits<float>::max() ||
        dValue < -std::numeric_limits<float>::max())
        throw std::runtime_error("impossible");

    return static_cast<float>(dValue);
}

static double toDouble(std::string const input) {
//if it is a single char and not digit
    if (input.length() == 1 && !std::isdigit(input[0]))
        return static_cast<double>(input[0]);

    //pseudo literals
    if (input == "-inff" || input == "-inf")
        return -std::numeric_limits<double>::infinity();
    if (input == "+inff" || input == "+inf")
        return std::numeric_limits<double>::infinity();
    if (input == "nanf" || input == "nan")
        return -std::numeric_limits<double>::quiet_NaN();

    double dValue = std::strtod(input.c_str(), NULL);

    //check the range
    if (dValue > std::numeric_limits<double>::max() ||
        dValue < -std::numeric_limits<double>::max())
        throw std::runtime_error("impossible");

    return dValue;
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
    try {
        float f = toFloat(input);
        std::cout << B_GREEN << "float: " << RESET;
        if (std::isnan(f))
            std::cout << B_RED << "nanf" << RESET << std::endl;
        else if (std::isinf(f))
            std::cout << B_RED << (f < 0 ? "-inff" : "+inff") << RESET << std::endl;
        else
            std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    } catch (std::exception &e) {
        std::cout << B_GREEN << "float: " << RESET
                    << B_RED << e.what() << RESET << std::endl;
    }
    try {
        double d = toDouble(input);
        std::cout << B_GREEN << "double: " << RESET;
        if (std::isnan(d))
            std::cout << B_RED << "nan" << RESET << std::endl;
        else if (std::isinf(d))
            std::cout << B_RED << (d < 0 ? "-inf" : "+inf") << RESET << std::endl;
        else
            std::cout << std::fixed << std::setprecision(1) << d << std::endl;
    } catch (std::exception &e) {
        std::cout << B_GREEN << "double: " << RESET
                    << B_RED << e.what() << RESET << std::endl;
    }
}