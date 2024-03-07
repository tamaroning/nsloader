add_library(debugger STATIC)
target_sources(debuger PUBLIC
    debugger.cc
    gdbstub.cc
)
target_link_libraries(debugger PUBLIC
    common
)
