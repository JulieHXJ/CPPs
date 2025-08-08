/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:24:22 by xhuang            #+#    #+#             */
/*   Updated: 2025/08/05 18:10:55 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    //invalid Form creation tests
    std::cout << "----TEST 1----" << std::endl;
    try
    {
        Form wrongForm("High Form", 0, 30); 
    }
    catch(const std::exception& e)
    {
        std::cerr <<"\033[31m" << e.what() << "\033[0m" << std::endl;
    }
    try
    {
        Form wrongForm("Low Form", 150, 300); 
    }
    catch(const std::exception& e)
    {
        std::cerr <<"\033[31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "----TEST 2----" << std::endl;
    try
    {
        Bureaucrat a("Julie", 50);// valid grade
        Bureaucrat b("Cooper", 100);//grade too low
        Form f1("Mid-term Exam", 60, 30);
        Form f2 = f1;

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << "Form 1 - " << f1 << std::endl;
        std::cout << "Form 2 - " << f2 << std::endl;

        try
        {
            a.signForm(f1);
            std::cout << "Form 1 - " << f1 << std::endl;//change isSigned status
        }
        catch(const std::exception& e)
        {
            std::cerr <<"\033[31m" << e.what() << "\033[0m" << std::endl;
        }
        try
        {
            b.signForm(f2);
            std::cout << "Form 2 - " << f2 << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr <<"\033[31m" << e.what() << "\033[0m" << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr <<"\033[31m" << e.what() << "\033[0m" << std::endl;
    }

    return 0;
}
