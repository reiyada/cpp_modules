/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:12:47 by ryada             #+#    #+#             */
/*   Updated: 2025/10/28 16:17:51 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef whatever_hpp
#define whatever_hpp

#include <iostream>

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T min(T& a, T& b) {
    return (a < b ? a : b);
}

template<typename T>
T max(T& a, T& b) {
    return (a > b ? a : b);
}

#endif