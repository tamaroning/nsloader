add_library(arm STATIC)
target_sources(arm PUBLIC
    arm_interface.cc
)
target_link_libraries(arm PUBLIC
    common
)
