add_library(core STATIC)
target_sources(core PUBLIC
    system.cc
)
target_link_libraries(core PUBLIC
    common
    hle
)

add_subdirectory(hle)
