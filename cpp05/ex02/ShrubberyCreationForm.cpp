/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:28:37 by xhuang            #+#    #+#             */
/*   Updated: 2025/08/08 18:07:13 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream> //for std::ofstream
#include <stdexcept> // for std::runtime_error

//pass const value to base constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}
    
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
    // create output file
    // converts the std::string into a const char* (old-style string)
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for writing");
    }
    //print ascii tree
    file <<
    "      /\\\n"
    "     /  \\\n"
    "    /++++\\\n"
    "   /  ++  \\\n"
    "  / ++++++ \\\n"
    " /__________\\\n"
    "     ||||\n"
    "     ||||\n";
    if (!file) {
        throw std::runtime_error("Failed to write to file");
    }
    file.close();
}