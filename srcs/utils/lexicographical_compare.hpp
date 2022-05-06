/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:21:47 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/05/01 11:42:17 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{

	/**
	 * @brief  true if the sequence of elements defined by the range [first1, last1)
	 * is lexicographically less than the sequence of elements
	 * defined by the range [first2, last2).
	 * Returns false otherwise.
	 *
	 * @tparam InputIterator1
	 * @tparam InputIterator2
	 * @tparam Compare
	 * @param first1
	 * @param last1
	 * @param first2
	 * @param last2
	 * @param comp
	 * @return true
	 * @return false
	 */
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								 InputIterator2 first2, InputIterator2 last2)
	{
		// for (InputIterator1 i = first1, InputIterator2 j = first2; i != last1 && j != last2 && !(*i < *j) && !(*j < *i); ++i, ++j)
			//  {}
		// return j == last2 ? false : i == last1 || *i < *j;
		// Another alternative by me, but the reference code is perfect
		while (first1 != last1)
		{
			if (*first1 < *first2)
				return (true);
			else if (*first1 > first2)
				return (false);
			else if (first2 == last2)
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}
	template <typename T>
	bool lexicographical_compare(T *el1, T *el2)
	{
		// we let the operators defined by the obj do the job
		return (el1 < el2);
	}
}
#endif