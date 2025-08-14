/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:19:39 by xhuang            #+#    #+#             */
/*   Updated: 2025/08/11 19:35:53 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

/**
 * * Required grades: sign 72, exec 45
 * * Print drilling noises
 * informs that <target> has been robotomized successfully 50% of the time. 
 * Otherwise, it informs that the robotomy failed.
 */
class RobotomyRequestForm : public AForm
{
private:
    std::string _target;

public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();

    virtual void executeAction() const; 


};



#endif // ROBOTOMYREQUESTFORM_HPP