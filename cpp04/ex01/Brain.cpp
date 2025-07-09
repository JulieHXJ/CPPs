/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:40:43 by xhuang            #+#    #+#             */
/*   Updated: 2025/07/09 11:51:12 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "\033[38;5;22mBrain default constructor called\033[0m" << std::endl;
}

Brain::Brain(const Brain& src)
{
    std::cout << "\033[38;5;22mBrain copy constructor called\033[0m" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = src.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "\033[38;5;22mBrain assignment operator called\033[0m" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
} 

Brain::~Brain()
{
    std::cout << "\033[38;5;22mBrain destructor called\033[0m" << std::endl;
}

std::string Brain::getIdea(int i) const {
    if (i < 0 || i >= 100)
        return "Invalid index";
    return ideas[i];
}

void Brain::setIdea(int i, const std::string& idea) {
    if (i < 0 || i >= 100)
        return;
    ideas[i] = idea;
}