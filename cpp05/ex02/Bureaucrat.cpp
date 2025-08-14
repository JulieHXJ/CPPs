/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:29:09 by xhuang            #+#    #+#             */
/*   Updated: 2025/08/14 17:24:42 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name(name), grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        // name is const, so we cannot assign it
        grade = other.grade;
        if (grade < 1)
            throw GradeTooHighException();
        if (grade > 150)
            throw GradeTooLowException();
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "\033[33mBureaucrat " << name << " destroyed\033[0m" << std::endl;
}

const std::string &Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade() {
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

void Bureaucrat::signForm(AForm &f)
{
    try{
        f.beSigned(*this);
        std::cout << "\033[32m" << name << " signed " << f.getName() << "\033[0m" << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "\033[31m" << name << " couldn't sign " << f.getName()
        << " because " << e.what() << "\033[0m" << std::endl;
    }
    
}

/**
 *  It must attempt to execute the form. If successful, print something like:
<bureaucrat> executed <form>
If not, print an explicit error message.
 */
void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << "\033[32m" <<  name << " executed " << form.getName() << "\033[0m" << std::endl;
    } catch (const std::exception &e) {
        std::cout << "\033[31m" <<  name << " couldn't execute " << form.getName()
                  << " because " << e.what() << "\033[0m" << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
    out << "\033[34m" << b.getName() << ", bureaucrat grade " << b.getGrade() << "\033[0m";
    return out;
}
