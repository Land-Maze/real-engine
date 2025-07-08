#pragma once

namespace RealEngine {

    class Renderer {
    public:
        Renderer();
        ~Renderer();

        void Draw();
    private:
        unsigned int m_VAO, m_VBO;
        unsigned int m_ShaderProgram;

        unsigned int CompileShader(unsigned int type, const char* source);
        unsigned int CreateShaderProgram(const char* vertexSrc, const char* fragmentSrc);
    };

}
