add_library(cpu STATIC)
target_sources(cpu PUBLIC
    cpu.cc
)
target_link_libraries(cpu PUBLIC
    common
    dynarmic
)
