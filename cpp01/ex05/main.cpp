/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:04:16 by xhuang            #+#    #+#             */
/*   Updated: 2025/04/28 18:02:10 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
	std::string level;

    if (ac != 1)
	{
		std::cout << "Usage: ./harl" << std::endl;
		return (1);
	}
	std::cout << "Enter complaint level (DEBUG, INFO, WARNING, ERROR):" << std::endl;
    while (std::getline(std::cin, level))
    {
		if (level == "exit")
		{
			std::cout << "Goodbye:)" << std::endl;
			break ;
		}
        harl.complain(level);
        std::cout << "Enter complaint level (DEBUG, INFO, WARNING, ERROR):" << std::endl;
    }
	return (0);
}