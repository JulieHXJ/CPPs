/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:38:08 by xhuang            #+#    #+#             */
/*   Updated: 2025/04/28 18:07:47 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	print_msg(std::string msg)
{
	std::cout << msg << std::endl;
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::string msg("I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!");
    print_msg(msg);
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
	std::string msg("I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!");
	print_msg(msg);
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
	std::string msg("I think I deserve to have some extra bacon for free.\nI've been coming for years, whereas you started working here just last month.");
	print_msg(msg);
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
	std::string msg("This is unacceptable! I want to speak to the manager now.");
	print_msg(msg);
}

void Harl::complain(std::string level)
{
    int i = 0;
    //array of levels
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    while (i < 4)
    {
        if (level == levels[i])
            break;
        i++;
    }
    switch (i)
    {
    case 0:
        this->debug();
    case 1:
        this->info();
    case 2:
        this->warning();
    case 3:
        this->error();
        break;
    default:
        std::cout << "Incorrect complain! Harl doesn't know what to say!" << std::endl;
        break;
    }
}