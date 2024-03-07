add_library(loader STATIC)
target_sources(loader PUBLIC
    loader.cc
    nso.cc
)
target_link_libraries(loader PUBLIC
    common
)
