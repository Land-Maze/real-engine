add_library(Engine STATIC)

target_sources(Engine
    PRIVATE
        Core/Application.cpp
        Core/Application.h
 "Core/Window.h" "Core/Window.cpp" "Renderer/Renderer.h" "Renderer/Renderer.cpp")

target_include_directories(Engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(Engine PRIVATE glfw glad)