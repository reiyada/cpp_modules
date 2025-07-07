#ifndef UTILS_HPP
#define UTILS_HPP

#include <cctype>
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <string>
#include <cstdlib>

bool checkEmpty(const std::string& str);
bool isAlphaString(const std::string& str);
bool isDigitString(const std::string& str);
void    printUpTo10(const std::string& str);

#endif