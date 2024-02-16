include(FetchContent)
set(SFML_VERSION "2.5.1")

FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG        "${SFML_VERSION}"
)

FetchContent_GetProperties(sfml)
if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()
FetchContent_MakeAvailable(sfml)

include_directories(${sfml_SOURCE_DIR}/include)
find_package(OpenCV REQUIRED)

set(
    SOURCE
    main.cpp
    Window.cpp
    AssetManager.cpp
    TitleBar.cpp
    Interactables/Button.cpp
    Interactables/Dropdown.cpp
)

add_executable(Sapiens WIN32 ${SOURCE})

target_compile_definitions(Sapiens PUBLIC SFML_STATIC)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Sapiens POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Sapiens> $<TARGET_FILE_DIR:Sapiens> COMMAND_EXPAND_LISTS)
endif()

add_dependencies(Sapiens copy_assets)

target_link_libraries(Sapiens
    PRIVATE
        sfml-audio
        sfml-graphics
        sfml-system
        sfml-window
)