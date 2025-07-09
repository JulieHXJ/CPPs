/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:58:06 by xhuang            #+#    #+#             */
/*   Updated: 2025/07/09 12:04:09 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

Animal::Animal()
{
    std::cout << "\033[38;5;12mAnimal default constructor called\033[0m" << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal& other)
{
    std::cout << "\033[38;5;12mAnimal copy constructor called\033[0m" << std::endl;
    this->type = other.type;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "\033[38;5;12mAnimal assignment operator called\033[0m" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "\033[38;5;12mAnimal destructor called\033[0m" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const {
    std::cout << "\033[38;5;12mAnimal makes a sound\033[0m" << std::endl;
}