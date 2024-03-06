find_package(Boost 1.74.0 REQUIRED)

add_library(utils STATIC)
target_sources(utils PUBLIC
    log.cc
    mmapped_file.cc
)
target_link_libraries(utils PUBLIC
    common
    ${Boost_LIBRARIES}
)
