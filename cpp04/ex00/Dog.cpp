/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:05:45 by xhuang            #+#    #+#             */
/*   Updated: 2025/07/09 11:44:04 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() 
{
    std::cout << "\033[38;5;13mDog default constructor called\033[0m" << std::endl;
    this->type = "Dog";
}

Dog ::~Dog()
{
    std::cout << "\033[38;5;13mDog destructor called\033[0m" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src) 
{
    std::cout << "\033[38;5;13mDog copy constructor called\033[0m" << std::endl;
    *this = src;
}

Dog& Dog::operator=(const Dog& other) 
{
    std::cout << "\033[38;5;13mDog assignment operator called\033[0m" << std::endl;
    if (this != &other) 
    {
        this->type = other.type;
    }
    return *this;
}
void Dog::makeSound() const 
{
    std::cout << "\033[38;5;13mDog barks: Woof Woof!\033[0m" << std::endl;
}