add_executable(Sandbox main.cpp)

target_link_libraries(Sandbox PRIVATE glad imgui glfw OpenGL::GL Engine)

target_link_libraries(Sandbox PRIVATE Engine)

target_include_directories(Sandbox
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)