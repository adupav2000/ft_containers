/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:14:33 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/04/30 20:16:23 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
#define MAKE_PAIR_HPP
#include "pair.hpp"

namespace ft
{
	/**
	 * @brief Creates a std::pair object, deducing the target type from
	 * the types of arguments.
	 *
	 * @tparam T1
	 * @tparam T2
	 * @param x
	 * @param y
	 * @return pair<T1, T2>
	 */
	template <class T1, class T2>
	pair<T1, T2> make_pair(const T1 &x, const T2 &y)
	{
		return (pair<T1, T2>(x, y));
	}
}
#endif