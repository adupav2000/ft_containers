/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_node.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:01:17 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/05/12 17:01:19 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_NODE_HPP
#define RBTREE_NODE_HPP

#define RED		true
#define BLACK	false

namespace ft
{
	template <class T>
	struct rbtree_node
	{
		typedef T		value_type;

		rbtree_node*	left;
		rbtree_node*	right;
		rbtree_node*	parent;

		bool			color;

		value_type		data;

		rbtree_node(const value_type& src) : data(src) {}

		rbtree_node &operator=(const rbtree_node& rhs) {
			if (this != rhs)
			{
				this->left = rhs.left;
				this->right = rhs.right;
				this->parent = rhs.parent;
				this->color = rhs.color;
			}
			return (*this);
		}
	};
}

#endif
