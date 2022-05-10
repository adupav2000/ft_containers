/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:27:39 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/05/10 21:10:13 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "iterator.hpp"
#include "pair.hpp"
#include "utils.hpp"

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

	template <class T, class Compare, class Alloc = std::allocator<rbtree_node<T> > >
	class rbtree
	{
		public:
			typedef T												value_type;
			// by default is less defined in utils
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef size_t											size_type;
			typedef rbtree_node<value_type>							node;
			typedef node*											node_ptr;
			typedef ft::rbtree_iterator<value_type, node>			iterator;
			typedef ft::rbtree_iterator<const value_type, node>		const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		protected:
			node_ptr										_root;
			node_ptr										_NIL;
			size_type										_size;
			allocator_type									_alloc;
			key_compare										_comp;
		public:		 
			rbtree(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _NIL(_alloc.allocate(1)), _size(0)
			{
				// aucun element -> tout est NIL
				_NIL->parent = _NIL;
				_NIL->right = _NIL;
				_NIL->left = _NIL;
				_NIL->color = BLACK;
			}

			rbtree(rbtree &rhs) : _alloc(rhs._alloc), _root(rhs._root), _size(rhs._size), _NIL(_alloc.allocate(1)), _comp(rhs._comp)
			{
				_NIL->parent = _NIL;
				_NIL->right = _NIL;
				_NIL->left = _NIL;
				_NIL->color = BLACK;

				
			}

			~rbtree(void)
			{
				clear();
				_alloc.deallocate(_NIL, 1);
			}

			rbtree &operator=(const rbtree &copy)
			{
				clear();
				_deepCopy(*this, copy._root, copy._NIL);
				return *this;
			}

			iterator begin(void)
			{
				return iterator(_findMin(_root), _root, _NIL);
			}

			const_iterator begin(void) const
			{
				return const_iterator(_findMin(_root), _root, _NIL);
			}

			iterator end(void)
			{
				return iterator(_NIL, _root, _NIL);
			}

			const_iterator end(void) const
			{
				return const_iterator(_NIL, _root, _NIL);
			}

			reverse_iterator rbegin(void)
			{
				return reverse_iterator(end());
			}

			const_reverse_iterator rbegin(void) const
			{
				return const_reverse_iterator(end());
			}
			reverse_iterator rend(void)
			{
				return reverse_iterator(begin());
			}

			const_reverse_iterator rend(void) const
			{
				return const_reverse_iterator(begin());
			}

			size_type size(void) const
			{
				return _size;
			}

			size_type max_size(void) const
			{
				return _alloc.max_size();
			}

			iterator find(const value_type &k)
			{
				node_ptr ret = _find(k);
				if (!ret)	return end();
				else		return iterator(ret, _root, _NIL);
			}

			const_iterator find(const value_type &k) const
			{
				node_ptr ret = _find(k);
				if (!ret)	return end();
				else		return const_iterator(ret, _root, _NIL);
			}

			void clear(void)
			{
				_deepClear(_root);
				_root = _NIL;
				_size = 0;
			}

			void erase(iterator position)
			{
				if (position.base() != _NIL)
					_deepRemove(position.base());
			}

			size_type erase(value_type const &k)
			{
				node_ptr tmp = _find(k);
				if (tmp)
					return _deepRemove(tmp);
				return 0;
			}

			/**
			 * @brief creates a new node, inserts it using regular insertDeep
			 * if insert does not work because there is already a value equal to it
			 * in the tree it will simply return another make pair iterator
			 * 
			 * @param to_insert 
			 * @return ft::pair<iterator, bool> 
			 */
			ft::pair<iterator, bool> insert(const value_type &to_insert)
			{
				node_ptr newNode = _newNode(to_insert);
				ft::pair<node_ptr, bool> ret = _insertDeep(_root, newNode);
				if (ret.second)
				{
					_size++;
					if (newNode->parent == _NIL)
						newNode->color = BLACK;
					else
						_insertFix(newNode);
					_root = _getRoot(newNode);
					return ft::make_pair(iterator(newNode, _root, _NIL), true);
				}
				else
				{
					_alloc.destroy(newNode);
					_alloc.deallocate(newNode, 1);
					return ft::make_pair(iterator(ret.first, _root, _NIL), false);
				}
			}

			void swap(rbtree &x)
			{
				ft::swap(x._root, _root);
				ft::swap(x._NIL, _NIL);
				ft::swap(x._size, _size);
				ft::swap(x._alloc, _alloc);
				ft::swap(x._comp, _comp);
			}

			/**
			 * @brief tries to insert after a specific iterator called hint
			 * this can be used to increase the efficiency of an algorithm
			 * 
			 * @param hint 
			 * @param value 
			 * @return iterator 
			 */
			iterator insert(iterator hint, const value_type &value)
			{
				node_ptr next = _next(hint.base());
				if (_comp(hint.base()->data, value) && _comp(value, next->data))
				{
					node_ptr newNode = _newNode(value);
					ft::pair<node_ptr, bool> r = _deepInsert(hint.base(), newNode);
					_size++;
					return iterator(r.first, _root, _NIL);
				}
				return insert(value).first;
			}

			bool isIn(const value_type &k) const
			{
				return _find(k) != NULL;
			}

			iterator lower_bound(const value_type &k)
			{
				iterator it = begin();
				while (it != end())
				{
					node_ptr tmp = it.base();
					if (_comp(k, tmp->data) || (!_comp(k, tmp->data) && !_comp(tmp->data, k)))
						return it;
					it++;
				}
				return it;
			}

			const_iterator lower_bound(const value_type &k) const
			{
				const_iterator it = begin();
				while (it != end())
				{
					node_ptr tmp = it.base();
					if (_comp(k, tmp->data) || (!_comp(k, tmp->data) && !_comp(tmp->data, k)))
						return it;
					it++;
				}
				return it;
			}

			iterator upper_bound(const value_type &k)
			{
				iterator it = begin();
				while (it != end())
				{
					node_ptr tmp = it.base();
					if (_comp(k, tmp->data))
						return it;
					it++;
				}
				return it;
			}

			const_iterator upper_bound(const value_type &k) const
			{
				const_iterator it = begin();
				while (it != end())
				{
					node_ptr tmp = it.base();
					if (_comp(k, tmp->data))
						return it;
					it++;
				}
				return it;
			}

		private:
			/**
			 * @brief insert to insert into its right position
			 * each time the function is called it check if the position is right
			 * if the position is not, it invokes the function again with a new branch
			 * 
			 * @param root 
			 * @param to_insert 
			 * @return ft::pair<node_ptr, bool> 
			 */
			ft::pair<node_ptr, bool> _insertDeep(node_ptr root, node_ptr to_insert)
			{
				// insert data smaller than root data -> going left
				if (root != _NIL && _comp(to_insert->data, root->data))
				{
					if (root->left != _NIL)
					 	return (_insert(root->left, to_insert));
					else
						root->left = to_insert;
				}
				else if (root != _NIL && _comp(root->data, to_insert->data))
				{
					if (root->right != _NIL)
					 	return (_insert(root->right, to_insert));
					else
						root->right = to_insert;
				}
				else if (root != _NIL)
					return (ft::make_pair(root, false));
				to_insert->parent = root;
				to_insert->color = RED;
				to_insert->left = _NIL;
				to_insert->right = _NIL;
				return (ft::make_pair(to_insert, true));
			}

			/**
			 * @brief basically just removes the node z, then calls remove fix to 
			 * heal the tree
			 * 
			 * @param z 
			 * @return int 
			 */
			int _deepRemove(node_ptr to_remove)
			{
				node_ptr y = to_remove;
				node_ptr x;
				bool y_original_color = y->color;

				if (to_remove->left == _NIL)
				{
					x = to_remove->right;
					_invert(to_remove, to_remove->right);
				}
				else if (to_remove->right == _NIL)
				{
					x = to_remove->left;
					_invert(to_remove, to_remove->left);
				}
				else
				{
					y = _findMin(to_remove->right);
					y_original_color = y->color;
					x = y->right;
					if (y->parent == to_remove)
						x->parent = y;
					else
					{
						_invert(y, y->right);
						y->right = to_remove->right;
						y->right->parent = y;
					}
					_invert(to_remove, y);
					y->left = to_remove->left;
					y->left->parent = y;
					y->color = to_remove->color;
				}
				_alloc.destroy(to_remove);
				_alloc.deallocate(to_remove, 1);
				_size--;
				if (y_original_color == BLACK)
					_removeFix(x);
				return 1;
			}
		
			/**
			 * @brief this is a tuff one, explaining the working in this
			 * https://www.programiz.com/dsa/deletion-from-a-red-black-tree
			 * 
			 * @param x 
			 */
			void _removeFix(node_ptr x)
			{
				node_ptr s;
				while (x != _root && x->color == BLACK)
				{
					if (x == x->parent->left)
					{
						s = x->parent->right;
						if (s->color == RED)
						{
							s->color = BLACK;
							x->parent->color = RED;
							_leftRotate(x->parent);
							s = x->parent->right;
						}
						if (s->left->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x = x->parent;
						}
						else
						{
							if (s->right->color == BLACK)
							{
								s->left->color = BLACK;
								s->color = RED;
								_rightRotate(s);
								s = x->parent->right;
							}
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->right->color = BLACK;
							_leftRotate(x->parent);
							x = _root;
						}
					}
					else
					{
						s = x->parent->left;
						if (s->color == RED)
						{
							s->color = BLACK;
							x->parent->color = RED;
							_rightRotate(x->parent);
							s = x->parent->left;
						}
						if (s->right->color == BLACK && s->left->color == BLACK)
						{
							s->color = RED;
							x = x->parent;
						}
						else
						{
							if (s->left->color == BLACK)
							{
								s->right->color = BLACK;
								s->color = RED;
								_leftRotate(s);
								s = x->parent->left;
							}
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->left->color = BLACK;
							_rightRotate(x->parent);
							x = _root;
						}
					}
				}
				x->color = BLACK;
			}

			/**
			 * @brief 
			 * 
			 * @param tree_dst 
			 * @param root_src 
			 * @param nil_src 
			 */
			void _deepCopy(rbtree &tree_dst, node_ptr root_src, node_ptr nil_src)
			{
				if (root_src != nil_src)
				{
					_deepCopy(tree_dst, root_src->left, nil_src);
					tree_dst.insert(root_src->data);
					_deepCopy(tree_dst, root_src->right, nil_src);
				}
			}

			int _deepRemove(node_ptr z)
			{
				node_ptr y = z;
				node_ptr x;
				bool y_original_color = y->color;

				if (z->left == _NIL)
				{
					x = z->right;
					_invert(z, z->right);
				}
				else if (z->right == _NIL)
				{
					x = z->left;
					_invert(z, z->left);
				}
				else
				{
					y = _findMin(z->right);
					y_original_color = y->color;
					x = y->right;
					if (y->parent == z)
						x->parent = y;
					else
					{
						_invert(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}
					_invert(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
				_alloc.destroy(z);
				_alloc.deallocate(z, 1);
				_size--;
				if (y_original_color == BLACK)
					_removeFix(x);
				return 1;
			}

			void _rotateLeft(node_ptr x)
			{
				node_ptr y = x->right;
				x->right = y->left;
				if (y->left != _NIL)
					y->left->parent = x;
				y->parent = x->parent;
				if (x->parent == _NIL)
					this->_root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;
			}

			void _rotateRight(node_ptr x)
			{
				node_ptr y = x->left;
				x->left = y->right;
				if (y->right != _NIL)
					y->right->parent = x;
				y->parent = x->parent;
				if (x->parent == _NIL)
					this->_root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x;
				x->parent = y;
			}

			node_ptr _getMin(node_ptr node) const
			{
				while (node->left != _NIL)
					node = root->left;
				return node;
			}

			node_ptr _getMax(node_ptr node) const
			{
				while (node->right != _NIL)
					node = node->right;
				return node;
			}

			node_ptr _next(node_ptr node) const
			{
				node_ptr tmp = _NIL;

				if (node->right != _NIL)
					return _findMin(node->right);
				tmp = node->parent;
				while (tmp != _NIL && node == tmp->right)
				{
					node = tmp;
					tmp = tmp->parent;
				}
				return tmp;
			}

			node_ptr _getRoot(node_ptr node) const
			{
				node_ptr tmp = node;

				while (tmp->parent != _NIL)
					tmp = tmp->parent;
				return tmp;
			}

			/**
			 * @brief allocates and sets to 0
			 * 
			 * @param data value that is copied in the node
			 * @return node_ptr 
			 */
			node_ptr _newNode(const value_type &data)
			{
				node_ptr newNode = _alloc.allocate(1);
				_alloc.construct(newNode, data);
				newNode->color = RED;
				newNode->left = _NIL;
				newNode->right = _NIL;
				newNode->parent = _NIL;
				return newNode;
			}

			/**
			 * @brief finds the value val and returns node pointer
			 * returns NULL in case no corresponding value is found
			 * 
			 * @param val 
			 * @return node_ptr 
			 */
			node_ptr _find(value_type const &val) const
			{
				node_ptr tmp = _root;
				while (tmp != _NIL)
				{
					if (_comp(val, tmp->data))
						tmp = tmp->left;
					else if (_comp(tmp->data, val))
						tmp = tmp->right;
					else
						return tmp;
				}
				return NULL;
			}

			/**
			 * @brief 
			 * 
			 * @param src 
			 */
			void _deepClear(node_ptr src = NULL)
			{
				if (src == NULL)
					src = _root;
				if (src != _NIL)
				{
					_deepClear(src->left);
					_deepClear(src->right);
					_alloc.destroy(src);
					_alloc.deallocate(src, 1);
				}
			}
			//
			/**
			 * @brief inverts the elem, called the_new bcs new was taken
			 * 
			 * @param old to be put "under" new le
			 * @param the_new node to be put on top of old
			 */
			void _invert(node_ptr old, node_ptr the_new)
			{
				if (old->parent == _NIL)
					_root = the_new;
				else if (old == old->parent->left)
					old->parent->left = the_new;
				else
					old->parent->right = the_new;
				the_new->parent = old->parent;
			}
	
			void _insertFix(node_ptr k)
			{
				node_ptr uncle;

				while (k->parent->color == RED)
				{
					// if left child
					if (k->parent == k->grandParent()->right)
					{
						uncle = k->uncle();
						if (uncle->color == RED)
						{
							uncle->color = BLACK;
							k->parent->color = BLACK;
							k->grandParent()->color = RED;
							k = k->grandParent();
						}
						else
						{
							if (k == k->parent->left)
							{
								k = k->parent;
								_rightRotate(k);
							}
							k->parent->color = BLACK;
							k->grandParent()->color = RED;
							_leftRotate(k->grandParent());
						}
					}
					else
					{
						uncle = k->uncle();

						if (uncle->color == RED)
						{
							uncle->color = BLACK;
							k->parent->color = BLACK;
							k->grandParent()->color = RED;
							k = k->grandParent();
						}
						else
						{
							if (k == k->parent->right)
							{
								k = k->parent;
								_leftRotate(k);
							}
							k->parent->color = BLACK;
							k->grandParent()->color = RED;
							_rightRotate(k->grandParent());
						}
					}
					if (k == _root)
						break;
				}
				_root->color = BLACK;
			}
	}

}

#endif