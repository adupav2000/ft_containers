/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:32:11 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/05/10 21:57:45 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>

#include "../utils/iterator.hpp"
#include "../utils/rbtree.hpp"
#include "../utils/pair.hpp"
#include "../utils/make_pair.hpp"
#include "../utils/utils.hpp"
namespace ft
{
	/**
	 * @brief std::map is a sorted associative container that contains key-value
	 * pairs with unique keys. Keys are sorted by using the comparison function
	 * Compare. Search, removal, and insertion operations have logarithmic
	 * complexity. Maps are usually implemented as red-black trees
	 *
	 * @tparam Key
	 * @tparam T
	 * @tparam Compare
	 * @tparam std::allocator<ft::pair<const Key, T> >
	 */
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		typedef size_t size_type;
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		class value_compare
		{
		protected:
			Compare _comp;

		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;

			bool operator()(const value_type &x, const value_type &y) const
			{
				return _comp(x.first, y.first);
			}
		};

		typedef ft::rbtree<value_type, value_compare> tree_type;
		typedef typename tree_type::iterator iterator;
		typedef typename tree_type::const_iterator const_iterator;
		typedef typename tree_type::reverse_iterator reverse_iterator;
		typedef typename tree_type::const_reverse_iterator const_reverse_iterator;

	private:
		tree_type _tree;
		allocator_type _alloc;
		key_compare _keyComp;
		value_compare _valComp;

	public:
		explicit map(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type())
		{
			_alloc = alloc;
			_keyComp = comp;
			_valComp = value_compare();
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type())
		{
			_alloc = alloc;
			_keyComp = comp;
			_valComp = value_compare();
			insert(first, last);
		}

		map(const map &x)
		{
			*this = x;
		}

		map &operator=(const map &x)
		{
			_alloc = x._alloc;
			_keyComp = x._keyComp;
			_valComp = x._valComp;
			_tree = x._tree;
			clear();
			insert(x.begin(), x.end());
			return *this;
		}

		iterator begin(void)
		{
			return iterator(_tree.begin());
		}

		const_iterator begin(void) const
		{
			return const_iterator(_tree.begin());
		}

		iterator end(void)
		{
			return iterator(_tree.end());
		}

		const_iterator end(void) const
		{
			return const_iterator(_tree.end());
		}

		reverse_iterator rbegin(void)
		{
			return reverse_iterator(_tree.rbegin());
		}

		const_reverse_iterator rbegin(void) const
		{
			return const_reverse_iterator(_tree.rbegin());
		}

		reverse_iterator rend(void)
		{
			return reverse_iterator(_tree.rend());
		}

		const_reverse_iterator rend(void) const
		{
			return const_reverse_iterator(_tree.rend());
		}

		/**
		 * @brief checks whether the container is empty
		 * 
		 * @return true 
		 * @return false 
		 */
		bool empty(void) const
		{
			return _tree.size() == 0;
		}

		/**
		 * @brief returns the number of elements
		 * 
		 * @return size_type 
		 */
		size_type size(void) const
		{
			return _tree.size();
		}

		/**
		 * @brief returns the maximum possible number of elements
		 * 
		 * @return size_type 
		 */
		size_type max_size(void) const
		{
			return _tree.max_size();
		}
		
		/**
		 * @brief Returns a reference to the value that is mapped to a
		 * key equivalent to key, performing an insertion if such key
		 * does not already exist.
		 * 
		 * @param k 
		 * @return mapped_type& 
		 */
		mapped_type &operator[](const key_type &k)
		{
			return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
		}

		/**
		 * @brief inserts element(s) into the container, if the container
		 * doesn't already contain an element with an equivalent key.
		 * 
		 * @param val 
		 * @return pair<iterator, bool> 
		 */
		pair<iterator, bool> insert(const value_type &val)
		{
			return _tree.insert(val);
		}

