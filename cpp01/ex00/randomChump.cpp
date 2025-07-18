/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:50:34 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/25 18:01:42 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//create on stack, names it, and makes it announce itself, auto destroy
void randomChump( std::string name )
{
    Zombie zombie(name);
    zombie.annouce();
}