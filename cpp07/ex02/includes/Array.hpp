/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:17:53 by ryada             #+#    #+#             */
/*   Updated: 2025/10/29 13:58:04 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Array_hpp
#define Array_hpp

#include <iostream>
#include <exception>

template<typename T>

class Array {
private:
    T* _arr;
    unsigned int _size;

public:
    Array(): _arr(NULL), _size(0) {};
    Array(unsigned int n): _arr(new T[n]), _size(n) {};
    Array(const Array& other): _arr(NULL), _size(0) {
        *this = other;
    };
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] this->_arr;
            this->_size = other._size;
            this->_arr = new T[_size];
            for (unsigned int i = 0; i < this->_size; i++)
                this->_arr[i] = other._arr[i];
        }
        return *this;
    };
    ~Array() {
        delete[] this->_arr;
    };

    T& operator[](unsigned int index) {
        if (index >= this->_size)
            throw std::out_of_range("Index is out of the range.");
        return this->_arr[index];
    };

    unsigned int size() const {
        return this->_size;
    };

};

#endif