add_library(hle STATIC)
target_sources(hle PUBLIC
    loader/loader.cc
    loader/nso.cc
)
target_link_libraries(hle PUBLIC
    common
)
