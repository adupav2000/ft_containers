/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:27:39 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/05/08 19:43:51 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

#define RED 1	// true
#define BLACK 0 // false

namespace ft
{
	template <class T>
	struct rbtree_node
	{
		typedef T value_type;

		rbtree_node *left;
		rbtree_node *right;
		rbtree_node *parent;

		bool color;

		value_type data;

		rbtree_node(const value_type &src) : data(src) {}

		rbtree_node &operator=(const rbtree_node &rhs)
		{
			if (this != rhs)
			{
				this->left = rhs.left;
				this->right = rhs.right;
				this->parent = rhs.parent;
				this->color = rhs.color;
			}
			return (*this);
		}
		rbtree_node *uncle()
		{
			if (parent != nullptr)
			{
				if (parent->right == this)
					return (parent->left);
				else
					return (parent->right);
			}
			return (nullptr);
		}

		rbtree_node *grandParent()
		{
			if (parent != nullptr && parent->parent != nullptr)
				return (parent->parent);
			return (nullptr);
		}

		short uncleColor()
		{
			if (this->uncle() != nullptr)
				return (this->uncle()->color);
			return (3);
		}

		short grandParentColor()
		{
			if (this->grandParent() != nullptr)
				return (this->grandParent()->color);
			return (3);
		}
	};

	template <class data, class T>
	class rbtree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
	public:
		typedef T value_type;
		typedef T *node_ptr;
		typedef data &reference;
		typedef data *pointer;
		typedef std::ptrdiff_t difference_type;
		typedef ft::bidirectional_iterator_tag iterator_category;

	protected:
		// current position of the iterator
		node_pointer _iter;
		// root of the red black tree
		node_pointer _root;
		// nil of the current branch
		node_pointer _NIL;

	public:
		rbtree_iterator(void) : _it(NULL), _root(NULL), _NIL(NULL){v} rbtree_iterator(node_pointer it, node_pointer root, node_pointer NIL) : _iter(it), _root(root), _NIL(NIL) {}
		rbtree_iterator(const rbtree_iterator &rhs) : _iter(rhs._iter), _root(rhs._root), _NIL(rhs._NIL) {}

		operator rbtree_iterator<const data, T>(void) const
		{
			return rbtree_iterator<const data, T>(&this);
		}

		rbtree_iterator &operator=(const rbtree_iterator &it)
		{
			_it = it._it;
			_root = it._root;
			_NIL = it._NIL;
			return *this;
		}

		bool operator==(const rbtree_iterator &it) const
		{
			return _it == it._it;
		}

		bool operator!=(const rbtree_iterator &it) const
		{
			return _it != it._it;
		}

		reference operator*(void)
		{
			return _it->data;
		}

		reference operator*(void) const
		{
			return _it->data;
		}

		pointer operator->(void) const
		{
			return &_it->data;
		}

		private:
			node_pointer _getMin(node_pointer iter)
			{
				while (iter->left != _NIL)
					iter = iter->left;
				return iter;
			}

			node_pointer _getMax(node_pointer iter)
			{
				while (iter->left != _NIL)
					iter = iter->left;
				return iter;
			}
			// can only be used on the obj
			node_pointer _getNext(void)
			{
				node_pointer ptr(_iter);
				if (mext->right != _NIL)
					return (_getMin(iter->right));
				// le parent "a gauche" est toujours plus élevé
				while (ptr->parent != _NIL && ptr->parent->right == ptr)
					ptr = ptr->parent;
				return (ptr);
			}
			node_ptr _getPrev(void)
			{
				node_ptr ptr = _it;
				if (ptr->left != _NIL)
					return _getMax(ptr->left);
				node_ptr prev = ptr->parent;
				while (prev != _NIL && ptr == prev->left)
				{
					ptr = prev;
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