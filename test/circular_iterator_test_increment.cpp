#include <cstdlib>
#include <circular_iterator.h>
#include <vector>
#include <iostream>

auto main()->int
{
    auto const vec  {std::vector<int>{1,2,3}};

    auto c_iter {circular_iterator<decltype (vec.begin())>(vec.begin(), vec.end())};

    if(*c_iter != 1)
    {
        std::cerr << "c_iter != 1" << std::endl;
        return EXIT_FAILURE;
    }
    c_iter.increment();
    if(*c_iter != 2)
    {
        std::cerr << "1:c_iter != 2" << std::endl;
        return EXIT_FAILURE;
    }
    if(*c_iter++ != 2)
    {
        std::cerr << "2:c_iter != 2" << std::endl;
        return EXIT_FAILURE;
    }
    if(*c_iter != 3)
    {
        std::cerr << "c_iter != 3" << std::endl;
        return EXIT_FAILURE;
    }
    if(*++c_iter != 1)
    {
        std::cerr << "loop:c_iter != 1" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
