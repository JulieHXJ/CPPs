/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:21:52 by xhuang            #+#    #+#             */
/*   Updated: 2025/08/05 17:58:27 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned), 
      _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
    if (other._signGrade < 1 || other._executeGrade< 1)
        throw AForm::GradeTooHighException();
    if (other._signGrade > 150 || other._executeGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm(){
    std::cout << "\033[33mForm " << _name << " destroyed\033[0m" << std::endl;
}

const std::string &AForm::getName() const {
    return _name;
}

bool AForm::getSigned() const {
    return _isSigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecuteGrade() const {
    return _executeGrade;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade too low";
}

const char* AForm::NotSignedException::what() const throw() {
    return "AForm not signed";
}

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > _signGrade)
    {
        throw AForm::GradeTooLowException();
    }
    _isSigned = true;
}

//check and execute
void AForm::execute(Bureaucrat const & executor) const
{
    if (!_isSigned)
        throw NotSignedException();
    if (executor.getGrade() > _executeGrade)
        throw GradeTooLowException();
    this->executeAction();  // for overriding
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
    out << "AForm Name: " << f.getName() 
        << ", Signed: " << (f.getSigned() ? "Yes" : "No") 
        << ", Sign Grade Required: " << f.getSignGrade() 
        << ", Execute Grade Required: " << f.getExecuteGrade();
    return out;
}
