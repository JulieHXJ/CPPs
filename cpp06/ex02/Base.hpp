/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:05:26 by junjun            #+#    #+#             */
/*   Updated: 2025/08/24 18:17:26 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

//Implement a Base class that has a public virtual destructor only.
class Base
{
public:
	virtual ~Base();
};

class A : public Base {};//empty class
class B : public Base {};
class C : public Base {};

#endif