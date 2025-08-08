/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:24:22 by xhuang            #+#    #+#             */
/*   Updated: 2025/08/05 16:18:09 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    // Bureaucrat a("Julie", 151);//this will crash!
    try
    {
        Bureaucrat a("Julie", 151);//invaid creation
        // std::cout << a << std::endl;//this won't execute
    }
    catch(const std::exception& e)
    {
        std::cerr <<"\033[31m" << e.what() << "\033[0m" << std::endl;
    }

    try
    {
        Bureaucrat b("Cooper", 1);
        std::cout << b << std::endl;
        b.incrementGrade(); 
    }
    catch(const std::exception& e)
    {
        std::cerr <<"\033[31m" << e.what() << "\033[0m" << std::endl;
    }
    //loop
    Bureaucrat c("Seid", 100);
    std::cout << c << std::endl;
    while (1)
    {
        try
        {
            c.decrementGrade();
            std::cout << c << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr <<"\033[31m" << e.what() << "\033[0m" << std::endl;
            break;
        }
    }
    return 0;
}