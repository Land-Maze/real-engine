add_executable(Sandbox main.cpp)

target_link_libraries(Sandbox PRIVATE glad imgui glfw OpenGL::GL Engine)
target_include_directories(Sandbox PUBLIC
    ${PROJECT_SOURCE_DIR}/External/glad/include
    ${PROJECT_SOURCE_DIR}/External/imgui
    ${PROJECT_SOURCE_DIR}/External/imgui/backends
)

target_link_libraries(Sandbox PRIVATE Engine)

target_include_directories(Sandbox
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)