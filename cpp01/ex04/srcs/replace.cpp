/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:18:31 by ryada             #+#    #+#             */
/*   Updated: 2025/08/19 09:12:23 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/replace.hpp"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

ReplaceFile::ReplaceFile(const std::string& filename, const std::string& s1, const std::string& s2)
    :_filename(filename), _s1(s1), _s2(s2) {}

ReplaceFile::~ReplaceFile() {}

bool ReplaceFile::process()
{
    std::ifstream infile(_filename.c_str()); //ifstream-> input file stream
    if (!infile)
    {
        std::cerr << "ERROR: cannot open input file." << std::endl;
        return false;
    }

    std::ofstream outfile((_filename + ".replace").c_str());
    if (!outfile)
    {
        std::cerr << "ERROR: cannot open output file." << std::endl;
        return false;
    }

    std::string line;
    bool first = true;
    while (std::getline(infile, line))
    {
        if (!first)
            outfile << std::endl;
        first = false;
        size_t pos = 0;
        while ((pos = line.find(_s1, pos)) != std::string::npos)
        {
            line.erase(pos, _s1.length());
            line.insert(pos, _s2);
            pos += _s2.length();
        }
        outfile << line;
    }
    return true;
}