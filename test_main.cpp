#include <stdlib.h>

#include <iostream>
#include <iterator>
#include <vector>
int main()
{
    std::vector<int> as(100, 22);
    as.insert(as.begin(), as.max_size() * 2, 22);
    for (std::size_t i = 0; i < as.size(); i++)
    {
        std::cout << as.at(i) << std::endl;

    }
    return 0;
}
//c++ -Wall -Wextra -Werror -fsanitize=address -std=c++98 test_main.cpp -o test_main