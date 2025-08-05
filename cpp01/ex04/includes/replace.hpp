/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:18:13 by ryada             #+#    #+#             */
/*   Updated: 2025/08/05 17:18:16 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>

class ReplaceFile
{
private:
    std::string _filename;
    std::string _s1;
    std::string _s2;

public:
    ReplaceFile(const std::string& filename, const std::string& s1, const std::string& s2);
    //use reference to avoid copying the strings
    bool process();
};

#endif
