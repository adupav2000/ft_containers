/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:39:22 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/05/06 10:12:51y adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FT_REVERSE_ITERATOR_HPP
#define FT_REVERSE_ITERATOR_HPP

#include "./iterators_traits.hpp"
#include "./iterator.hpp"

namespace ft
{
	template <class T>
	class reverse_iterator : public ft::iterator_traits<T>
	{
	protected:
		iterator<T> _current;

	public:
		typedef iterator<T> iterator_type;
		typedef typename iterator_traits<iterator<T> >::difference_type difference_type;
		typedef typename iterator_traits<iterator<T> >::reference reference;
		typedef typename iterator_traits<iterator<T> >::pointer pointer;

		reverse_iterator() : _current(NULL){};
		explicit reverse_iterator(iterator<T> x) : _current(x){};
		template <class U>
		reverse_iterator(const reverse_iterator<U> &u) : _current(u->base()){};
		iterator<T> base() const
		{
			return (this->_current);
		}
		reverse_iterator &operator++()
		{
			reverse_iterator tmp(this->_current);
			this->_current--;
			return (tmp);
		}
		reverse_iterator operator++(int)
		{
			this->_current--;
			return (*this);
		}
		reverse_iterator &operator--()
		{
			reverse_iterator &tmp(this->_current);
			this->_current++;
			return (tmp);
		}
		reverse_iterator operator--(int)
		{
			this->_current--;
			return (*this);
		}
		reverse_iterator operator+(difference_type n) const
		{
			reverse_iterator tmp(this->_current - n);
			return (tmp);
		}
		reverse_iterator &operator+=(difference_type n)
		{
			this->_current = this->_current - n;
			return (*this);
		}
		reverse_iterator operator-(difference_type n) const
		{
			reverse_iterator tmp(this->_current + n);
			return (tmp);
		}
		reverse_iterator &operator-=(difference_type n)
		{
			this->_current = this->_current + n;
			return (*this);
		}
		reference operator[](difference_type n) const
		{
			return (*(operator+(n)));
		}
	};
};

#endif