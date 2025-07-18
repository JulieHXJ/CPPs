/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:40:54 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/23 15:19:58 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cctype>
#include <iomanip>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

class PhoneBook 
{ 
public:
    PhoneBook();

    void addContact();
    void search() const;

private:
    Contact contacts[8];//define array of 8
    int contactCount;
    int contactIndex;
    std::string get_input(const std::string& prompt) const;
    std::string truncate(const std::string& str) const;
    void printAll() const;
    void searchIndex() const;

};

#endif