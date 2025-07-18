/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:40:57 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/23 13:15:43 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

// Class definition 
class Contact
{
public:
    // Constructor
    Contact();
    // //Destructor
    // ~Contact();

    //functions
    void setFirstName(const std::string firstName);
    void setLastName(const std::string lastName);
    void setNickName(const std::string nickeName);
    void setPhoneNumber(const std::string phoneNumber);
    void setSecret(const std::string secret);
    std::string		getFirstName() const;
	std::string		getLastName() const;
	std::string		getNickName() const;
	std::string		getPhoneNumber() const;
	std::string		getSecret() const;
    
    
//variables of the contact structure
private:
    std:: string firstName;
    std:: string lastName;
    std:: string nickName;
    std:: string phoneNumber;
    std:: string darkSecret;

};

#endif