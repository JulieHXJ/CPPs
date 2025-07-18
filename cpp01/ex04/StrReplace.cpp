/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strReplace.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:31:30 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/29 15:50:11 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StrReplace.hpp"
#include <fstream> //for ifstream and ofstream
#include <string>

StrReplace::StrReplace(const std::string &filename, const std::string &s1,
	const std::string &s2) : filename(filename), s1(s1), s2(s2)
{}

bool StrReplace::doReplace()
{
    // open infile(input file stream)
	std::ifstream inputfile(filename);
	if (!inputfile)
	{
        std::cerr << "Error: failed to open file " << filename << std::endl;
		return (false);
	}
    
    // check if s1 is null
    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return (false);
    }

	// create outputfile and (output file stream)
	std::ofstream outputfile(filename + ".replace");
	if (!outputfile)
	{
		std::cerr << "Error: failed to create output file." << std::endl;
		return (false);
	}

	// read line, replace and write to outputfile
    // find(): searching for string starting from given index, returns the index of the string starts, if not found returns npos
    // substr(): in c++ has two versions substr(pos, len) and substr(pos)
    
	std::string line;
    bool s1_found = false;
	while (std::getline(inputfile, line))
	{
		// for each line replace the string
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
            s1_found = true;
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
		}

		// write to file
		outputfile << line << "\n";
	}
    if (!s1_found)
    {
        std::cerr << "Error: s1 was not found in file." << std::endl;
        return false;
    }

	inputfile.close();
	outputfile.close();
    return (true);
}