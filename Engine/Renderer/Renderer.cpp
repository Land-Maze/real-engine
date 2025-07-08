#include "Renderer.h"
#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>

namespace RealEngine {

	static std::string ReadFile(const char* filepath) { // NOTE: Abstract this to a FileSystem class later
        std::ifstream file(filepath);
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    Renderer::Renderer() {
        float vertices[] = { // triangle
            -0.5f, -0.5f,
             0.5f, -0.5f,
             0.0f,  0.5f
        };

        glGenVertexArrays(1, &m_VAO);
        glGenBuffers(1, &m_VBO);

        glBindVertexArray(m_VAO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        auto vertexSrc = ReadFile("Shaders/Triangle.vert");
        auto fragmentSrc = ReadFile("Shaders/Triangle.frag");

        m_ShaderProgram = CreateShaderProgram(vertexSrc.c_str(), fragmentSrc.c_str());
    }

    Renderer::~Renderer() {
        glDeleteVertexArrays(1, &m_VAO);
        glDeleteBuffers(1, &m_VBO);
        glDeleteProgram(m_ShaderProgram);
    }

    void Renderer::Draw() {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(m_ShaderProgram);
        glBindVertexArray(m_VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    unsigned int Renderer::CompileShader(unsigned int type, const char* source) {
        unsigned int shader = glCreateShader(type);
        glShaderSource(shader, 1, &source, nullptr);
        glCompileShader(shader);

        int success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            char info[512];
            glGetShaderInfoLog(shader, 512, nullptr, info);
            std::cerr << "[Renderer] Shader compile error: " << info << std::endl;
        }

        return shader;
    }

    unsigned int Renderer::CreateShaderProgram(const char* vertexSrc, const char* fragmentSrc) {
        unsigned int vertexShader = CompileShader(GL_VERTEX_SHADER, vertexSrc);
        unsigned int fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentSrc);

        unsigned int program = glCreateProgram();
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);

        int success;
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (!success) {
            char info[512];
            glGetProgramInfoLog(program, 512, nullptr, info);
            std::cerr << "[Renderer] Program link error: " << info << std::endl;
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return program;
    }

}
