/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:27:42 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/28 15:50:01 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
private:
    Weapon *weapon;//point can be null
    std::string name;
public:
    HumanB(const std::string &name);
    void setWeapon(Weapon &newWeapon);
    void attack() const;
};

#endif