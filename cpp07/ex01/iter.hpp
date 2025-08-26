/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:50:45 by junjun            #+#    #+#             */
/*   Updated: 2025/08/26 22:50:04 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // for size_t

template <typename T>
void iter(T* array, size_t length, void (*func)(T&)) {
	if (!array || length == 0 || !func)
	{
		return;
	}
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}

//overload function for const T
template <typename T>
void iter(T const* array, size_t length, void (*func)(T const&)) {
	if (!array || length == 0 || !func)
	{
		return;
	}
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}


#endif