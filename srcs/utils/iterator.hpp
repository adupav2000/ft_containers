/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:04:16 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/05/08 13:51:28 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

#include "./iterators_traits.hpp"
namespace ft
{
	template <typename T>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{
	protected:

	public:
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer pointer;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference reference;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
	protected:
		pointer _pointer;

	public:
		random_access_iterator(void) : _pointer(NULL) {}
		random_access_iterator(pointer n_pointer) : _pointer(n_pointer) {}

		// constructor by copy
		random_access_iterator(random_access_iterator &rhs) : _pointer(rhs._pointer) {}

		// destructor
		~random_access_iterator();

		// assignation operator
		random_access_iterator &operator=(const random_access_iterator *rhs)
		{
			if (this != &rhs)
			{
				this->_pointer = rhs->_pointer;
			}
			return (*this);
		}

		// casting operator
		operator random_access_iterator<const T>(void) const
		{
			return random_access_iterator<const T>(this->_pointer);
		}

		pointer base(void) const
		{
			return (this->_pointer);
		}

		reference operator*(void)
		{
			return (*(this->_pointer));
		}

		reference operator*(void) const
		{
			return (*(this->_pointer));
		}

		pointer operator->(void) const
		{
			return (this->_pointer);
		}

		reference operator[](difference_type n)
		{
			return *(this->_pointer + n);
		}

		reference operator[](difference_type n) const
		{
			return *(this->_pointer + n);
		}

		random_access_iterator &operator+=(difference_type l)
		{
			this->_pointer += l;
			return (*this);
		}

		random_access_iterator &operator-=(difference_type l)
		{
			this->_pointer -= l;
			return (*this);
		}

		const random_access_iterator operator++(int)
		{
			this->_pointer++;
			return (this->_pointer);
		}

		random_access_iterator &operator++()
		{
			random_access_iterator tmp(this->pointer);
			this->_pointer++;
			return (tmp);
		}

		const random_access_iterator operator--(int)
		{
			this->_pointer--;
			return (*this);
		}

		random_access_iterator &operator--()
		{
			random_access_iterator tmp(this->_pointer);
			this->_pointer--;
			return (tmp);
		}

		random_access_iterator &operator+(difference_type n)
		{
			return (this->base() + n);
		}

		random_access_iterator &operator-(difference_type n)
		{
			return (this->base() - n);
		}

		bool operator==(random_access_iterator &rhs)
		{
			return (this->base() == rhs.base());
		}

		bool operator!=(random_access_iterator &rhs)
		{
			return (this->base() != rhs.base());
		}

		bool operator<=(random_access_iterator &rhs)
		{
			return (this->base() <= rhs.base());
		}

		bool operator>=(random_access_iterator &rhs)
		{
			return (this->base() >= rhs.base());
		}

		bool operator<(random_access_iterator &rhs)
		{
			return (this->base() < rhs.base());
		}

		bool operator>(random_access_iterator &rhs)
		{
			return (this->base() > rhs.base());
		}

		bool operator==(random_access_iterator<const T> &rhs) const
		{
			return (this->base() == rhs.base());
		}

		bool operator!=(random_access_iterator<const T> &rhs) const
		{
			return (this->base() != rhs.base());
		}

		bool operator<=(random_access_iterator<const T> &rhs) const
		{
			return (this->base() <= rhs.base());
		}

		bool operator>=(random_access_iterator<const T> &rhs) const
		{
			return (this->base() >= rhs.base());
		}

		bool operator<(random_access_iterator<const T> &rhs) const
		{
			return (this->base() < rhs.base());
		}

		bool operator>(random_access_iterator<const T> &rhs) const
		{
			return (this->base() > rhs.base());
		}
	};
	template <class T>
	class reverse_iterator : public ft::iterator_traits<T>
	{

	public:
		typedef T iterator_type;
		typedef typename iterator_traits<T>::difference_type difference_type;
		typedef typename iterator_traits<T>::reference reference;
		typedef typename iterator_traits<T>::pointer pointer;

	protected:
		iterator_type _current;

		reverse_iterator() : _current(NULL){};
		explicit reverse_iterator(iterator_type x) : _current(x){};
		template <class U>
		reverse_iterator(const reverse_iterator<U> &u) : _current(u->base()){};
		iterator_type base() const
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