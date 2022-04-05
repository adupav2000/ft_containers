/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:18:05 by adu-pavi          #+#    #+#             */
/*   Updated: 2022/04/05 18:10:40 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <iostream>

int main()
{
	std::cout << "Je ne comprend rien, ce test est pour voir si tout fonctionnne correctement" << std::endl;
	std::vector<std::string> test;
	std::vector<std::string> test1;
	// std::vector<int> test2;

	std::cout << test.get_allocator().max_size() << std::endl;
	std::cout << test.capacity() << std::endl;
	// std::cout << (test.get_allocator().construct()) << std::endl;

	for (int i = 0; i < 42; i++)
	{
		std::cout << test.capacity() << std::endl;
		test.push_back("Hello el 1");
		if (test.size() > 20)
			std::cout << "we know it has the capacity" << test[20] << std::endl;
	}
	test1.push_back("Hello el 1");
	test1.push_back("Hello el 2");
	test1.push_back("Hello el 3");
	test1.push_back("Hello el 4");
	test1.push_back("Hello el 5");

	std::vector<std::string>::iterator norm = test1.begin();
	std::vector<std::string>::reverse_iterator rev = test.rbegin();

	std::cout << "test < test1 " << (test < test1) << std::endl;
	std::cout << "test <= test1 " << (test <= test1) << std::endl;
	std::cout << "test >= test1 " << (test >= test1) << std::endl;
	std::cout << "test > test1 " << (test > test1) << std::endl;

	for (int i = 5; i < 5; i++)
	{
		std::cout << "Normal num " << i << " equals " << *(++norm) << std::endl;
		std::cout << "Reverse num " << i << " equals " << *(++rev) << std::endl;
	}
	return 0;
}
