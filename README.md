# circular_iterator
C++ circular iterator compliant with STL containers using Boost

## What is it:
**circular_iterator** converts a typical linear form container (like `std::vector`) to a circular form or so called ring. User would pass two iterators (e.g. `begin` and `end`) of the container to the circular_iterator constructor. circular_iterator will provide `increment`, `decrement`, `operator ++` and `operator --`.
## License:
circular_iterator is distributed under the [MIT License](https://github.com/navidcity/circular_iterator/blob/main/LICENSE).
## Build and Install:
>Note: Depending on how you would use the library, you might not need to install it (see Basic Usage)
###Build from source:
Clone the repository. Inside the directory run the following commands:
```cmake
mkdir build
cmake -B build
```
>Note: You might want to add
>   `-DBUILD_TESTING=false` or `true`
>   and
>   `-DNDEBUG` to shut the runtime assertion down
then
```cmake
cmake --build build --config Release --target install
```
>Note: The last step will build the library and install it system wide, therefore it might need admins rights.

## Basic usage:
#### Use with cmake:
The library officially supports two ways how it can be used with cmake. You can find examples for both methods in the examples folder.
1. FetchContent (Recommended, no installation required)
2. FindPackage (installation required, see above)

Both methods will provide the `circular_iterator::circular_iterator` target.
## Contact:
- Issues at [Issues section](https://github.com/navidcity/circular_iterator/issues)
- Email at *navidcity@gmail.com*
