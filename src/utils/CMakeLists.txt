add_library(utils STATIC)
target_sources(utils PRIVATE
    log.cc
)
target_link_libraries(utils PUBLIC
    common
)
