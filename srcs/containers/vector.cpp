/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:14:16 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/04/12 08:08:56y adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"

/**
 * ========================================================================
 *
 * 					CONSTRUCTORS/COPIERS/DESTROYERS
 *
 * ========================================================================
 **/

template <class T, class Alloc>
ft::vector<T, Alloc>::vector(const ft::vector<T, Alloc>::allocator_type &allocator = allocator_type())
	: _allocator(allocator), _capacity(0), _data(nullptr), _size(0)
{
}

/**
 * @brief constructs a new vector and allocates it
 *
 * @param n : number of element in the new vector
 * @param value : is the value that will be assigne to the vector, its type will the also used
 */

template <class T, class Alloc>
ft::vector<T, Alloc>::vector(size_type n, const T &value, const Alloc &allocator)
	: _allocator(allocator.pointer), _capacity(0), _data(nullptr), _size(0)
{
	// check if n > 0
	for (int i = 1; i < n; i *= 2)
		_capacity = i;
	_size = n;
	try
	{
		_data = _allocator.allocate(_capacity);
		for (size_t i = 0; i < _size; i++)
			_allocator.construct(&_data[i], value);
	}
	catch (std::bad_alloc &ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << '\n';
	}
}

/**
 * @brief Construct a new vector object
 *
 * @tparam InputIterator
 * @param first
 * @param last
 */
template <class T, class Alloc>
template <class InputIterator>
ft::vector<T, Alloc>::vector(InputIterator first, InputIterator last, const Alloc &allocator)
	: _allocator(allocator.pointer), _capacity(0), _data(nullptr), _size(0)
{
	InputIterator tmp;
	int n;

	n = 0;
	tmp = first;
	while (tmp++ != last)
		n++;
	_size = n;
	// check if n > 0
	for (int i = 1; i < n; i *= 2)
		_capacity = i;
	// behaviour observed on the real vector
	// the capacity is alays a result from 2^x that is above the size
	_capacity = _capacity * _capacity;
	_data = _allocator.allocate(_capacity);
	for (size_t i = 0; (first + i) != last; i++)
	{
		n = i;
		_allocator.construct(&_data[i], (first + i));
	}
	_allocator.construct(&_data[n], (first + n));
	&_data[++n] = nullptr;
}

template <class T, class Alloc>
ft::vector<T, Alloc>::vector(const vector<T, Alloc> &x)
	: _allocator(x->get_allocator()), _capacity(x->capacity()), _data(nullptr), _size(x->size())
{
	_data = _allocator.allocate(_capacity);
	for (size_t i = 0; i < x->size(); i++)
		this->push_back(*(x->begin() + i));
}

/**
 * ========================================================================
 *
 * 						 -- INFORMATION --
 *
 * ========================================================================
 **/
template <class T, class Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::size() const
{
	return (_size);
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::max_size() const
{
	return (this->_allocator.max_size());
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::capacity() const
{
	return (this->_capacity);
}

/**
 * ========================================================================
 *
 * 						MODIFIERS
 *
 * ========================================================================
 **/

/**
 * @brief
 *
 * @param x : new element adress to be added
 */
template <class T, class Alloc>
void ft::vector<T, Alloc>::push_back(const T &x)
{
	if (_size + 1 < _capacity)
	{
		_allocator.construct(&_data[_size], x);
		_size++;
	}
	&_data[_size] = nullptr;
}

template <class T, class Alloc>
void ft::vector<T, Alloc>::pop_back()
{
	_allocator.destroy(&_data[_size - 1]);
}

/*
	iterator vector::insert(iterator position, const T &x);
	void vector::insert(iterator position, size_type n, const T &x);
	template <class InputIterator>
	void vector::insert(iterator position, InputIterator first, InputIterator last);
	iterator vector::erase(iterator position);
	iterator vector::erase(iterator first, iterator last);
	void vector::swap(vector<T, Alloc> &);
	void vector::clear();
*/
