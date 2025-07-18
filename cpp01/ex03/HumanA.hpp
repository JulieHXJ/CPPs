/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:21:50 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/28 15:40:04 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
private:
    Weapon &weapon;//ref to weapon, so always be armed
    std::string name;
public:
    HumanA(const std::string &name, Weapon &weapon);
    void attack() const;
};


#endif