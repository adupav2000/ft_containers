/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:06:57 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/04/17 15:51:15 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS
#define ITERATOR_TRAITS

#include <iterator>

namespace ft
{
	/**
	 * @brief 	std::iterator_traits is the type trait class that provides
	 * uniform interface to the properties of LegacyIterator types.
	 * This makes it possible to implement algorithms only in terms
	 * of iterators.
	 * 
	 * The template can be specialized for user-defined iterators so that
	 * the information about the iterator can be retrieved even if the type
	 * does not provide the usual typedefs.
	 * 
	 * @tparam Iterator 
	 */
	template <class Iterator> class iterator_traits : Iterator
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};
}
#endif