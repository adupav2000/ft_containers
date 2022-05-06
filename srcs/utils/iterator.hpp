/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:04:16 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/05/06 11:53:08 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

#include "./iterators_traits.hpp"

namespace ft
{
	template <class T>
	class iterator : public ft::iterator_traits<T>
	{

	private:
		T *_pointer;

	public:
		typedef std::ptrdiff_t difference_type;

	public:
		iterator() : _pointer(NULL) {}
		~iterator();
		iterator(iterator &rhs) : _pointer(rhs._pointer) {}

		iterator(T *pointer): _pointer(pointer) {}

		T &operator=(iterator *rhs)
		{
			this->_pointer = rhs->_pointer;
		}

		T &operator+=(difference_type l)
		{
			this->_pointer += l;
		}

		T &operator-=(difference_type l)
		{
			this->_pointer -= l;
		}

		T operator++(iterator)
		{
			this->_pointer++;
			return (*this);
		}

		T &operator++()
		{
			iterator tmp(this->pointer);
			this->_pointer++;
			return (tmp);
		}

		T operator--(iterator)
		{
			this->_pointer--;
			return (*this);
		}

		T &operator--()
		{
			T *tmp;
			tmp = this->_pointer;
			this->_pointer--;
			return (tmp);
		}

		T &operator+(difference_type n)
		{
			return (this->_pointer + n);
		}

		T &operator-(difference_type n)
		{
			return (this->_pointer - n);
		}

		bool operator==(iterator *rhs)
		{
			return (this->_pointer == rhs->_pointer);
		}

		bool operator!=(iterator *rhs)
		{
			return (this->_pointer != rhs->_pointer);
		}

		bool operator<=(iterator *rhs)
		{
			return (this->_pointer <= rhs->_pointer);
		}

		bool operator>=(iterator *rhs)
		{
			return (this->_pointer >= rhs->_pointer);
		}

		bool operator<(iterator *rhs)
		{
			return (this->_pointer < rhs->_pointer);
		}

		bool operator>(iterator *rhs)
		{
			return (this->_pointer > rhs->_pointer);
		}
	};
};

#endif