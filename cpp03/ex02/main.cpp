/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:30:23 by xhuang            #+#    #+#             */
/*   Updated: 2025/07/04 18:22:48 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static void printStatus(const ClapTrap& bot, const std::string& label) {
    std::cout << "\n< " << label << " >" << std::endl;
    std::cout << "Name: " << bot.getName() << std::endl;
    std::cout << "Hit Points (HP): " << bot.getHitPoints() << std::endl;
    std::cout << "Energy Points (EP): " << bot.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage (AD): " << bot.getAttackDmg() << std::endl;
}

int main(void) 
{
    std::cout << "=== ClapTrap Tests ===" << std::endl;
    ClapTrap a("Tom");
    ClapTrap b(a);
    ClapTrap c("Jerry");
    a = c;

    std::cout << "\nINITIAL STATUS" << std::endl;
    printStatus(a, "a");;
    printStatus(b, "b");
    printStatus(c, "c");
    
    std::cout << "\nACTIONS" << std::endl;
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
    
    std::cout << "\n=== ScavTrap Tests ===" << std::endl;
    ScavTrap scav("Serena");
    printStatus(scav, "ScavTrap Serena");
    scav.attack("Zombie");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate();
    printStatus(scav, "ScavTrap Serena (After Actions)");

    std::cout << "\n=== FragTrap Test ===\n";
    FragTrap frag("Victor");
    printStatus(frag, "FragTrap Victor");

    frag.attack("Dragon");
    frag.takeDamage(50);
    frag.beRepaired(20);
    frag.highFivesGuys();
    printStatus(frag, "FragTrap Victor (after actions)");

    std::cout << "\n=== End of main ===\n";
    return 0;
}
