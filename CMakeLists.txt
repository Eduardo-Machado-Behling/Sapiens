cmake_minimum_required(VERSION 3.0.0)
project(Sapiens VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_custom_command(
    OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/assets ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
    DEPENDS ${CMAKE_SOURCE_DIR}/assets
    COMMENT "Copying assets to bin directory"
)

add_custom_target(copy_assets ALL
    DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
)


include_directories(include)
add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
