/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:12:02 by xhuang            #+#    #+#             */
/*   Updated: 2025/07/04 18:19:18 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap constructor called for " << name << std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << name << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    std::cout << "\n<<<Attacking>>> " << std::endl;
    std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}


void FragTrap::highFivesGuys(void)
{
    std::cout << "\n<<<High Fives>>> " << std::endl;
    std::cout << "FragTrap " << name << " requests a positive high-five! " << std::endl;
}