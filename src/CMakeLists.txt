add_executable(nsloader)
target_sources(nsloader PRIVATE
    main.cc
    )
target_link_libraries(nsloader PRIVATE
    common
    utils
    core
    )

add_subdirectory(utils)
add_subdirectory(core)
