/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:56:48 by xhuang            #+#    #+#             */
/*   Updated: 2025/07/04 17:51:04 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout << "ClapTrap constructor called for " << name << std::endl;
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
    std::cout << "ClapTrap destructor called for " << name << std::endl;
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

void ClapTrap::attack(const std::string& target) {
    std::cout << "\n<<<Attacking>>> " << std::endl;
    if (energyPoints<= 0 || hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " does not have enough energy points or hit points!" << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    std::cout << "ClapTrap " << name << " has " << energyPoints << " energy points left!" << std::endl;
}

void ClapTrap:: takeDamage(unsigned int amount) {
    std::cout << "\n<<<Taking damage>>>" << std::endl;
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
        return;
    }
    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "\n<<<Repairing>>>" << std::endl;
    if (energyPoints <= 0 || hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " does not have enough energy points or hit points!" << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " regains " << amount << " hit points." << std::endl;
    std::cout << "ClapTrap " << name << " has " << hitPoints << " Hit points left!" << std::endl;
}