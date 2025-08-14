/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:24:22 by xhuang            #+#    #+#             */
/*   Updated: 2025/08/14 21:03:22 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib> 
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::srand(std::time(NULL)); // seed once for the whole program（for random in robotomy）
    
    try
    {
        std::cout << "----Bureaucrat INIT----" << std::endl;
        Bureaucrat top("top", 1); //can sign and execute
        Bureaucrat exec("exec", 40); // > 5 
        Bureaucrat mid("mid", 100); // < 145
        Bureaucrat low("low", 150); //cannot do anything
        std::cout << low << "\n" << mid << "\n" << exec << "\n" << top << std::endl;
        
        std::cout << "----Forms Creation----\n";
        Intern randomIntern;

        AForm* f1 = randomIntern.makeForm("shrubbery creation", "home");
        AForm* f2 = randomIntern.makeForm("robotomy request", "Bender");
        AForm* f3 = randomIntern.makeForm("presidential pardon", "Arthur Dent");
        AForm* fBad = randomIntern.makeForm("unknown thing", "Nobody");
        (void)fBad; // to avoid unused variable warning
        
        std::cout << "----Test1 ShrubberyCreationForm----" << std::endl;
        if (f1) 
        {
            std::cout << *f1 << std::endl;
            low.executeForm(*f1);
            low.signForm(*f1);
            mid.signForm(*f1);
            low.executeForm(*f1);
            exec.executeForm(*f1);
            std::cout << *f1 << "\n";
        }
        
        std::cout << "----Test2 RobotomyRequestForm----" << std::endl;
        if (f2) 
        {
            std::cout << *f2 << std::endl;
            exec.executeForm(*f2);
            mid.signForm(*f2);
            exec.signForm(*f2);
            mid.executeForm(*f2);
            for (int i = 0; i < 5; ++i) {
                exec.executeForm(*f2);
            }
            std::cout << *f2 << "\n\n";
        }
        
        std::cout << "----Test3 PresidentialPardonForm----" << std::endl;
        if (f3) {
            std::cout << *f3 << std::endl;
            exec.executeForm(*f3);
            exec.signForm(*f3);
            top.signForm(*f3);
            exec.executeForm(*f3);
            top.executeForm(*f3);
            std::cout << *f3 << "\n\n";
        }

        delete f1;
        delete f2;
        delete f3;
    }
    catch(const std::exception& e)
    {
        std::cerr << "[Fatal]" << e.what() << std::endl;
    }
    return 0;
}
