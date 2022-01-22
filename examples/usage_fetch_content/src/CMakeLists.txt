add_executable(example)

target_compile_features(example PRIVATE cxx_std_17)

target_link_libraries(example
    PRIVATE
        circular_iterator::circular_iterator
)

target_sources(example PRIVATE
    main.cpp
    )
