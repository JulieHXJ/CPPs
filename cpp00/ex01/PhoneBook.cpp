/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:36:31 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/23 15:31:18 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): contactCount(0), contactIndex(0) {}

std::string PhoneBook::get_input(const std::string& prompt) const
{
    std::string input;

    std::cout << YELLOW << prompt << RESET;
    std::getline(std::cin, input);
    while (input.empty())
	{
		if (std::cin.eof())
			exit(0);
		else
        {
			std::cout << RED << "No empty field allowed!" << RESET << std::endl;
            std::cout << YELLOW << "Please enter: " << RESET;
            std::getline(std::cin, input);
        }
	}
    return (input);
}

//If the user tries to add a 9th contact, replace the oldest one by the new one.
void PhoneBook::addContact()
{
    std::cout << YELLOW << "You are adding a new contact..." << RESET << std::endl;
    contacts[contactIndex].setFirstName(get_input("Enter first name: "));
    contacts[contactIndex].setLastName(get_input("Enter last name: "));
    contacts[contactIndex].setNickName(get_input("Enter nick name: "));
    contacts[contactIndex].setPhoneNumber(get_input("Enter phone number: "));
    contacts[contactIndex].setSecret(get_input("Enter darkest secret: "));
    if (contactCount < 8)
    {
        contactCount++;
    }
    contactIndex = (contactIndex + 1) % 8;//ready for next contact
    std::cout <<YELLOW << "New contact added!" << RESET << std::endl;
}

std::string PhoneBook::truncate(const std::string& str) const
{
    if (str.length() > 10)
    {
        return str.substr(0, 9) + ".";
    }
    return str;
}

//display all contacts
void PhoneBook::printAll() const
{
    if (contactCount == 0)
    {
        std::cout << RED << "Empty phonebook!" << RESET << std::endl;
        return;
    }
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "  Index  | First Name | Last Name  | Nickname  " << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    for (int i = 0; i < contactCount; i++)
    {
        std::cout << " " << std::setw(7) << i << " |"; 
        std::cout << " " << std::setw(10) << std::right << truncate(contacts[i].getFirstName()) << " |";
        std::cout << " " << std::setw(10) << std::right << truncate(contacts[i].getLastName()) << " |";
        std::cout << " " << std::setw(10) << std::right << truncate(contacts[i].getNickName())<< " |";
        std::cout << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;
}

// show specific contact by index
void PhoneBook::searchIndex() const
{
    std::string input;
    int index;

    while (1)
    {
        input = get_input("Please enter the index: ");
        if (std::cin.eof())
            exit(0);
        try
        {
            index = std::stoi(input);//string to integer
            if (index >= 0 && index < contactCount)
                break;
            else
                std::cout << RED << "Index out of range!" << RESET << std::endl;
        }
        catch(const std::invalid_argument& e)
        {
            std::cout << RED << "Invalid input! Please enter a number!" << RESET << std::endl;
        }
    }
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getSecret() << std::endl;
}

void PhoneBook::search() const
{
    printAll();
    if (contactCount == 0)
    {
        return;
    }
    searchIndex();
}
