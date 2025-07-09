/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog copy.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:53:06 by xhuang            #+#    #+#             */
/*   Updated: 2025/07/09 12:06:18 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *brain; // Pointer to Brain object for Dog
public:
    Dog();
    Dog(const Dog& src);
    Dog& operator=(const Dog &other);
    virtual ~Dog();// virtual destructor to ensure proper cleanup of derived classes

    void makeSound() const;
    Brain* getBrain() const;
};



#endif