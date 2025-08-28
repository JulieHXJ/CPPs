/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:37:02 by xhuang            #+#    #+#             */
/*   Updated: 2025/08/28 16:38:56 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

void subjExampleTest()
{
    std::cout << "Testing subj:" <<  std::endl;
    ScalarConverter::convert("0");
    ScalarConverter::convert("nan");
    ScalarConverter::convert("42.0f");
    std::cout << std::endl;
}

void charIntTest()
{
    std::cout << "Testing chars:" << std::endl;
    ScalarConverter::convert("a");
    ScalarConverter::convert("%");
    ScalarConverter::convert("");
    std::cout << std::endl;

    std::cout << "Testing ints:" << std::endl;
    ScalarConverter::convert("235");
    ScalarConverter::convert("-32532");
    ScalarConverter::convert("+32532");
    ScalarConverter::convert("325325423523525");
    ScalarConverter::convert("-3252352353523235");
    std::cout << std::endl;
}

void floatDoubleTest()
{
    std::cout << "Testing floats:" << std::endl;
    ScalarConverter::convert("325.068f");
    std::cout << std::endl;
    ScalarConverter::convert("2147483648.0f");
    std::cout << std::endl;
    ScalarConverter::convert("-2147483649.0f");
    std::cout << std::endl;
    ScalarConverter::convert("-34325.0563f");
    std::cout << std::endl;

    std::cout << "Testing doubles:" << std::endl;
    ScalarConverter::convert("235235.034");
    std::cout << std::endl;
    ScalarConverter::convert("-2147483649.0");
    std::cout << std::endl;
    ScalarConverter::convert("3.141592653589793");
    std::cout << std::endl;
    ScalarConverter::convert("nan");
    std::cout << std::endl;
    ScalarConverter::convert("+inf");
    std::cout << std::endl;
    ScalarConverter::convert("-inf");
}

int main ()
{
    subjExampleTest();
    charIntTest();
    floatDoubleTest();
    return 0;
}
