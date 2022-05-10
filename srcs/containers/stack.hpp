/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:13:10 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/05/10 21:17:01 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

		protected:
			container_type	_c;

		public:
			explicit stack(const container_type& cont = container_type())
				: _c(cont)
			{}

			~stack(void)
			{}

			stack& operator=(const stack& copy)
			{
				_c = copy._c;
				return *this;
			}

			reference top(void)
			{
				return _c.back();
			}

			const_reference top(void) const
			{
				return _c.back();
			}

			bool empty(void) const
			{
				return _c.empty();
			}

			size_type size(void) const
			{
				return _c.size();
			}

			void push(const value_type& value)
			{
				_c.push_back(value);
			}

			void pop(void)
			{
				_c.pop_back();
			};

			template<class _T, class _Container>
			friend bool operator==(const ft::stack<_T, _Container>& lhs, const ft::stack<_T, _Container>& rhs);

			template<class _T, class _Container>
			friend bool operator!=(const ft::stack<_T, _Container>& lhs, const ft::stack<_T, _Container>& rhs);

			template<class _T, class _Container>
			friend bool operator<(const ft::stack<_T, _Container>& lhs, const ft::stack<_T, _Container>& rhs);

			template<class _T, class _Container>
			friend bool operator>(const ft::stack<_T, _Container>& lhs, const ft::stack<_T, _Container>& rhs);

			template<class _T, class _Container>
			friend bool operator<=(const ft::stack<_T, _Container>& lhs, const ft::stack<_T, _Container>& rhs);

			template<class _T, class _Container>
			friend bool operator>=(const ft::stack<_T, _Container>& lhs, const ft::stack<_T, _Container>& rhs);
	};

	template<class T, class Container>
	bool operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
	{
		return lhs._c == rhs._c;
	}

	template<class T, class Container>
	bool operator!=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
	{
		return lhs._c != rhs._c;
	}

	template<class T, class Container>
	bool operator<(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
	{
		return lhs._c < rhs._c;
	}

	template<class T, class Container>
	bool operator>(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
	{
		return lhs._c > rhs._c;
	}

	template<class T, class Container>
	bool operator<=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
	{
		return lhs._c <= rhs._c;
	}

	template<class T, class Container>
	bool operator>=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
	{
		return lhs._c >= rhs._c;
	}
}