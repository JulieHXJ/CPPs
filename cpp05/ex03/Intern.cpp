/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:36:43 by junjun            #+#    #+#             */
/*   Updated: 2025/08/14 20:13:53 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

// Intern::Intern(const Intern &other) {
// 	(void)other; // No need to copy anything, Intern has no member variables
// }

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&) { return *this;}
	
Intern::~Intern() {}
	
AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	// list of form names
	const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;

			switch (i)
			{
			case 0:
				return new ShrubberyCreationForm(target);
			case 1:
				return new RobotomyRequestForm(target);
			case 2:
				return new PresidentialPardonForm(target);
			}
		}
		
	}
	std::cout << "[Error] Form name not recognized: " << formName << std::endl;
	return NULL;
}