/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:02:18 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/25 18:15:47 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
    std::string name = "";
    std::cout << "insert zombie name: ";
    std::cin >> name;
    
    //allocation on heap (malloc)
    Zombie* heapZombie = newZombie(name);
    heapZombie->annouce();
    delete heapZombie;

    std::cout << "insert another zombie name: ";
    std::cin >> name;
    
    //create on stack (temporary)
    randomChump(name);
    return 0;
}