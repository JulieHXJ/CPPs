/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:21:52 by xhuang            #+#    #+#             */
/*   Updated: 2025/08/05 17:58:27 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned), 
      _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
    if (other._signGrade < 1 || other._executeGrade< 1)
        throw Form::GradeTooHighException();
    if (other._signGrade > 150 || other._executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form(){
    std::cout << "\033[33mForm " << _name << " destroyed\033[0m" << std::endl;
}

const std::string &Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _isSigned;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecuteGrade() const {
    return _executeGrade;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade too low";
}

/** takes a Bureaucrat as a parameter. 
It changes the form’s status to signed if the bureaucrat’s grade 
is high enough (greater than or equal to the required one). */
void Form::beSigned(const Bureaucrat &b) {
    //if <= signGrade, then sign
    if (b.getGrade() > _signGrade)
    {
        throw Form::GradeTooLowException();
    }
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
    out << "Form Name: " << f.getName() 
        << ", Signed: " << (f.getSigned() ? "Yes" : "No") 
        << ", Sign Grade Required: " << f.getSignGrade() 
        << ", Execute Grade Required: " << f.getExecuteGrade();
    return out;
}