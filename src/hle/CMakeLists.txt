add_library(hle STATIC)
target_sources(hle PRIVATE
    hle.cc
    loader/loader.cc
)
target_link_libraries(hle PUBLIC
    common
)
