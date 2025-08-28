/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:05:36 by xhuang            #+#    #+#             */
/*   Updated: 2025/08/28 17:09:50 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_TPP
#define ARRAY_TPP
#include "Array.hpp"

template <typename T>
Array<T>::Array() : array_(NULL), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array_(new T[n]()), size_(n) {}

template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(other._size)
{
	if (_size > 0)
	{
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
	std::cout << "destructor called" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] _array;
		_size = other._size;
		if (_size > 0)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		else
			_array = NULL;
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif