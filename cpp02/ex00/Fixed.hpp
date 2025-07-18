/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:01:55 by xhuang            #+#    #+#             */
/*   Updated: 2025/06/28 14:10:29 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
    int fixedPointValue;
    static const int fractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed &other); //copy constructor: create a new object as a copy of another
    Fixed &operator=(const Fixed &other); //copy assignment operator: assign an existing object with the value of another
    ~Fixed();
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
