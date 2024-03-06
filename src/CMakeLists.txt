cmake_minimum_required(VERSION 3.16)

add_executable(nsloader)
target_sources(nsloader PRIVATE
    main.cc
    )
target_link_libraries(nsloader PRIVATE
    common
    utils
    hle
    )

add_subdirectory(utils)
add_subdirectory(hle)
