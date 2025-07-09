/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:54:01 by xhuang            #+#    #+#             */
/*   Updated: 2025/07/09 11:53:08 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "\033[38;5;15mWrongAnimal default constructor called\033[0m" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "\033[38;5;15mWrongAnimal destructor called\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "\033[38;5;15mWrongAnimal copy constructor called\033[0m" << std::endl;
    this->type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "\033[38;5;15mWrongAnimal assignment operator called\033[0m" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "\033[38;5;15mWrongAnimal makes a wrong sound\033[0m" << std::endl;
}