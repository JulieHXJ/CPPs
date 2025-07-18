/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:50:51 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/25 18:01:19 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//create a zombie with allocationg, names it, and returns it (need to use delete)
Zombie* newZombie( std::string name )
{
    return new Zombie(name);
}