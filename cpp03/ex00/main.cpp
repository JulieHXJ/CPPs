/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:30:23 by xhuang            #+#    #+#             */
/*   Updated: 2025/06/29 18:33:39 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void printStatus(const ClapTrap& bot, const std::string& label) {
    std::cout << "\n< " << label << " >" << std::endl;
    std::cout << "Name: " << bot.getName() << std::endl;
    std::cout << "Hit Points (HP): " << bot.getHitPoints() << std::endl;
    std::cout << "Energy Points (EP): " << bot.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage (AD): " << bot.getAttackDmg() << std::endl;
}

int main(void) 
{
    //defination
    ClapTrap a("Tom");//constructor
    ClapTrap b(a);//copy constructor
    ClapTrap c("Jerry");
    a = c;//copy assignment operator

    //display
    std::cout << "\n INITIAL STATUS" << std::endl;
    printStatus(a, "a");;
    printStatus(b, "b");
    printStatus(c, "c");
    
    // events
    std::cout << "\n ACTIONS" << std::endl;
    a.attack("Tom");
    b.takeDamage(5);
    b.beRepaired(1);
    b.attack("Jerry");
    a.takeDamage(0);
    a.attack("Tom");
    b.takeDamage(10);
    b.attack("Jerry");

    std::cout << "\n FINAL STATUS" << std::endl;
    printStatus(a, "a");
    printStatus(b, "b");
    printStatus(c, "c");

    return 0;
}
