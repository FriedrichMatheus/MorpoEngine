cmake_minimum_required(VERSION 3.20)
project(MorpoEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/SDL)

add_library(MorpoEngine
    src/MorpoEngine/Core/Application.cpp
    src/MorpoEngine/Window/Window.cpp
    src/MorpoEngine/Input/Input.cpp
    src/MorpoEngine/Renderer/Renderer.cpp
)

target_include_directories(MorpoEngine
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(MorpoEngine
    PRIVATE SDL2::SDL2
)

add_executable(game
    app/Main.cpp
)

target_link_libraries(game
    PRIVATE MorpoEngine
)

if (WIN32)
    target_link_libraries(game PRIVATE SDL2::SDL2main)

    add_custom_command(TARGET game POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SDL2::SDL2>
            $<TARGET_FILE_DIR:game>
    )
endif()