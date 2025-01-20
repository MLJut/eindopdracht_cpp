# Copyright 2023 Spicy Game

# Specify sources, add new sources below to add them to the build target
set(SRCS
)

# Specify header files, not required for building but makes the development environment
set(HPPS
    config.hpp
)

# Specify template files, not required for building but makes the development environment
set(TPPS

)

add_library(CPLUS-lib ${SRCS} ${HPPS})

target_include_directories(CPLUS-lib PUBLIC include)

# target_link_libraries(CPLUS-lib 
#     PUBLIC 
#     $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
# )

target_link_libraries(CPLUS-lib 
    PUBLIC 
    cpr::cpr
)