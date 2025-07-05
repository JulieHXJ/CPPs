/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:05:45 by xhuang            #+#    #+#             */
/*   Updated: 2025/07/05 17:57:23 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() 
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog ::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src) 
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = src;
}

Dog& Dog::operator=(const Dog& other) 
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) 
    {
        this->type = other.type;
    }
    return *this;
}
void Dog::makeSound() const 
{
    std::cout << "Dog barks: Woof Woof!" << std::endl;
}