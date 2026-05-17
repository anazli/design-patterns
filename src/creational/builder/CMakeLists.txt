set(BUILDER_TARGET builder)
add_executable(${BUILDER_TARGET} main.cpp
                                 character.cpp
                                 character.h
                                 person.cpp
                                 person.h)
target_include_directories(${BUILDER_TARGET} PRIVATE {CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(${BUILDER_TARGET} PRIVATE "-g")