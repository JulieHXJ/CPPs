/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:08:03 by xhuang            #+#    #+#             */
/*   Updated: 2025/07/05 18:04:57 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap(std::string name);
    FragTrap(const FragTrap& src);
    FragTrap& operator=(const FragTrap &other);    
    ~FragTrap();

    void attack(const std::string& target);
    void highFivesGuys(void);// displays a positive high-fives request on the standard output
};


#endif