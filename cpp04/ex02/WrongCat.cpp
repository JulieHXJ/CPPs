/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:56:28 by xhuang            #+#    #+#             */
/*   Updated: 2025/07/09 11:53:34 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "\033[38;5;16mWrongCat default constructor called\033[0m" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src)
{
    std::cout << "\033[38;5;16mWrongCat copy constructor called\033[0m" << std::endl;
    *this = src;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "\033[38;5;16mWrongCat assignment operator called\033[0m" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "\033[38;5;16mWrongCat destructor called\033[0m" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "\033[38;5;16mWrongCat makes a sound: Meeeeeeeooooooow~\033[0m" << std::endl;
}