/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:01:27 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/05/12 20:56:04 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_ITERATOR_HPP
#define RBTREE_ITERATOR_HPP

#include "utils.hpp"
#include "iterator.hpp"

namespace ft
{
	template <class data, class T>
	class rbtree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef T								value_type;
			typedef T*								node_ptr;
			typedef data&							reference;
			typedef data*							pointer;
			typedef std::ptrdiff_t					difference_type;
			typedef ft::bidirectional_iterator_tag	iterator_category;

		protected:
			node_ptr	_current;
			node_ptr	_root;
			node_ptr	_NIL;

		public:
			rbtree_iterator(void) : _current(NULL), _root(NULL), _NIL(NULL) {}
			rbtree_iterator(node_ptr it, node_ptr root, node_ptr NIL) : _current(it), _root(root), _NIL(NIL) {}
			rbtree_iterator(const rbtree_iterator &cpy) : _current(cpy._current), _root(cpy._root), _NIL(cpy._NIL) {}

			operator rbtree_iterator<const data, T>(void) const
			{
				return rbtree_iterator<const data, T>(_current, _root, _NIL);
			}

			rbtree_iterator &operator=(const rbtree_iterator &it)
			{
				_current = it._current;
				_root = it._root;
				_NIL = it._NIL;
				return *this;
			}

			bool operator==(const rbtree_iterator &it) const
			{
				return _current == it._current;
			}

			bool operator!=(const rbtree_iterator &it) const
			{
				return _current != it._current;
			}

			reference operator*(void)
			{
				return _current->data;
			}

			reference operator*(void) const
			{
				return _current->data;
			}

			pointer operator->(void) const
			{
				return &_current->data;
			}

			rbtree_iterator &operator++(void)
			{
				if (_current != _NIL)
					_current = _getNext();
				return *this;
			}

			rbtree_iterator operator++(int)
			{
				rbtree_iterator tmp(*this);
				++(*this);
				return tmp;
			}

			rbtree_iterator &operator--(void)
			{
				if (_current != _NIL)
					_current = _getPrev();
				else
					_current = _getMax(_root);
				return *this;
			}

			rbtree_iterator operator--(int)
			{
				rbtree_iterator tmp(*this);
				--(*this);
				return tmp;
			}

			node_ptr base(void) const
			{
				return _current;
			}

		private:
			node_ptr _getMin(node_ptr n)
			{
				while (n->left != _NIL)
					n = n->left;
				return n;
			}

			node_ptr _getMax(node_ptr n)
			{
				while (n->right != _NIL)
					n = n->right;
				return n;
			}

			node_ptr _getNext(void)
			{
				node_ptr n = _current;
				if (n->right != _NIL)
					return _getMin(n->right);
				node_ptr next = n->parent;
				while (next != _NIL && n == next->right)
				{
					n = next;
					next = next->parent;
				}
				return next;
			}

			node_ptr _getPrev(void)
			{
				node_ptr n = _current;
				if (n->left != _NIL)
					return _getMax(n->left);
				node_ptr prev = n->parent;
				while (prev != _NIL && n == prev->left)
				{
					n = prev;
					prev = prev->parent;
				}
				return prev;
			}
	};

	template <class data, class T1, class T2>
	bool operator==(const rbtree_iterator<data, T1> &it1, const rbtree_iterator<data, T2> &it2)
	{
		return it1.base() == it2.base();
	}

	template <class data, class T1, class T2>
	bool operator!=(const rbtree_iterator<data, T1> &it1, const rbtree_iterator<data, T2> &it2)
	{
		return !(it1 == it2);
	}
}

#endif
