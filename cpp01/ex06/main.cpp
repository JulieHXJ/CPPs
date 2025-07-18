/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:41:53 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/29 17:08:36 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    
    if (ac != 2)
	{
		std::cout << "Usage: ./harlFilter DEBUG/INFO/WARNING/ERROR" << std::endl;
		return (1);
	}
    std::string level(av[1]);
	harl.complain(level);
	return (0);
}