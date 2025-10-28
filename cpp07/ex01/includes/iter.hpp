/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:26:19 by ryada             #+#    #+#             */
/*   Updated: 2025/10/28 16:49:03 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef iter_hpp
#define iter_hpp

#include <cstddef>
#include <iostream>
#include <string>

template<typename T>
void iter(T* array, const size_t length, void (*func)(T&)) { //void->bc it returns nothing, (T&) ->the function takes a reference to type T
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

template<typename T>
void iter(T* array, const size_t length, void (*func)(T const &)) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

#endif