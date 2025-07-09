/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:05:45 by xhuang            #+#    #+#             */
/*   Updated: 2025/07/09 11:59:38 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
    std::cout << "\033[38;5;13mDog default constructor called\033[0m" << std::endl;
    this->type = "Dog";
}

Dog ::~Dog()
{
    std::cout << "\033[38;5;13mDog destructor called\033[0m" << std::endl;
    delete this->brain; // Clean up the brain
}

Dog::Dog(const Dog& src) : Animal(src) 
{
    std::cout << "\033[38;5;13mDog copy constructor called\033[0m" << std::endl;
    this->brain = new Brain(*src.brain); // Deep copy of the brain, not the pointer
    this->type = src.type;
}

Dog& Dog::operator=(const Dog& other) 
{
    std::cout << "\033[38;5;13mDog assignment operator called\033[0m" << std::endl;
    if (this != &other) 
    {
        Animal::operator=(other); // Call base class cuz we need also type
        delete this->brain; // Clean up existing brain
        brain = new Brain(*other.brain); // copy brain
        type = other.type;
    }
    return *this;
}
void Dog::makeSound() const 
{
    std::cout << "\033[38;5;13mDog barks: Woof Woof!\033[0m" << std::endl;
}

Brain* Dog::getBrain() const 
{
    return this->brain;
}