/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:24:40 by junjun            #+#    #+#             */
/*   Updated: 2025/08/28 16:43:43 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip> // std::setprecision, std::fixed
#include <limits> //for ovrerflow and underflow checks
#include <cstdlib> // std::atof, std::atoi strtod/strtof
#include <cctype> // for char - isprint, isdigit

static bool checkDouble(const std::string &input)
{
	if (input.empty())
		return false;
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

static bool checkInt(const std::string& input) {
    if (input.empty())
		return false;
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






		
//convert char/int/float to double
static bool toDouble(const std::string &input, double &d)
{
	// char
	if (input.size() == 1 && !std::isdigit(static_cast<unsigned char>(input[0])))
	{
		d = static_cast<double>(input[0]);
		return true;
	}
	
	//float
	if (input.size() >= 2 && input[input.size() - 1] == 'f')
	{
		std::string floatInput = input.substr(0, input.size() - 1);
		if (!checkDouble(floatInput))
			return false; // invalid float input
		char *endptr; // check conversion finished or not
		d = std::strtod(floatInput.c_str(), &endptr);
		return endptr && *endptr == '\0';
	}

	//double
	if (checkDouble(input))
	{
		char *endptr;
		d = std::strtod(input.c_str(), &endptr);
		return endptr && *endptr == '\0';
	}

	//int
	if (checkInt(input))
	{
		char *endptr;
		long l = std::strtol(input.c_str(), &endptr, 10);
		if (endptr && *endptr == '\0')
		{
			d = static_cast<double>(l);
			return true;
		}
	}
	return false;
}

// print functions
static void printChar(double c)
{
	int i = static_cast<int>(c);
	//check nan or inf	
	if (c != c // NaN
		|| c > 127.0 || c < 0.0)
	{
		std::cout << "char: impossible\n";
		return;
	}
	if (!isprint(static_cast<unsigned char>(i)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(i) << "'\n";
		
}

static void printInt(double i)
{
	if (i != i // NaN
		|| i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(i) << "\n";
}

static void printDouble(double d)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
}

static void printFloat(double f)
{
	if (f > static_cast<double>(std::numeric_limits<float>::max()) 
		|| f < static_cast<double>(-std::numeric_limits<float>::max()))
	{
		std::cout << "float: impossible\n";
		return;
	}
	float fval = static_cast<float>(f);
	std::cout << "float: " << std::fixed << std::setprecision(1) << fval << "f\n";
}

void ScalarConverter::convert(const std::string &input)
{
	// output message directly if nan inf or inff 
	if (input == "nan" || input == "+inf" || input == "-inf")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << input << "f\n";
		std::cout << "double: " << input << "\n";
		return;
	}
	if (input == "nanf" || input == "+inff" || input == "-inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << input << "\n";
		std::cout << "double: " << input.substr(0, input.length() - 1) << "\n"; // remove 'f'
		return;
	}

	// convert input to double
	double d;
	if (!toDouble(input, d))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
	}
	//print output message
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);	
}



/*
static bool			isChar(std::string);
		static bool			isDouble(std::string);
		static bool			isFloat(std::string);
		static bool			isInteger(std::string);
		static bool			isSpecial(std::string);

		static char			strToChar(std::string const &);
		static double		strToDouble(std::string const &);
		static float		strToFloat(std::string const &);
		static int			strToInteger(std::string const &);

		static void			displayDouble(double);
		static void			displayFloat(float);
		static void			displayInteger(int);
		static void			displayChar(char c);
		static void			displaySpecial(std::string const &);
		static void			displayImpossible(void);

		static std::string	trim(std::string const &);
		*/





		type getType(std::string input)
		{
			size_t sign = (input[0] == '+' || input[0] == '-') ? 1 : 0;
		
			if (input.length() == 1 && !std::isdigit(input[0]))
				return CHAR;
			else if (input.find_first_not_of("0123456789", sign) == std::string::npos)
				return INT;
			else if ((input.back() == 'f' && input.find_first_not_of("0123456789.f", sign) == std::string::npos)
						|| input == "-inff" || input == "+inff" || input == "nanf")
			{
				size_t first_dot = input.find('.');
				size_t last_dot = input.rfind('.');
				if (first_dot == last_dot || input == "-inff" || input == "+inff" || input == "nanf") 
					return FLOAT;
			}
			else if (input.find_first_not_of("0123456789.", sign) == std::string::npos
					|| input == "-inf" || input == "+inf" || input == "nan")
			{
				size_t first_dot = input.find('.');
				size_t last_dot = input.rfind('.');
				if (first_dot == last_dot || input == "-inf" || input == "+inf" || input == "nan")
					return DOUBLE;
			}
				return INVALID;
			}

		
		void allImp()
		{
			std::cout << "char: Impossible" << std::endl;
			std::cout << "int: Impossible" << std::endl;
			std::cout << "float: Impossible" << std::endl;
			std::cout << "double: Impossible" << std::endl;
		}
		
		
		bool intImpossible(double value)
		{
			return std::isnan(value) || std::isinf(value) ||
				   value < INT_MIN || value > INT_MAX;
		}


		
		void ScalarConverter::convert(std::string input)
		{
			if (input.empty())
			{
				std::cout << "Invalid input: empty string" << std::endl;
				return;
			}
			if (getType(input) == CHAR)
			{
				char output = input[0];
				printOutput(output);
			}
			else if (getType(input) == INT)
			{
				try
				{
					int output = std::stoi(input);
					printOutput(output);
				}
				catch(const std::exception& e)
				{
					allImp();
				}
			}
			else if (getType(input) == FLOAT)
			{
				try
				{
					float output = std::stof(input);
					printOutput(output);
				}
				catch(const std::exception& e)
				{
					allImp();
				}
			}
			else if (getType(input) == DOUBLE)
			{
				try
				{
					double output = std::stod(input);
					printOutput(output);
				}
				catch(const std::exception& e)
				{
					allImp();
				}
			}
			else
				std::cerr << "Error: Invalid input" << std::endl;
		}
		