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
#include <stdio.h>
#include <stdlib.h>

#define real


#ifndef real
#include "srcs/containers/stack.hpp"
#include "srcs/containers/map.hpp"
#include "srcs/containers/vector.hpp"
#else
#include <map>
#include <stack>
#include <vector>
namespace ft = std;
#endif


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
		(void)argc;
		(void)argv;
		
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
		ft::vector<int> vector_int_insert(20);
		vector_int_insert.resize(12, 12);
		for (size_t i = 0; i < vector_int.size(); i++)
		{
			std::cout << vector_int.at(i) << "-" << i << " ";
		}
		std::cout << std::endl;

		// vector_int.insert(vector_int.begin(), (std::size_t)23, (std::size_t)22);
		vector_int.insert(vector_int.begin(), vector_int_insert.begin(), vector_int_insert.end());
		for (size_t i = 0; i < vector_int.size(); i++)
		{
			std::cout << vector_int.at(i) << "-" << i << " ";
		}
		std::cout << std::endl;

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