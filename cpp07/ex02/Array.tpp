/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:05:36 by xhuang            #+#    #+#             */
/*   Updated: 2025/09/01 12:37:44 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : _size(0), _data(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n) 
: _size(n), _data(n ? new T[n]() : NULL) {}

template <typename T>
Array<T>::Array(const Array& other) 
:  _size(other._size), _data(other._size ? new T[other._size]() : NULL) {
	for (size_t i = 0; i < _size; ++i) {
		_data[i] = other._data[i];
	}
}

template <typename T>
Array<T>::~Array() { delete[] _data;}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		T* newData = other._size ? new T[other._size]() : NULL;
		for (size_t i = 0; i < other._size; ++i) {
			newData[i] = other._data[i];
		}
		delete[] _data;
		_data = newData;
		_size = other._size;
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= _size) {
		throw std::out_of_range("Array index out of bounds");
	}
	return _data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
	if (index >= _size)
		throw std::out_of_range("Array index out of range");
	return _data[index];
}

template <typename T>
size_t Array<T>::size() const
{
	return _size;
}

#endif