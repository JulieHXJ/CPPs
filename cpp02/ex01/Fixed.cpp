/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:12:04 by xhuang            #+#    #+#             */
/*   Updated: 2025/06/28 15:23:56 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) 
{
    fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

// int copy constructor
Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called" << std::endl;
    fixedPointValue = n << fractionalBits; // shift left 8 bits to store
}

// float copy constructor
Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called" << std::endl;
    fixedPointValue = static_cast<int>(roundf(f * (1 << fractionalBits))); // f * 256, round to nearest integer
}


Fixed:: Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other; // use copy assignment operator to copy the value
}

Fixed& Fixed:: operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixedPointValue = other.fixedPointValue;
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

// convert to float
float Fixed::toFloat(void) const
{
    return static_cast<float>(fixedPointValue) / (1 << fractionalBits); // divide by 256
}

// Convert to integer
int Fixed::toInt(void) const
{
    return fixedPointValue >> fractionalBits; // shift right 8 bits
}

//insert float value into output stream
std::ostream &operator<<(std::ostream &os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
