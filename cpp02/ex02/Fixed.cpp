/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:12:04 by xhuang            #+#    #+#             */
/*   Updated: 2025/06/28 17:29:09 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
    : fixedPointValue(0){}

// int copy constructor
Fixed::Fixed(int const n)
{
    fixedPointValue = n << fractionalBits;
}

// float copy constructor
Fixed::Fixed(float const f)
{
    fixedPointValue = static_cast<int>(roundf(f * (1 << fractionalBits)));
}

Fixed:: Fixed(const Fixed& other)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed:: operator=(const Fixed &other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixedPointValue = other.fixedPointValue;
    return *this;
}

Fixed:: ~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
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

//operators
std::ostream &operator<<(std::ostream &os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}


bool    Fixed::operator>(const Fixed &other) const {
    return this->fixedPointValue > other.fixedPointValue;
}

bool    Fixed::operator<(const Fixed &other) const {
    return this->fixedPointValue < other.fixedPointValue;
}

bool	Fixed::operator>=(const Fixed &other) const {
    return this->fixedPointValue >= other.fixedPointValue;
}

bool	Fixed::operator<=(const Fixed &other) const {
    return this->fixedPointValue <= other.fixedPointValue;
}

bool	Fixed::operator==(const Fixed &other) const {
    return this->fixedPointValue == other.fixedPointValue;
}

bool	Fixed::operator!=(const Fixed &other) const {
    return this->fixedPointValue != other.fixedPointValue;
}

Fixed Fixed:: operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed:: operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed:: operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed:: operator/(const Fixed &other) const {
    return Fixed (this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() {
    this->fixedPointValue++; // increment the fixed-point value 1/256
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->fixedPointValue++;
    return temp;
}

Fixed &Fixed::operator--() {
    this->fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->fixedPointValue--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}