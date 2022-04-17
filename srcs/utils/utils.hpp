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
}

#endif