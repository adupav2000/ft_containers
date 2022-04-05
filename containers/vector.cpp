/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:14:16 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/04/05 18:26:08 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

namespace ft{
	template <class T, class Allocator = allocator<T>>
	vector::vector() : _allocator(Allocator),
					_capacity(0),
					_data(nullptr),
					_lenght(0)
	{
		
	}

	vector::vector(const Allocator& = Allocator()) :  _allocator(Allocator.pointer), _capacity()
	{

	}

	size_type vector::size() const
	{
		return (_length);
	}

	size_type vector::max_size() const
	{
		return (this->_allocator.max_size())
	}
	size_type vector::capacity() const
	{
		return (this->_capacity);
	}
	explicit vector(const Allocator& = Allocator())
	{

	}
	explicit vector(size_type n, const T& value = T(), const Allocator& = Allocator());

			template <class InputIterator>
			vector(InputIterator first, InputIterator last,
				const Allocator& = Allocator());
			vector(const vector<T,Allocator>& x);
}