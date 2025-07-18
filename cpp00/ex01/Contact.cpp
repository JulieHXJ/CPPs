/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:39:37 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/23 13:20:22 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//constructor/initialization
Contact::Contact()
{
    this->firstName = "";
    this->lastName = "";
    this->nickName = "";
    this->phoneNumber = "";
    this->darkSecret = "";
}

//setters
void Contact::setFirstName(const std::string firstName)
{
    this->firstName = firstName;
}

void Contact::setLastName(const std::string lastName)
{
    this->lastName = lastName;   
}

void Contact::setNickName(const std::string nickeName)
{
    this->nickName = nickeName;
}

void Contact::setPhoneNumber(const std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Contact::setSecret(const std::string secret)
{
    this->darkSecret = secret;
}

//getters
std::string		Contact::getFirstName() const
{
    return (firstName);
}

std::string		Contact::getLastName() const
{
    return (lastName);
}

std::string		Contact::getNickName() const
{
    return (nickName);
}

std::string		Contact::getPhoneNumber() const
{
    return (phoneNumber);
}

std::string		Contact::getSecret() const
{
    return (darkSecret);
}
    