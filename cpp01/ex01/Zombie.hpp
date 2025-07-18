/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:37:27 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/25 18:43:45 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_H
#define _ZOMBIE_H

#include <iostream>

class Zombie
{
private:
    std::string name;

public:
    Zombie();
    ~Zombie();
    void setName(std::string name);
    void annouce(void);
};

#endif 