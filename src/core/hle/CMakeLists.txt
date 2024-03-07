add_library(hle STATIC)
target_sources(hle PUBLIC
)
target_link_libraries(hle PUBLIC
    common
    kernel
    loader
)

add_subdirectory(kernel)
add_subdirectory(loader)