		iterator insert(iterator position, const value_type &val)
		{
			return _tree.insert(position, val);
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			while (first != last)
				_tree.insert(*(first)++);
		}


		void erase(iterator position)
		{
			_tree.erase(position);
		}

		size_type erase(const key_type &k)
		{
			return _tree.erase(ft::make_pair(k, mapped_type()));
		}

		void erase(iterator first, iterator last)
		{
			while (first != last)
				_tree.erase(first++);
		}

		void swap(map &x)
		{
			tree_type tmp_tree = x._tree;
			allocator_type tmp_alloc = x._alloc;
			key_compare tmp_key_comp = x._keyComp;
			value_compare tmp_val_comp = x._valComp;

			x._alloc = _alloc;
			x._tree = _tree;
			x._keyComp = _keyComp;
			x._valComp = _valComp;

			_tree = tmp_tree;
			_alloc = tmp_alloc;
			_keyComp = tmp_key_comp;
			_valComp = tmp_val_comp;
		}

		void clear(void)
		{
			_tree.clear();
		}

		key_compare key_comp(void) const
		{
			return _keyComp;
		}

		value_compare value_comp(void) const
		{
			return _valComp;
		}

		/**
		 * @brief Finds an element with key equivalent to key.
		 * 
		 * @param k 
		 * @return iterator 
		 */
		iterator find(const key_type &k)
		{
			return _tree.find(ft::make_pair(k, mapped_type()));
		}

		/**
		 * @brief Finds an element with key equivalent to key.(same in const)
		 * 
		 * @param k 
		 * @return const_iterator 
		 */
		const_iterator find(const key_type &k) const
		{
			return _tree.find(ft::make_pair(k, mapped_type()));
		}

		/**
		 * @brief Returns the number of elements with key that compares equivalent
		 * to the specified argument, which is either 1 or 0 since this
		 * container does not allow duplicates.
		 * 
		 * @param k 
		 * @return size_type 
		 */
		size_type count(const key_type &k) const
		{
			return _tree.isIn(ft::make_pair(k, mapped_type()));
		}

		/**
		 * @brief Returns an iterator pointing to the first element that is
		 * not less than (i.e. greater or equal to) key.
		 * 
		 * @param k 
		 * @return iterator 
		 */
		iterator lower_bound(const key_type &k)
		{
			return _tree.lower_bound(ft::make_pair(k, mapped_type()));
		}

		const_iterator lower_bound(const key_type &k) const
		{
			return _tree.lower_bound(ft::make_pair(k, mapped_type()));
		}

		/**
		 * @brief Returns an iterator pointing to the first element
		 * that is greater than key.
		 * 
		 * @param k 
		 * @return iterator 
		 */
		iterator upper_bound(const key_type &k)
		{
			return _tree.upper_bound(ft::make_pair(k, mapped_type()));
		}

		const_iterator upper_bound(const key_type &k) const
		{
			return _tree.upper_bound(ft::make_pair(k, mapped_type()));
		}

		/**
		 * @brief Returns a range containing all elements with the
		 * given key in the container. The range is defined by two
		 * iterators, one pointing to the first element that is not
		 * less than key and another pointing to the first element
		 * greater than key.
		 * 
		 * @param k 
		 * @return ft::pair<iterator, iterator> 
		 */
		ft::pair<iterator, iterator> equal_range(const key_type &k)
		{
			iterator low = lower_bound(k);
			iterator up = upper_bound(k);
			return ft::make_pair(low, up);
		}
		ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			const_iterator low = lower_bound(k);
			const_iterator up = upper_bound(k);
			return ft::make_pair(low, up);
		}

		allocator_type get_allocator(void) const
		{
			return _alloc;
		}
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return !(rhs > lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return rhs < lhs;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap(ft::map<Key, T, Compare, Alloc> &lhs, ft::map<Key, T, Compare, Alloc> &rhs)
	{
		rhs.swap(lhs);
	}
}
#endif