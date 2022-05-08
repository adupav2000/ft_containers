/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:14:44 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/05/06 12:32:59 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FT_CONST_ITERATOR_HPP
#define FT_CONST_ITERATOR_HPP

#include "./iterators_traits.hpp"

namespace ft
{
	template <class T>
	class const_iterator : public ft::iterator<const T>
	{
	private:
		T *_pointer;

		typedef std::ptrdiff_t difference_type;

	};
};

#endif