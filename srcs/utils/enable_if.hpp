/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 10:01:59 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/05/04 18:11:20 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ENABLE_IF
#define ENABLE_IF
namespace ft
{

	/**
	 * @brief If B is true, std::enable_if has a public member typedef type,
	 * equal to T;otherwise, there is no member typedef.
	 * This metafunction is a convenient way to leverage SFINAE prior to C++20's
	 * concepts, in particular for conditionally removing functions from the
	 * candidate set based on type traits, allowing separate function overloads
	 * or specializations based on those different type traits.
	 *
	 * @tparam B
	 * @tparam T
	 */
	// everything else than true has no type
	template<bool Cond, class T = void>
	struct enable_if {};
	// specialisation in case of true has type
    template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
}
#endif