/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:01:37 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/05/12 17:01:38 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
	class pair
	{
		public:
			typedef T1	first_type;
			typedef T2	second_type;

			first_type	first;
			second_type	second;

			pair(void) {}

			pair(const first_type& u, const second_type& v) : first(u), second(v) {};

			template <class _T1, class _T2>
			pair(const pair<_T1, _T2>& pair) : first(pair.first), second(pair.second) {}

			~pair(void) {};

			template <class _T1, class _T2>
			pair<T1, T2>& operator=(const pair<_T1, _T2>& pair)
			{
				first = pair.first;
				second = pair.second;
				return *this;
			}

			operator pair<const T1, const T2>(void) const
			{
				return pair<const T1, const T2>(first, second);
			}
	};

	template <class T1, class T2>
	bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first != rhs.first || lhs.second != rhs.second);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first < rhs.first && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first > rhs.first && lhs.second > rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first <= rhs.first && lhs.second <= rhs.second);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first >= rhs.first && lhs.second >= rhs.second);
	}

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 u, T2 v)
	{
		return (pair<T1, T2>(u, v));
	}
}

#endif
