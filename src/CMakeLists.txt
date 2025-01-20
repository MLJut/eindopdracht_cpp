# Specify sources, add new sources below to add them to the build target
set(SRCS
    main.cpp
)

# Specify header files, not required for building but makes the development environment
set(HPPS
)

# Specify template files, not required for building but makes the development environment
set(TPPS
)

add_executable(CPLUS ${SRCS} ${HPPS})

target_link_libraries(CPLUS PRIVATE CPLUS-lib)
