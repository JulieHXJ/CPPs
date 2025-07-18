/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:12:04 by xhuang            #+#    #+#             */
/*   Updated: 2025/06/28 14:17:15 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// Default constructor
Fixed::Fixed(void) 
{
    fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

//copy constructor
Fixed:: Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other; // use copy assignment operator to copy the value
}

//copy assignment operator
Fixed& Fixed:: operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) // check for self-assignment
    {
        fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed:: ~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed:: getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixedPointValue;
}

void Fixed:: setRawBits(int const raw)
{
    fixedPointValue = raw;
}
