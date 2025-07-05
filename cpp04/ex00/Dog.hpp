/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:53:06 by xhuang            #+#    #+#             */
/*   Updated: 2025/07/05 17:47:01 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog& src);
    Dog& operator=(const Dog &other);
    virtual ~Dog();// virtual destructor to ensure proper cleanup of derived classes

    void makeSound() const;
};



#endif