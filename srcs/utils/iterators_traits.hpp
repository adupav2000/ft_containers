/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:06:57 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/05/08 19:44:45 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS
#define ITERATOR_TRAITS

#include <cstddef>

namespace ft
{
	//Random access → Bidirectional → Forward → (Input && Output)
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

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
	template <class Iterator>
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};
	template <class T>
	class iterator_traits<T*>
	{
		public:
			typedef std::ptrdiff_t							difference_type;
			typedef T										value_type;
			typedef T*										pointer;
			typedef T&										reference;
			typedef std::random_access_iterator_tag			iterator_categorie;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		public:
			typedef std::ptrdiff_t							difference_type;
			typedef T										value_type;
			typedef const T*								pointer;
			typedef const T&								reference;
			typedef std::random_access_iterator_tag			iterator_categorie;
	};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator
	{
		public:
			typedef T								value_type;
			typedef Distance						difference_type;
			typedef Pointer							pointer;
			typedef Reference						reference;
			typedef Category						iterator_category;
		protected:
			pointer _pointer;
	};
}
#endif