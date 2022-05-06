/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:42:30 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/05/04 17:36:43 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


namespace ft
{
	/**
	 * @brief  Checks whether T is an integral type. Provides the member
	 * constant value which is equal to true, if T is the type
	 * bool,
	 * char,
	 * short,
	 * int,
	 * long,
	 * unsigned char,
	 * unsigned short int,
	 * unsigned int,
	 * unsigned long int,
	 * unsigned long long int
	 * or any implementation-defined extended integer types,
	 * including any signed, unsigned, and cv-qualified variants.
	 * Otherwise, value is equal to false.
	 *
	 */
	template <bool true_false, typename T>
	struct is_integral_parent {
		static const bool value = true_false;
	};
	template <typename T>
	struct is_integral : public is_integral_parent<false, bool> { };
	template <>
	struct is_integral<bool> : public is_integral_parent<true, bool> { };
	template <>
	struct is_integral<char> : public is_integral_parent<true, char> { };
	template <>
	struct is_integral<short> : public is_integral_parent<true, short> { };
	template <>
	struct is_integral<int> : public is_integral_parent<true, int> { };
	template <>
	struct is_integral<long int> : public is_integral_parent<true, long int> { };
	template <>
	struct is_integral<long long int> : public is_integral_parent<true, long long int> { };
	template <>
	struct is_integral<unsigned char> : public is_integral_parent<true, unsigned char> { };
	template <>
	struct is_integral<unsigned short int> : public is_integral_parent<true, unsigned short int> { };
	template <>
	struct is_integral<unsigned int> : public is_integral_parent<true, unsigned int> { };
	template <>
	struct is_integral<unsigned long int> : public is_integral_parent<true, unsigned long int> { };
	template <>
	struct is_integral<unsigned long long int> : public is_integral_parent<true, unsigned long long int> { };
}