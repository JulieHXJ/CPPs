/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:21:09 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/28 15:35:05 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
private:
    std::string type;
    
public:
    Weapon(const std::string type);
    ~Weapon();

    const std::string &getType() const;//take const string and return a const ref
    void setType(const std::string &newType);//pass value will create unnecessary copy, so pass ref
    
};
#endif