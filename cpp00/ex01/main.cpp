/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:41:01 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/23 15:13:11 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string input;
    
    while (1)
    {
        if (std::cin.eof())
			break;
        //display prompt
        std::cout << YELLOW << "Please enter the command (ADD/SEARCH/EXIT): " << RESET;
        std::getline(std::cin, input);

        if (input == "EXIT")
            break;
        else if (input == "ADD")
            phonebook.addContact();
        else if (input == "SEARCH")
            phonebook.search();
        else
            std::cout << RED << "Invalid command!" << RESET << std::endl;
    }
    return (0);
}