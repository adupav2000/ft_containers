/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 21:42:26 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/04/29 15:28:51y adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>

// #include "srcs/utils/iterator.hpp"
// #include "srcs/utils/enable_if.hpp"
// #include "srcs/utils/is_integral.hpp"
// #include "srcs/utils/iterators_traits.hpp"
// #include "srcs/utils/lexicographical_compare.hpp"
#include "srcs/utils/make_pair.hpp"
#include "srcs/utils/pair.hpp"
// #include "srcs/utils/reverse_iterator.hpp"
// #include "srcs/utils/utils.hpp"

// #ifndef REAL_LIB
// #define REAL_LIB 1
// #endif

// #if REAL_LIB == 1
// #include <map>
// #include <stack>
// #include <vector>
// namespace ft = std;
// #else
// #include "srcs/containers/map.hpp"
// #include "srcs/containers/stack.hpp"
// #endif

#include "srcs/containers/vector.hpp"

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

int main(int argc, char **argv)
{
	{
		if (argc != 2)
		{
			std::cerr << "Usage: ./test seed" << std::endl;
			std::cerr << "Provide a seed please" << std::endl;
			std::cerr << "Count value:" << COUNT << std::endl;
			return 1;
		}
		const int seed = atoi(argv[1]);
		srand(seed);
		std::cout << "passed the first " << std::endl;
		// ft::vector<std::string> vector_str;
		// ft::vector<int> test_int(100, 10);
		ft::vector<int> vector_int(20);
		size_t tt_cap = 0;
		for (size_t i = 0; i < 300000; i++)
		{
			if (tt_cap != vector_int.capacity())
			{
				tt_cap = vector_int.capacity();
				std::cout << tt_cap << " " << vector_int.size() << std::endl;
			}
			vector_int.push_back(i * i);
		}
		// test on resize
		vector_int.resize(3, 12);
		vector_int.resize(300, 12);
		for (size_t i = 0; i < vector_int.size(); i++)
		{
			std::cout << vector_int.at(i) << "-" << i << " ";
		}
		std::cout << std::endl;

		vector_int.assign(100, 12);
		for (size_t i = 0; i < vector_int.size(); i++)
		{
			std::cout << vector_int.at(i) << "-" << i << " ";
		}
		std::cout << std::endl;

		std::cout << "passed the second " << std::endl;
		// ft::stack<int> stack_int;
		struct Buffer test_buffer_resize;
		test_buffer_resize.idx = 123;
		ft::vector<Buffer> vector_buffer;
		vector_buffer.resize(123, test_buffer_resize);

		// ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
		// ft::map<int, int> map_int;

		std::cout << " Vector int " << vector_int.capacity() << " and size " << vector_int.size() << std::endl;
		std::cout << " Vector buffer " << vector_buffer.capacity() << " and size " << vector_buffer.size() << std::endl;

		std::cout << "Back vector int " << *(vector_int.begin()) << std::endl;
	}
	{
		// PAIR TESTING
		ft::pair<int, double> x(22, 23.23);
		ft::pair<int, double> y(22, 23);
		if (x < y)
			std::cout << "x < y" << std::endl;
		if (x > y)
			std::cout << "x > y" << std::endl;
		if (x <= y)
			std::cout << "x <= y" << std::endl;
		if (x >= y)
			std::cout << "x >= y" << std::endl;
		if (x != y)
			std::cout << "x != y" << std::endl;
		if (x == y)
			std::cout << "x == y" << std::endl;

		ft::pair<int, int> x1(22, 23);
		ft::pair<int, int> y1(22, 23);
		if (x1 < y1)
			std::cout << "x1 < y1" << std::endl;
		if (x1 > y1)
			std::cout << "x1 > y1" << std::endl;
		if (x1 <= y1)
			std::cout << "x1 <= y1" << std::endl;
		if (x1 >= y1)
			std::cout << "x1 >= y1" << std::endl;
		if (x1 != y1)
			std::cout << "x1 != y1" << std::endl;
		if (x1 == y1)
			std::cout << "x1 == y1" << std::endl;

		ft::pair<bool, bool> x2(0, 1);
		ft::pair<bool, bool> y2(0, 0);
		if (x2 < y2)
			std::cout << "x2 < y2" << std::endl;
		if (x2 > y2)
			std::cout << "x2 > y2" << std::endl;
		if (x2 <= y2)
			std::cout << "x2 <= y2" << std::endl;
		if (x2 >= y2)
			std::cout << "x2 >= y2" << std::endl;
		if (x2 != y2)
			std::cout << "x2 != y2" << std::endl;
		if (x2 == y2)
			std::cout << "x2 == y2" << std::endl;
	}
	{
		//ENABLE_IF TESTING

	}
	{
		// IS_INTEGRAL TESTING
		
	}
	{
		// 
	}
	return (0);
}