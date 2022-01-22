include(FetchContent)

FetchContent_Declare(circular_iterator
  GIT_REPOSITORY https://github.com/navidcity/circular_iterator.git
  GIT_TAG        origin/main
)

add_subdirectory(circular_iterator)
