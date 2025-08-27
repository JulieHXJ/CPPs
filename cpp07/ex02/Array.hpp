/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 00:13:02 by junjun            #+#    #+#             */
/*   Updated: 2025/08/28 00:22:53 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef> // for size_t
#include <stdexcept> // for std::out_of_range

template <typename T>
class Array {
private:
	size_t _size;//non negative index for checking out of range
	T* _data;
public:
	Array() : _size(0), _data(NULL) {}//Construction with no parameter
	
	Array(unsigned int n) : _size(n), _data(n ? new T[n]() : NULL) {}//Construction with an unsigned int
	Array(const Array& other) : _size(other._size), _data(other._size ? new T[other._size]() : NULL) {
		for (size_t i = 0; i < _size; ++i) {
			_data[i] = other._data[i];
		}
	}
	
	//❌ 赋值时先 delete[] 再 new，中途异常会把对象留在“半死不活”的状态（改用“先分配新内存再替换”更安全）。
	Array& operator=(const Array& other) {
		if (this != &other) {
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

	~Array() { delete[] _data; }

	T& operator[](size_t index) {
		if (index >= _size) {
			throw std::out_of_range("Array index out of bounds");
		}
		return _data[index];
	}
	const T& operator[](size_t idx) const {
    	if (idx >= _size) 
			throw std::out_of_range("Array index out of range");
    	return _data[idx];
	}

	size_t size() const { return _size; }

};

#endif