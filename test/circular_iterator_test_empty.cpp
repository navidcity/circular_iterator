#include <cstdlib>
#include <circular_iterator.h>
#include <vector>
#include <iostream>

auto main()->int
{
    auto const vec  {std::vector<int>()};

    try
    {
        auto c_iter {circular_iterator<decltype (vec.begin())>(vec.begin(), vec.end())};
    }
    catch(std::invalid_argument const &e)
    {
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}
