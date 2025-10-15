#include "../includes/Serializer.hpp"
#include "../includes/define.hpp"
#include <iostream>

Serializer::Serializer() {
    std::cout << B_BLUE << "[ Serializer default constructor called ]" << RESET << std::endl;
}

Serializer::Serializer(const Serializer& other) {
    std::cout << B_BLUE << "[ Serializer copy constructor called ]" << RESET << std::endl;
    *this = other;
}

const Serializer Serializer::operator=(const Serializer& other) {
    std::cout << B_BLUE << "[ Serializer operator called ]" << RESET << std::endl;
    (void)other;
    return *this;
}

Serializer::~Serializer() {
    std::cout << B_BLUE << "[ Serializer destructor called ]" << RESET << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
    //Data* ptr = (e.g.,)0x7ffeefbff4d8
    //reinterpret_cast<uintptr_t> -> make it as an unsignined int
    //so now it is like 140732920867288
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
    //this is the opposite of serialize()
}