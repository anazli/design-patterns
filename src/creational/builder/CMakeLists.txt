set(BUILDER_TARGET builder)
add_executable(${BUILDER_TARGET} main.cpp)
target_include_directories(${BUILDER_TARGET} PRIVATE {CMAKE_CURRENT_SOURCE_DIR})