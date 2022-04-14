/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 06:13:22 by AlainduPa         #+#    #+#             */
/*   Updated: 2022/04/12 08:08:57by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include <iterator>
namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		// types
		typedef typename Alloc::reference reference;
		typedef typename Alloc::const_reference const_reference;
		typedef std::iterator<std::random_access_iterator_tag, T> iterator;
		typedef const std::iterator<std::random_access_iterator_tag, T> const_iterator;
		typedef typename Alloc::size_type size_type;
		typedef typename Alloc::difference_type difference_type;
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename Alloc::pointer pointer;
		typedef typename Alloc::const_pointer const_pointer;
		typedef std::reverse_iterator<T> reverse_iterator;
		typedef std::reverse_iterator<T> const_reverse_iterator;

	private:
		Alloc _allocator;
		/*returns the number of elements that can be
			held in currently allocated storage */
		size_type _capacity;
		/* First pointer to the list */
		T *_data;
		/* Gives the size of the vector */
		size_type _size;

	public:
		// 23.2.4.1 construct/copy/destroy:

		explicit vector(const Alloc &allocator = allocator_type())
			: _allocator(allocator), _capacity(0), _data(nullptr), _size(0)
		{
		}
		explicit vector(size_type n, const T &value = T(), const Alloc &allocator = allocator_type())
			: _allocator(allocator), _capacity(0), _data(nullptr), _size(0)
		{
			// quoi qu'il arrive la capacity est a 1
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
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const Alloc &allocator = allocator_type())
			: _allocator(allocator), _capacity(0), _data(nullptr), _size(0)
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
		vector(const vector<T, Alloc> &x)
			: _allocator(x->get_allocator()), _capacity(x->capacity()), _data(nullptr), _size(x->size())
		{
			_data = _allocator.allocate(_capacity);
			for (size_t i = 0; i < x->size(); i++)
				this->push_back(*(x->begin() + i));
		}
		~vector()
		{
			for (size_t i = this->_size - 1; i > 0 ; i--)
				_allocator.destroy((this->_data + i));
					_allocator.deallocate(_data, _capacity);
		}
		vector<T, Alloc> &operator=(const vector<T, Alloc> &x);
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last);
		void assign(size_type n, const T &u);
		allocator_type get_allocator() const
		{
			return (this->_allocator);
		}
		// iterators:
		/*Will return an iterator to *_start*/
		std::iterator<std::random_access_iterator_tag, T> begin();
		/*will return a const iterator to *start */
		const std::iterator<std::random_access_iterator_tag, T> begin() const;
		/*will return a iterator the last adress of memory */
		std::iterator<std::random_access_iterator_tag, T> end();
		/*will return a const iterator the last adress of memory */
		const std::iterator<std::random_access_iterator_tag, T> end() const;

		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		// 23.2.4.2 capacity:
		/*return the _size param, that refers to the number of element stored*/
		size_type size() const
		{
			return (this->_size);
		}

		/*return the max size of the vector, just a reference to the allocator.max_size*/
		size_type max_size() const
		{
			return (this->_allocator.max_size());
		}

		/**/
		void resize(size_type sz, T c = T());
		/*will return a sze that is always a 2^n superior to size*/
		size_type capacity() const
		{
			return (this->_capacity);
		}
		/*returns true only if the _size parameter is ==0*/
		bool empty() const;
		void reserve(size_type n);
		// element access:
		reference operator[](size_type n);
		const_reference operator[](size_type n) const;
		const_reference at(size_type n) const;
		reference at(size_type n);
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		// 23.2.4.3 modifiers:
		void push_back(const T &x)
		{
			if (_size + 1 < _capacity)
			{
				_allocator.construct(&_data[_size], x);
				_size++;
			}
			&_data[_size] = nullptr;
			// else copy the whole thing to another location that is progressively constructed, but allocated at first
		}
		void pop_back()
		{
			_allocator.destroy(&_data[_size - 1]);
		}
		std::iterator<std::random_access_iterator_tag, T> insert(iterator position, const T &x);
		void insert(iterator position, size_type n, const T &x);
		template <class InputIterator>
		void insert(iterator position,
					InputIterator first, InputIterator last);
		std::iterator<std::random_access_iterator_tag, T> erase(iterator position);
		std::iterator<std::random_access_iterator_tag, T> erase(iterator first, iterator last);
		void swap(vector<T, Alloc> &);
		void clear();
	};
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &x,
					const vector<T, Alloc> &y);
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &x,
				   const vector<T, Alloc> &y);
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &x,
					const vector<T, Alloc> &y);
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &x,
				   const vector<T, Alloc> &y);
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &x,
					const vector<T, Alloc> &y);
	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &x,
					const vector<T, Alloc> &y);
	// specialized algorithms:
	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y);
}

#endif