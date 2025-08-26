/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:09:10 by junjun            #+#    #+#             */
/*   Updated: 2025/08/25 12:13:57 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T& min(T &a, T &b) {
	if (a < b)
		return a;
	return b;
}

template <typename T>
T& max(T &a, T &b) {
	if (a > b)
		return a;
	return b;
}

#endif