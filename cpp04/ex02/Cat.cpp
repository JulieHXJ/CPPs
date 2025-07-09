/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:08:02 by xhuang            #+#    #+#             */
/*   Updated: 2025/07/09 12:10:16 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : brain(new Brain())
{
    std::cout << "\033[38;5;14mCat default constructor called\033[0m" << std::endl; 
    this->type = "Cat";
}

Cat::Cat(const Cat& src) : Animal(src)
{
    std::cout << "\033[38;5;14mCat copy constructor called\033[0m" << std::endl;
    *this = src;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "\033[38;5;14mCat assignment operator called\033[0m" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }  
    return *this;
}

Cat::~Cat()
{
    std::cout << "\033[38;5;14mCat destructor called\033[0m" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const
{
    std::cout << "\033[38;5;14mCat makes a sound: Meow~\033[0m" << std::endl;
}

Brain* Cat::getBrain() const
{
    return this->brain;
}