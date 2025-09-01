/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:15:43 by junjun            #+#    #+#             */
/*   Updated: 2025/09/01 11:44:53 by junjun           ###   ########.fr       */
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

#endif // SCALARCONVERTER_HPP