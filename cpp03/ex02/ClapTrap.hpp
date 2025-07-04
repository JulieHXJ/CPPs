/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:51:52 by xhuang            #+#    #+#             */
/*   Updated: 2025/07/04 17:47:26 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
protected:// change to protected to allow accessing from child classes
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage; 
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& src);
    ClapTrap& operator=(const ClapTrap &other);
    virtual ~ClapTrap();  // change to virtual to allow polymorphism


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