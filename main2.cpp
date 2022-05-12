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

#ifdef FT
	#include "inc/map.hpp"
	#include "inc/stack.hpp"
	#include "inc/vector.hpp"
#else
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#endif

static void vector_tests(int n)
{
	ft::vector<int> vect_int;

	for (int i = 0; i < n; i++)
		vect_int.push_back(i);

	for (int i = 0; i < 2; i++)
		vect_int.pop_back();

	std::cout << "capactity: " << vect_int.capacity() << std::endl;
	std::cout << "size: " << vect_int.size() << std::endl;
	std::cout << "max size: " << vect_int.max_size() << std::endl;

	for (size_t i = 0; i < vect_int.size(); i++)
		std::cout << "[" << i << "] = " << vect_int[i] << "\n";
}

static void stack_tests(int n)
{
	ft::stack<int> stack_int;

	for (int i = 0; i < n; i++)
		stack_int.push(i);

	for (int i = 0; i < 2; i++)
		stack_int.pop();

	std::cout << "size: " << stack_int.size() << std::endl;

	size_t i = stack_int.size();
	while (!stack_int.empty() && i--)
	{
		std::cout << "[" << i << "] = " << stack_int.top() << "\n";
		stack_int.pop();
	}
}

static void map_tests(int n)
{
	ft::map<int, int> map_int;

	for (int i = 0; i < n; i++)
		map_int.insert(ft::make_pair(i, i));

	std::cout << "size: " << map_int.size() << std::endl;
	std::cout << "max size: " << map_int.max_size() << std::endl;

	for (size_t i = 0; i < map_int.size(); i++)
		std::cout << "[" << i << "] = " << map_int[i] << "\n";
}

int main(void)
{
	int lim = 20;
	std::cout << ">>>>\nTests for vector\n<<<<" << std::endl;
	vector_tests(lim);

	std::cout << ">>>>\nTests for stack\n<<<<" << std::endl;
	stack_tests(lim);

	std::cout << ">>>>\nTests for map\n<<<<" << std::endl;
	map_tests(lim);

	return (0);
}
