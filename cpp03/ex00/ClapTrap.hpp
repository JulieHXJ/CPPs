/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:51:52 by xhuang            #+#    #+#             */
/*   Updated: 2025/06/29 18:23:30 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
private:
    std::string name;
    int hitPoints;// the health of the ClapTrap
    int energyPoints;// for performing actions like attacking or repairing
    int attackDamage; // for the damage to the target when attacking
public:
    ClapTrap();
    ~ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& src);
    ClapTrap& operator=(const ClapTrap &other);

    // getter & setter
    std::string getName() const;
    int		getHitPoints() const;
    int		getEnergyPoints() const;
    int		getAttackDmg() const;
    void	setEnergyPoints(int amount);
    
    //member functions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};



#endif