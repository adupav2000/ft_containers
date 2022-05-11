/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:34:05 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/04/30 20:43:29by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

#include "utils.hpp"

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

		pair() : first(), second() { }

		pair(const T1 &x, const T2 &y) : first(x), second(y) { }

		template <class U, class V>
		pair(const pair<U, V> &p) : first(p.first), second(p.second) {
		}

		pair<T1, T2> operator=(const pair<T1, T2> &x)
		{
			this->first = x.first;
			this->second = x.second;
			return (*this);
		}
	};

	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return (x.first == y.first && x.second == y.second);
	};

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return (x.first != y.first || x.second != y.second);
	};

	template< class T1, class T2 >
	bool operator<=( const pair<T1,T2>& x, const pair<T1,T2>& y )
	{
		return (x.first <= y.first && x.second <= y.second);
	};

	template< class T1, class T2 >
	bool operator>=( const pair<T1,T2>& x, const pair<T1,T2>& y )
	{
		return (x.first >= y.first && x.second >= y.second);
	};

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return (x.first < y.first || (!(y.first > x.first) && x.second > y.second));
	};

	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));
	};
}

#endif