/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:22:53 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/28 15:51:57 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon): name(name), weapon(weapon)
{} 
    
void HumanA::attack() const
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}