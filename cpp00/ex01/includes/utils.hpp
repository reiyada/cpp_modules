/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:32:18 by ryada             #+#    #+#             */
/*   Updated: 2025/08/05 15:32:19 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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