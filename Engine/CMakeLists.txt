add_library(Engine STATIC)

target_sources(Engine
    PRIVATE
        Core/Application.cpp
        Core/Application.h
)

target_include_directories(Engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)