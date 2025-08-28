/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:15:43 by junjun            #+#    #+#             */
/*   Updated: 2025/08/28 16:42:22 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
	// ScalarConverter() = delete; for c++11
	ScalarConverter();// private constructor to prevent instantiation
	ScalarConverter(const ScalarConverter&); 
	ScalarConverter& operator=(const ScalarConverter&);
	
public:
	static void convert(const std::string &input);
};


//helper
enum type {CHAR, INT, FLOAT, DOUBLE, INVALID};
type getType(std::string s);
void allImp();
bool intImpossible(double value);

template <typename T>
void printOutput(T output) 
{
    if (static_cast<int>(output) < 0 || static_cast<int>(output) > 127)
        std::cout << "char: Impossible" << std::endl;
    else if (std::isprint(static_cast<char>(output)))
        std::cout << "char: " << static_cast<char>(output) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (intImpossible(static_cast<double>(output)))
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(output) << std::endl;
    if (static_cast<float>(output) != static_cast<int>(output))
    std::cout << "float: " << std::fixed << std::setprecision(7) << static_cast<float>(output) << "f" << std::endl;
    else
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(output) << "f" << std::endl;
    if (static_cast<double>(output) != static_cast<int>(output))
    std::cout << "double: " << std::fixed << std::setprecision(16) << static_cast<double>(output) << std::endl;
    else
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(output) << std::endl;
}







#endif // SCALARCONVERTER_HPP