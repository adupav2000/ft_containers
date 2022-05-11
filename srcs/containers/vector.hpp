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

#include "../utils/iterator.hpp"
#include "../utils/utils.hpp"
#include <memory>
#include <iostream>

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		// types
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename ft::random_access_iterator<value_type> iterator;
		typedef typename ft::random_access_iterator<const value_type> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const iterator> const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
		typedef typename std::size_t size_type;

	private:
		/* allocator */
		Alloc _allocator;
		/*returns the number of elements that can be
			held in currently allocated storage */
		size_type _capacity;
		/* First pointer to the list */
		pointer _data;
		/* Gives the size of the vector */
		size_type _size;

	public:
		// 23.2.4.1 construct/copy/destroy:
		explicit vector(const allocator_type &allocator = allocator_type())
			: _allocator(allocator),
			  _capacity(0),
			  _data(u_nullptr),
			  _size(0)
		{
		}

		explicit vector(size_type n, const T &value = T(), const allocator_type &allocator = allocator_type())
			: _allocator(allocator),
			  _capacity(0),
			  _data(u_nullptr),
			  _size(0)
		{
			this->_size = n;
			this->_capacity = n;
			try
			{
				this->_data = this->_allocator.allocate(this->_capacity);
				for (size_t i = 0; i < this->_size; i++)
				{
					this->_allocator.construct(&_data[i], value);
				}
			}
			catch (std::bad_alloc &ba)
			{
				std::cerr << "bad_alloc caught: " << ba.what() << '\n';
			}
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &allocator = allocator_type())
			: _allocator(allocator), _capacity(0), _data(u_nullptr), _size(0)
		{
			ptrdiff_t n;

			n = 0;
			while ((first + n) != last)
				n++;
			this->_size = n;
			// check if n > 0
			this->_capacity = n;
			this->_data = this->_allocator.allocate(this->_capacity);
			for (int i = 0; (first + i) != last; i++)
			{
				n = i;
				this->_allocator.construct(&_data[i], *first);
				first++;
			}
			this->_allocator.construct(&_data[n], *first);
		}

		/**
		 * @brief Construct a new vector object
		 *
		 * @param x
		 */
		vector(const vector<T, Alloc> &x)
			: _allocator(x.get_allocator()), _capacity(x.capacity()), _data(u_nullptr), _size(x.size())
		{
			this->_data = this->_allocator.allocate(this->_capacity);
			for (size_type i = 0; i < x.size(); i++)
				this->push_back(x.at(i));
		}

		~vector()
		{
			for (int i = this->_size - 1; i > 0; i--)
				this->_allocator.destroy((this->_data + i));
			this->_allocator.deallocate(this->_data, this->_capacity);
		}

		vector &operator=(const vector<T, Alloc> &x)
		{
			if (x == *this)
				return (*this);
			//deep copy
			this->clear();
			this->insert(this->begin(), x.begin(), x.end());
			return (*this);
		}

		/**
		 * @brief Assigns new contents to the vector, replacing
		 * its current contents, and modifying its size accordingly.
		 *
		 * @tparam InputIterator
		 * @param first
		 * @param last
		 */
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			this->erase(this->begin());
			this->insert(this->begin(), first, last);
		}

		/**
		 * @brief  Replaces the contents with count copies of value value
		 *
		 * @param n the new size of the container
		 * @param u the value to initialize elements of the container with
		 */
		void assign(size_type n, const T &u)
		{
			this->erase(this->begin(), this->end());
			this->insert(this->begin(), n, u);
		}

		allocator_type get_allocator() const
		{
			return (this->_allocator);
		}

		// iterators:
		/*Will return an iterator to *_start*/
		iterator begin()
		{
			return (_data);
		}

		/*will return a const iterator to *start */
		const_iterator begin() const
		{
			return ((const_iterator(this->_data)));
		}
		/*will return a iterator the last adress of memory */
		iterator end()
		{
			return ((iterator(&(this->_data[this->_size - 1]))));
		}
		/*will return a const iterator the last adress of memory */
		const_iterator end() const
		{
			return ((const_iterator(&(this->_data[this->_size - 1]))));
		}

		reverse_iterator rbegin()
		{

			return ((reverse_iterator(this->_data)));
		}
		const_reverse_iterator rbegin() const
		{
			return ((const_reverse_iterator(this->_data)));
		}
		reverse_iterator rend()
		{
			return ((reverse_iterator(&(this->_data[this->_size - 1]))));
		}
		const_reverse_iterator rend() const
		{
			return ((const_reverse_iterator(&(this->_data[this->_size - 1]))));
		}

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

		/**
		 * @brief resizes and changes the value
		 *
		 * @param sz give the new size of the vector
		 * @param c the value the new vectors element will be assigned
		 */
		void resize(size_type sz, T c = T())
		{
			pointer new_data;

			// sz < size les element dont la position > _sz sont supprimé
			if (this->_size > sz)
			{
				for (size_t i = sz + 1; i < this->_size; i++)
					_allocator.destroy(&_data[i]);
				this->_size = sz;
			}
			else if (sz > this->_size && sz < this->_capacity)
			{
				// sz > size et _size < capacity -> on rajoute l'élément "c" a toute les position manquante
				for (size_t i = this->_size; i < sz; i++)
					this->push_back(c);
			}
			// sz > _size et _size > capacity -> on réallou la mémoire après avoir delete l'ancienne, on remplie les case en plus avec la valeur c
			else if (sz > this->_size && sz >= this->_capacity)
			{
				// allocate new
				new_data = _allocator.allocate(sz);
				this->_capacity = sz;
				for (size_t i = 0; i < this->_size; i++)
					_allocator.construct(&new_data[i], this->_data[i]);
				// copy to the next
				for (size_t i = this->_size; i < sz; i++)
					_allocator.construct(&new_data[i], c);

				// freeing memory
				for (int i = this->_size - 1; i > 0; i--)
					_allocator.destroy((this->_data + i));
				_allocator.deallocate(this->_data, this->_size);

				this->_data = new_data;
				this->_size = sz;
			}
		}

		/*will return a sze that is always a 2^n superior to size*/
		size_type capacity() const
		{
			return (this->_capacity);
		}

		/*returns true only if the _size parameter is == 0*/
		bool empty() const
		{
			return (this->_size == 0);
		}

		/**
		 * @brief Increase the capacity of the vector (the total number of elements that
		 *  the vector can hold without requiring reallocation) to a value that's greater
		 *  or equal to new_cap. If new_cap is greater than the current capacity(), new
		 *  storage is allocated, otherwise the function does nothing
		 *
		 * @param n
		 */
		void reserve(size_type n)
		{
			if (n <= this->_capacity)
				return;
			if (n > this->max_size())
				throw std::length_error("vector::reserve");
			pointer new_data = this->_allocator.allocate(n);
			for (size_t i = 0; i < this->_size; i++)
			{
				_allocator.construct(&(new_data[i]), this->_data[i]);
				_allocator.destroy(&(this->_data[i]));
			}
			this->_data = new_data;
		}
		// element access:

		/**
		 * @brief Returns a reference to the element at position n in the vector container.
		 *
		 * @param n
		 * @return reference
		 */
		reference operator[](size_type n)
		{
			return (this->_data[n]);
		}

		const_reference operator[](size_type n) const
		{
			return (this->_data[n]);
		}

		const_reference at(size_type n) const
		{
			if (n >= this->_size)
				throw std::out_of_range("vector");
			const_reference ret = _data[n];
			return (ret);
		}

		reference at(size_type n)
		{
			if (n > this->_size)
				throw std::out_of_range("vector");
			reference ret = _data[n];
			return (ret);
		}

		/**
		 * @brief Returns a reference to the first element in the vector.
		 *
		 * @return reference
		 */
		reference front()
		{
			reference ret = *_data;
			return (ret);
		}
		const_reference front() const
		{
			const reference ret = *_data;
			return (ret);
		}

		/**
		 * @brief Returns a reference to the last element in the vector.
		 * https://www.cplusplus.com/reference/vector/vector/assign/
		 *
		 *
		 * @return reference
		 */
		reference back()
		{
			reference ret = (_data[_size - 1]);
			return (ret);
		}

		const_reference back() const
		{
			const_reference ret = (_data[_size - 1]);
			return (ret);
		}

		// 23.2.4.3 modifiers:
		void push_back(const T &x)
		{
			if (_size < _capacity)
			{
				this->_allocator.construct(&(this->_data[this->_size]), x);
				this->_size++;
			}
			else
			{
				// enew allocate
				pointer new_data = _allocator.allocate(this->_capacity * 2);
				// copy old information
				for (size_t i = 0; i < this->_size; i++)
				{
					_allocator.construct(&(new_data[i]), this->_data[i]);
					_allocator.destroy(&(this->_data[i]));
				}
				_allocator.deallocate(this->_data, this->_size);
				this->_size++;
				this->_capacity *= 2;
				_allocator.construct((&new_data[this->_size]), x);
				this->_data = new_data;
			}
		}

		void pop_back()
		{
			if (this->_size > 1)
			{
				this->_allocator.destroy(&(this->_data[this->_size]));
				this->_size--;
			}
		}

		/**
		 * @brief The vector is extended by inserting new elements before
		 * the element at the specified position, effectively increasing
		 * the container size by the number of elements inserted.
		 *
		 * This causes an automatic reallocation of the allocated storage
		 * space if -and only if- the new vector size surpasses the current
		 * vector capacity.
		 *
		 * @param position
		 * @param x
		 * @return std::iterator<std::random_access_iterator_tag, T>
		 */
		iterator insert(iterator position, const T &x)
		{
			// 1. tenter d'augmenter la reserve
			// 2. rajouter les elements
			// pas oblige de rajouter des condition vu que la resrve augmentera ou pas la taille
			// TO VERIFY - is the return value right
			if (!(position <= this->_data + this->_size && position >= this->_data))
			{
				return (_data);
			}
			// check if capacity is enough
			if (this->_size + 1 > this->_capacity)
				this->resize(this->_size * 2);
			pointer save_data = this->_allocator.allocate(this->end() - position + 1);
			// save the value
			// if
			size_t s = 0;
			size_t d = 0;
			for (size_t i = 0; i < this->_size + 1; i++)
			{
				if (this->_data[i] == *position)
				{
					this->_allocator.construct(&(save_data[s++]), this->_data[i]);
					this->_allocator.construct(&(this->_data[i]), x);
					d++;
					i++;
				}
				this->_allocator.construct(&(save_data[s++]), this->_data[i]);
				this->_allocator.construct(&(this->_data[i]), save_data[s - d - 1]);
				this->_allocator.destroy(&(save_data[s - d - 1]));
			}
			this->_allocator.deallocate(save_data, s);
			return (position - 1);
		}

		/**
		 * @brief The vector is extended by inserting new elements before
		 * the element at the specified position, effectively increasing the
		 * container size by the number of elements inserted.
		 * This causes an automatic reallocation of the allocated storage
		 * space if -and only if- the new vector size surpasses the current vector capacity.
		 * https://www.cplusplus.com/reference/vector/vector/insert/
		 *
		 * @param position
		 * @param n
		 * @param x
		 */
		void insert(iterator position, size_type n, const T &x)
		{
			if (!(position <= this->end() && position >= this->begin()))
			{
				throw std::length_error("vector::_M_fill_insert");
			}
			size_type new_len = this->_size;
			// check if capacity is enough
			while (this->_size + n > this->_capacity && new_len < n)
				new_len *= 2;
			if (this->_size + n > this->capacity())
				this->resize(new_len);
			size_type save_data_size = this->end() - position + n + 1;
			pointer save_data = this->_allocator.allocate(save_data_size);
			// save the value
			size_t s = 0;
			size_t d = 0;
			iterator beg = this->begin();
			for (size_t i = 0; i < this->_size + n; i++)
			{
				if (beg + i == position)
				{
					while (s < n)
					{
						this->_allocator.construct(&(save_data[s++]), this->_data[i]);
						this->_allocator.construct(&(this->_data[i]), x);
						d++;
						i++;
					}
				}
				if (s > 0)
				{
					this->_allocator.construct(&(save_data[s++]), this->_data[i]);
					this->_allocator.construct(&(this->_data[i]), save_data[s - d - 1]);
					this->_allocator.destroy(&(save_data[s - d - 1]));
				}
				else
				{
					this->_allocator.construct(&(this->_data[i]), this->_data[i]);
				}
			}
			this->_size += n;
			this->_allocator.deallocate(save_data, save_data_size);
			return;
		}

		template <class InputIterator>
		void insert(iterator position,
					InputIterator first, InputIterator last)
		{
			if (!(position <= this->end() && position >= this->begin()))
			{
				throw std::length_error("vector::_M_fill_insert");
			}
			size_type new_len = this->_size;
			// check if capacity is enough
			size_t dist = last - first;
			while (this->_size + dist > this->_capacity && new_len < dist)
				new_len *= 2;
			if (this->_size + dist > this->capacity())
				this->resize(new_len);
			size_type save_data_size = this->end() - position + dist + 1;
			pointer save_data = this->_allocator.allocate(save_data_size);
			// save the value
			size_t s = 0;
			size_t d = 0;
			iterator beg = this->begin();
			for (size_t i = 0; i < this->_size + dist; i++)
			{
				if (beg + i == position)
				{
					while (s < dist)
					{
						this->_allocator.construct(&(save_data[s++]), this->_data[i]);
						this->_allocator.construct(&(this->_data[i]), *first);
						first++;
						d++;
						i++;
					}
				}
				if (s > 0)
				{
					this->_allocator.construct(&(save_data[s++]), this->_data[i]);
					this->_allocator.construct(&(this->_data[i]), save_data[s - d - 1]);
					this->_allocator.destroy(&(save_data[s - d - 1]));
				}
				else
				{
					this->_allocator.construct(&(this->_data[i]), this->_data[i]);
				}
			}
			this->_size += dist;
			this->_allocator.deallocate(save_data, save_data_size);
			return;
			// // check that the position iterator is in the right place
			// if (!(position < this->_data + this->_size && position > this->_data))
			// 	return (_data);
			// // check if capacity is enough
			// size_type length_to_insert = first - last;
			// size_type new_len = this->_size + length_to_insert;
			// if (new_len > this->max_size())
			// 	throw std::length_error("vector::reserve");
			// if (this->_size + length_to_insert > this->_capacity)
			// {
			// 	try
			// 	{
			// 		pointer new_data;
			// 		new_data = this->_allocator.allocate(this->_capacity * 2);
			// 		for (size_t i = 0; i < this->_size + 1; i++)
			// 		{
			// 			if (this->_data[i] == position)
			// 			{
			// 				this->_allocator.construct(new_data[i], x);
			// 				i++;
			// 			}
			// 			this->_allocator.construct(new_data[i], this->_data[i]);
			// 			this->_allocator.destroy(this->_data[i]);
			// 		}
			// 		this->_allocator.deallocate(this->_data);
			// 		this->_data = new_data;
			// 	}
			// 	catch (const std::exception &e)
			// 	{
			// 		std::cerr << e.what() << '\n';
			// 	}
			// }
			// else
			// {
			// 	T tmp;
			// 	T tmp_2;
			// 	size_t offset = 0;
			// 	for (size_t i = 0; i < this->_size + 1; i++)
			// 	{
			// 		if (this->_data[i] == position)
			// 		{
			// 			tmp = this->_data[i];
			// 			this->_data[i] = x;
			// 			offset = 1;
			// 		}
			// 		tmp_2 = this->_data[i + offset];
			// 		this->_data[i + offset] = tmp;
			// 		tmp = tmp_2;
			// 	}
			// }
			// return (position - 1);
		}

		/**
		 * @brief Removes from the vector either a single element
		 * (position) or a range of elements ([first,last)).
		 * This effectively reduces the container size by the
		 * number of elements removed, which are destroyed.
		 *
		 * @param position
		 * @return std::iterator<std::random_access_iterator_tag, T>
		 */
		iterator erase(iterator position)
		{
			if (!(position <= this->end() && position >= this->begin()))
			{
				throw std::length_error("vector::_M_fill_insert");
			}
			this->_size -= (this->end() - position);
			iterator tmp = position;
			position--;
			while (tmp != this->end())
				this->_allocator.destroy((tmp++).base());
			return (position);
		}

		iterator erase(iterator first, iterator last)
		{
			if (!(first <= this->end() && first >= this->begin()))
			{
				throw std::length_error("vector::_M_fill_insert");
			}
			this->_size -= last - first;
			iterator tmp = first;
			first--;
			while (tmp != this->end() && tmp != last)
				this->_allocator.destroy((tmp++).base());
			return (first);
		}

		/**
		 * @brief Exchanges the content of the container by the content
		 * of x, which is another vector object of the same type. Sizes may differ.
		 *
		 */
		void swap(vector<T, Alloc> &x)
		{
			Alloc tmp_allocator = this->get_allocator();
			size_type tmp_capacity = this->capacity();
			pointer tmp_data = this->_data;
			size_type tmp_size = this->size();

			x._allocator = this->_allocator;
			x._capacity = this->_capacity;
			x._data = this->_data;
			x._size = this->_size;

			this->_allocator = tmp_allocator;
			this->_capacity = tmp_capacity;
			this->_data = tmp_data;
			this->_size = tmp_size;
		}

		/**
		 * @brief Removes all elements from the vector (which are destroyed),
		 * leaving the container with a size of 0.
		 *
		 */
		void clear()
		{
			for (size_t i = this->_size; i > 0; i--)
				_allocator.destroy(&(_data[i]));
			this->_size = 0;
		}
	};

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &x, const vector<T, Alloc> &y)
	{
		typedef ft::random_access_iterator<const typename vector<T, Alloc>::value_type> iterator;
		iterator x_beg = x.begin();
		iterator x_last = x.end();
		iterator y_beg = y.begin();
		iterator y_last = y.end();
		while (x_beg != x_last && y_beg != y_last)
		{
			// the opposite is confirmed -> assertion false
			if (*x_beg > *y_beg)
				return (false);
			if (*x_beg < *y_beg)
				return (true);
			++y_beg;
			++x_beg;
		}
		// if y is not at the end, it is undeniably bigger
		if (y_beg != y_last)
			return (true);
		return (false);
	};

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &x, const vector<T, Alloc> &y)
	{
		typedef ft::random_access_iterator<const typename vector<T, Alloc>::value_type> iterator;
		iterator x_beg = x.begin();
		iterator x_last = x.end();
		iterator y_beg = y.begin();
		iterator y_last = y.end();
		while (x_beg != x_last && y_beg != y_last)
		{
			// the opposite is confirmed -> assertion false
			if (*x_beg > *y_beg)
				return (false);
			if (*x_beg < *y_beg)
				return (true);
			++y_beg;
			++x_beg;
		}
		// if y is not at the end, it is undeniably bigger
		if (y_beg != y_last)
			return (true);
		return (false);
	};

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &x, const vector<T, Alloc> &y)
	{
		typedef ft::random_access_iterator<const typename vector<T, Alloc>::value_type> iterator;
		iterator x_beg = x.begin();
		iterator x_last = x.end();
		iterator y_beg = y.begin();
		iterator y_last = y.end();
		while (x_beg != x_last && y_beg != y_last)
		{
			if (*y_beg != *x_beg)
				return (false);
			++y_beg;
			++x_beg;
		}
		// if one of them is not at the end -> not equal
		if (x_beg != x_last || y_beg != y_last)
			return (false);
		return (true);
	};

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &x, const vector<T, Alloc> &y)
	{
		typedef ft::random_access_iterator<const typename vector<T, Alloc>::value_type> iterator;
		iterator x_beg = x.begin();
		iterator x_last = x.end();
		iterator y_beg = y.begin();
		iterator y_last = y.end();
		while (x_beg != x_last && y_beg != y_last)
		{
			// the opposite is confirmed -> assertion false
			if (*x_beg < *y_beg)
				return (false);
			if (*x_beg> *y_beg)
				return (true);
			++y_beg;
			++x_beg;
		}
		// if x is not at the end, it is undeniably bigger
		if (x_beg != x_last)
			return (true);
		return (false);
	};

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &x, const vector<T, Alloc> &y)
	{
		typedef ft::random_access_iterator<const typename vector<T, Alloc>::value_type > iterator;
		iterator x_beg = x.begin();
		iterator x_last = x.end();
		iterator y_beg = y.begin();
		iterator y_last = y.end();
		while (x_beg != x_last && y_beg != y_last)
		{
			// the opposite is confirmed -> assertion false
			if (*x_beg < *y_beg)
				return (false);
			if (*x_beg > *y_beg)
				return (true);
			++y_beg;
			++x_beg;
		}
		// if y is not the last one, it's size is considered bigger
		if (y_beg != y_last)
			return (false);
		// they are equal or the size of x is bigger :> true
		return (true);
	};

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &x, const vector<T, Alloc> &y)
	{
		typedef ft::random_access_iterator<const typename vector<T, Alloc>::value_type > iterator;
		iterator x_beg = x.begin();
		iterator x_last = x.end();
		iterator y_beg = y.begin();
		iterator y_last = y.end();
		while (x_beg != x_last && y_beg != y_last)
		{
			// the opposite is confirmed -> assertion false
			if (*x_beg > *y_beg)
				return (false);
			if (*x_beg < *y_beg)
				return (true);
			++y_beg;
			++x_beg;
		}
		// if x is not the last one, it's size is considered bigger
		if (x_beg != x_last)
			return (false);
		// they are equal or the size of y is bigger :> true
		return (true);
	};

	// // specialized algorithms:
	// template <class T, class Alloc>
	// void ft::vector<T, Alloc>::swap(vector &x, vector &y)
	// {
	// 	(void)y;
	// }
}

#endif