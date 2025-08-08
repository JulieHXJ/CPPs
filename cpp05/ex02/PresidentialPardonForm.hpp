/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:19:21 by xhuang            #+#    #+#             */
/*   Updated: 2025/08/08 17:43:25 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

/**
 * Required grades: sign 25, exec 5
 * Informs that <target> has been pardoned by Zaphod Beeblebrox.
 */
class PresidentialPardonForm : public AForm
{
private:
    /* data */
public:
    PresidentialPardonForm(/* args */);
    ~PresidentialPardonForm();
};

PresidentialPardonForm::PresidentialPardonForm(/* args */)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}


#endif // PRESIDENTIALPARDONFORM_HPP