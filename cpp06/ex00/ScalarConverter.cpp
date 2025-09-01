/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:24:40 by junjun            #+#    #+#             */
/*   Updated: 2025/09/01 12:11:06 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip> // std::setprecision, std::fixed
#include <limits> //for ovrerflow and underflow checks
#include <cstdlib> // std::atof, std::atoi strtod/strtof
#include <cctype> // for char - isprint, isdigit

enum type {
	CHAR, 
	INT, 
	FLOAT, 
	DOUBLE,
	PSEUDO_FLOAT,
	PSEUDO_DOUBLE, 
	INVALID};

static bool isDouble(const std::string &input)
{
	size_t i = 0;
	if (input[i] == '-' || input[i] == '+'){
		i++;
		if (i >= input.size()) return false;
	}
	bool hasDecimal = false;
	bool hasDigit = false;
	for (; i < input.size(); i++)
	{
		if (std::isdigit(static_cast<unsigned char>(input[i])))
			hasDigit = true;
		else if (input[i] == '.' && !hasDecimal)
			hasDecimal = true;
		else
			return false;
	}
	return hasDigit && hasDecimal;
}

static bool isInt(const std::string& input) {
	if (input.empty()) return false;
	size_t i = 0;
	if (input[i] == '-' || input[i] == '+'){
		i++;
		if (i >= input.size())
			return false; // no digits after sign
	}
	for (; i < input.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return false;
	}
	return true;
}

static type getType(const std::string &input){
	// output message directly if nan inf or inff 
	if (input == "nan" || input == "+inf" || input == "-inf")
		return PSEUDO_DOUBLE;
	if (input == "nanf" || input == "+inff" || input == "-inff")
		return PSEUDO_FLOAT;
	if (input.size() == 1 && !std::isdigit(static_cast<unsigned char>(input[0])))
		return CHAR;
	else if (isInt(input))
		return INT;
	else if (isDouble(input))
		return DOUBLE;
	else if (input.size() >= 2 && input[input.size() - 1] == 'f' && isDouble(input.substr(0, input.size() - 1)))
		return FLOAT;
	else
		return INVALID;
}

//printing functions
template <typename T>
static void printValues (T val)
{
	//char 
	if (static_cast<int>(val) < 0 || static_cast<int>(val) > 127) //out of char range
	{
		std::cout << "char: impossible\n";
	} else if (!std::isprint(static_cast<unsigned char>(val))){
		std::cout << "char: Non displayable\n";
	} else {
		std::cout << "char: '" << static_cast<char>(val) << "'\n";
	}
	//int
	double d = static_cast<double>(val);
	if (d != d || d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()))
	{
		std::cout << "int: impossible\n";
	} else {
		std::cout << "int: " << static_cast<int>(d) << "\n";
	}
	//float
	if (d > static_cast<double>(std::numeric_limits<float>::max()) || d < static_cast<double>(std::numeric_limits<float>::min()))
	{
		std::cout << "float: impossible\n";
	} else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f\n";
	}
	//double
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
}


// template <typename T>
// void printOutput(T output) 
// {
//     // if (static_cast<int>(output) < 0 || static_cast<int>(output) > 127)
//     //     std::cout << "char: Impossible" << std::endl;
//     // else if (std::isprint(static_cast<char>(output)))
//     //     std::cout << "char: " << static_cast<char>(output) << std::endl;
//     // else
//     //     std::cout << "char: Non displayable" << std::endl;

//     // if (intImpossible(static_cast<double>(output)))
//     //     std::cout << "int: Impossible" << std::endl;
//     // else
//     //     std::cout << "int: " << static_cast<int>(output) << std::endl;
//     if (static_cast<float>(output) != static_cast<int>(output))
//     std::cout << "float: " << std::fixed << std::setprecision(7) << static_cast<float>(output) << "f" << std::endl;
//     else
//     std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(output) << "f" << std::endl;
//     if (static_cast<double>(output) != static_cast<int>(output))
//     std::cout << "double: " << std::fixed << std::setprecision(16) << static_cast<double>(output) << std::endl;
//     else
//     std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(output) << std::endl;
// }

static void invalid()
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}

void ScalarConverter::convert(const std::string &input)
{
	
	double d = 0.0;

	if (input.empty())
	{
		std::cout << "Invalid input: empty string" << std::endl;
		return;
	}
	switch (getType(input))
	{
		case PSEUDO_FLOAT: {
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: " << input << "\n";
			std::cout << "double: " << input.substr(0, input.size() - 1) << "\n";
			return;
			
		}
		case PSEUDO_DOUBLE: {
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: " << input << "f\n";
			std::cout << "double: " << input << "\n";
			return;
			
		}
		case CHAR: {
			char src_c = input[0];
			printValues(src_c);
			return;
			
		}
		case INT: {
			char* end = 0; errno = 0;
            long l = std::strtol(input.c_str(), &end, 10);
            if (!end || *end != '\0' || errno == ERANGE ||
                l > std::numeric_limits<int>::max() ||
                l < std::numeric_limits<int>::min())
            {
				invalid();
                return;
            }
    		printValues(l);
			return;
			
		}
		case FLOAT: {
			std::string core = input.substr(0, input.size() - 1);//remove 'f'
			char* end = 0; errno = 0;
			double dd = std::strtod(core.c_str(), &end);
			if (!end || *end != '\0') { invalid(); return; }
			float f = static_cast<float>(dd);
			printValues(f);
			return;
		}
		case DOUBLE: {
			char* end = 0; errno = 0;
			d = std::strtod(input.c_str(), &end);
			if (!end || *end != '\0') { invalid(); return; }
			printValues(d);
			return;
		}
		default: {
			invalid();
			return;
		}
	}
}
