/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 00:13:02 by junjun            #+#    #+#             */
/*   Updated: 2025/09/01 12:36:33 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef> // for size_t
#include <stdexcept> // for std::out_of_range

template <typename T>
class Array {
private:
	size_t _size;
	T* _data;
public:
	Array();
	// Array(unsigned int n);
	explicit Array(unsigned int n);//Prevents accidental implicit conversions
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	T& operator[](size_t n);
	const T& operator[](size_t n) const;
	size_t size() const;
};

#include "Array.tpp"
#endif