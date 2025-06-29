/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:56:48 by xhuang            #+#    #+#             */
/*   Updated: 2025/06/29 18:28:06 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout << "constructor called" << std::endl;
}

ClapTrap:: ClapTrap(const ClapTrap& src): name(src.name), hitPoints(src.hitPoints), energyPoints(src.energyPoints), attackDamage(src.attackDamage){
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap:: operator=(const ClapTrap &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->name = src.name;
        this->hitPoints = src.hitPoints;
        this->energyPoints = src.energyPoints;
        this->attackDamage = src.attackDamage;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "destructor called" << std::endl;
}

std::string ClapTrap::getName() const {
    return name;
}

int ClapTrap::getHitPoints() const {
    return hitPoints;
}

int ClapTrap::getEnergyPoints() const {
    return energyPoints;
}

int ClapTrap::getAttackDmg() const {
    return attackDamage;
}

void ClapTrap::setEnergyPoints(int amount) {
    energyPoints = amount;
}

//When ClapTrap attacks, it causes its target to lose <attack damage> hit points
//Attacking and repairing each cost 1 energy point.
//ClapTrap can’t do anything if it has no hit points or energy points left
void ClapTrap::attack(const std::string& target) {
    std::cout << "\n<<<Attacking>>> " << std::endl;
    if (this->energyPoints<= 0 || this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " does not have enough energy points or hit points!" << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    std::cout << "ClapTrap " << this->name << " has " << this->energyPoints << " energy points left!" << std::endl;
}

void ClapTrap:: takeDamage(unsigned int amount) {
    std::cout << "\n<<<Taking damage>>>" << std::endl;
    if (this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is already destroyed!" << std::endl;
        return;
    }
    this->hitPoints -= amount;
    if (this->hitPoints < 0)
        this->hitPoints = 0;
    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
}

//When ClapTrap repairs itself, it regains <amount> hit points.
//Attacking and repairing each cost 1 energy point.
//ClapTrap can’t do anything if it has no hit points or energy points left
void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "\n<<<Repairing>>>" << std::endl;
    if (this->energyPoints <= 0 || this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " does not have enough energy points or hit points!" << std::endl;
        return;
    }

    this->energyPoints--;
    this->hitPoints += amount;
    std::cout << "ClapTrap " << this->name << " regains " << amount << " hit points." << std::endl;
    std::cout << "ClapTrap " << this->name << " has " << this->hitPoints << " Hit points left!" << std::endl;
}