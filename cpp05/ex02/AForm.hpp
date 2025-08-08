/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:19:28 by xhuang            #+#    #+#             */
/*   Updated: 2025/08/08 17:29:37 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

//turn into a base abstract class
class AForm {
private: 
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;

public:
    AForm(const std::string &name, int signGrade, int executeGrade);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm() = 0; //abstract

    const std::string &getName() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    

    //member functions
    void beSigned(const Bureaucrat &b);
    void execute(Bureaucrat const & executor) const;
    virtual void executeAction() const = 0;//implemented in every child class 

    //exceptions
    class GradeTooHighException : public std::exception { const char* what() const throw(); };
    class GradeTooLowException : public std::exception { const char* what() const throw(); };
    class NotSignedException : public std::exception { const char* what() const throw(); };
        
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif // AFORM_HPP