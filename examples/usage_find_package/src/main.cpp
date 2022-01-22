#include <vector>
#include <iostream>
#include <unistd.h>
#include <circular_iterator/circular_iterator.h>

auto main()->int
{
    std::vector<int> vec { 1, 2, 3, 4};

    auto c_iter = cycle_iterator<decltype (vec.begin())>(vec.begin(), vec.end());

    while(true)
    {
        std::cout << *c_iter++ << std::endl;

        sleep(1);
    }
    return EXIT_SUCCESS;
}
