/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:02:18 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/25 18:38:02 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
    int zombieCount = 0;
    std::string name = "";
    std::cout << "insert number of zombies: ";
    std::cin >> zombieCount;
    std::cout << "insert zombie name: ";
    std::cin >> name;
    
    Zombie* horde = zombieHorde(zombieCount, name);
    for (int i = 0; i < zombieCount; i++)
    {
        horde[i].annouce();
    }
    delete[] horde;
    return 0;
}