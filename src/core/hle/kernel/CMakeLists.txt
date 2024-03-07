add_library(kernel STATIC)
target_sources(kernel PUBLIC
    proc_memory.cc
    proc.cc
)
target_link_libraries(kernel PUBLIC
    common
)
