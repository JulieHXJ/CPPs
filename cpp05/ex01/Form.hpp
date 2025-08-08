/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:19:28 by xhuang            #+#    #+#             */
/*   Updated: 2025/08/05 17:49:33 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
private: 
    const std::string _name;
    bool _isSigned;
    const int _signGrade;//required grade to sign
    const int _executeGrade; //required grade to execute

public:
    Form(const std::string &name, int signGrade, int executeGrade);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    //getters
    const std::string &getName() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
    
    //member functions
    void beSigned(const Bureaucrat &b);

};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif // FORM_HPP