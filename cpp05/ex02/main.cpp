/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:24:22 by xhuang            #+#    #+#             */
/*   Updated: 2025/08/14 17:26:31 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib> 
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL)); // seed once for the whole program（for random in robotomy）
    
    try
    {
        std::cout << "----Bureaucrat INIT----" << std::endl;
        Bureaucrat top("top", 1); //can sign and execute
        Bureaucrat okay("okay", 40); // > 5 
        Bureaucrat low("low", 100); // < 145
        Bureaucrat fail("fail", 150); //cannot do anything
        std::cout << fail << "\n" << low << "\n" << okay << "\n" << top << std::endl;
        
        
        std::cout << "----Test1 ShrubberyCreationForm----" << std::endl;
        ShrubberyCreationForm shrub("home");         // sign 145, exec 137
        std::cout << shrub << std::endl;
        
        fail.signForm(shrub);//fail
        top.executeForm(shrub);//without signing
        low.signForm(shrub);//ok
        low.executeForm(shrub);//ok
        std::cout << shrub << std::endl;
        
        std::cout << "----Test2 RobotomyRequestForm----" << std::endl;
        RobotomyRequestForm robo("Bender");          // sign 72,  exec 45
        std::cout << robo << std::endl;
        
        low.signForm(robo);//fail
        okay.signForm(robo);
        for (int i = 0; i < 5; i++)
        {
            okay.executeForm(robo);
        }
        std::cout << robo << std::endl;
        
        std::cout << "----Test3 PresidentialPardonForm----" << std::endl;
        PresidentialPardonForm pardon("Arthur");     // sign 25,  exec 5
        std::cout << pardon << std::endl;
        
        okay.signForm(pardon);//fail
        top.signForm(pardon);//ok
        okay.executeForm(pardon);
        top.executeForm(pardon);
        std::cout << pardon << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr <<"\033[36m" << " Error: " << e.what() << "\033[0m" << std::endl;
    }
    return 0;
}
