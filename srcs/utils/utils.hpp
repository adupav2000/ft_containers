/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:21:13 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/04/17 18:31:32by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{
	template <class IteratorTypeOne, class IteratorTypeTwo>
	bool equal(IteratorTypeOne x, IteratorTypeOne x_last,
			   IteratorTypeTwo y, IteratorTypeTwo y_last)
	{
		// while both are not at the end
		while (x != x_last && y != y_last)
		{
			if (*y != *x)
				return (false);
			++y;
			++x;
		}
		// if one of them is not at the end -> not equal
		if (x != x_last || y != y_last)
			return (false);
		return (true);
	}

	/**
	 * @brief less than (<), refers to the fist arg
	 *
	 * @tparam IteratorTypeOne
	 * @tparam IteratorTypeTwo
	 * @param x first iterator, so that i can go to the next one using ++,
	 * 			using vector it will be vector.begin()
	 * @param x_last last iterator of a list, in vector : vector.end()
	 * @param y second iterator
	 * @param y_last same ... end
	 * @return true : the assertion x(as an obj, not an iterator) < y is true
	 * @return false
	 */
	template <class IteratorTypeOne, class IteratorTypeTwo>
	bool lesser(IteratorTypeOne x, IteratorTypeOne x_last,
				IteratorTypeTwo y, IteratorTypeTwo y_last)
	{
		// while both are not at the end
		while (x != x_last && y != y_last)
		{
			// the opposite is confirmed -> assertion false
			if (*x > *y)
				return (false);
			if (*x < *y)
				return (true);
			++y;
			++x;
		}
		// if y is not at the end, it is undeniably bigger
		if (y != y_last)
			return (true);
		return (false);
	}

	/**
	 * @brief higher than (>), refers to the fist arg
	 *
	 * @tparam IteratorTypeOne
	 * @tparam IteratorTypeTwo
	 * @param x first iterator, so that i can go to the next one using ++,
	 * 			using vector it will be vector.begin()
	 * @param x_last last iterator of a list, in vector : vector.end()
	 * @param y second iterator
	 * @param y_last same ... end
	 * @return true : the assertion x(as an obj, not an iterator) > y is true
	 * @return false
	 */
	template <class IteratorTypeOne, class IteratorTypeTwo>
	bool higher(IteratorTypeOne x, IteratorTypeOne x_last,
				IteratorTypeTwo y, IteratorTypeTwo y_last)
	{
		// while both are not at the end
		while (x != x_last && y != y_last)
		{
			// the opposite is confirmed -> assertion false
			if (*x < *y)
				return (false);
			if (*x > *y)
				return (true);
			++y;
			++x;
		}
		// if x is not at the end, it is undeniably bigger
		if (x != x_last)
			return (true);
		return (false);
	}

	/**
	 * @brief higher than (>), refers to the fist arg
	 *
	 * @tparam IteratorTypeOne
	 * @tparam IteratorTypeTwo
	 * @param x first iterator, so that i can go to the next one using ++,
	 * 			using vector it will be vector.begin()
	 * @param x_last last iterator of a list, in vector : vector.end()
	 * @param y second iterator
	 * @param y_last same ... end
	 * @return true : the assertion x(as an obj, not an iterator) > y is true
	 * @return false
	 */
	template <class IteratorTypeOne, class IteratorTypeTwo>
	bool higherOrEqual(IteratorTypeOne x, IteratorTypeOne x_last,
					   IteratorTypeTwo y, IteratorTypeTwo y_last)
	{
		// while both are not at the end
		while (x != x_last && y != y_last)
		{
			// the opposite is confirmed -> assertion false
			if (*x < *y)
				return (false);
			if (*x > *y)
				return (true);
			++y;
			++x;
		}
		// if y is not the last one, it's size is considered bigger
		if (y != y_last)
			return (false);
		// they are equal or the size of x is bigger :> true
		return (true);
	}

	/**
	 * @brief lesser or equal than (<=), refers to the fist arg
	 *
	 * @tparam IteratorTypeOne
	 * @tparam IteratorTypeTwo
	 * @param x first iterator, so that i can go to the next one using ++,
	 * 			using vector it will be vector.begin()
	 * @param x_last last iterator of a list, in vector : vector.end()
	 * @param y second iterator
	 * @param y_last same ... end
	 * @return true : the assertion x(as an obj, not an iterator) <= y is true
	 * @return false
	 */
	template <class IteratorTypeOne, class IteratorTypeTwo>
	bool lesserOrEqual(IteratorTypeOne x, IteratorTypeOne x_last,
					   IteratorTypeTwo y, IteratorTypeTwo y_last)
	{
		// while both are not at the end
		while (x != x_last && y != y_last)
		{
			// the opposite is confirmed -> assertion false
			if (*x > *y)
				return (false);
			if (*x < *y)
				return (true);
			++y;
			++x;
		}
		// if x is not the last one, it's size is considered bigger
		if (x != x_last)
			return (false);
		// they are equal or the size of y is bigger :> true
		return (true);
	}
}

#endif
