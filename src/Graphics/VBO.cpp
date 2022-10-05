#include "VBO.hpp"

VBO::VBO() {
    std::cout << "[Log] VBO.cpp called!" << std::endl;
}

VBO::~VBO() {

}

void VBO::construct() {
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // x, y, z
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    glGenBuffers(1, &VBOs);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    const char *vertexShaderSource = "#version 330 core\n" // Vertex shader
    "layout (location = 0) in vec3 aPos;\n"
    "void main() {\n"
    "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // check if vertex shader is compiled successfully
    int isVertexShaderCompiled;
    char infoLogVertexShader[512];
    
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isVertexShaderCompiled);
    if(isVertexShaderCompiled) {
        std::cout << "[Log] Compiled vertex shader: ok" << std::endl;
        
        const char *fragmentShaderSource = "#version 330 core\n" // Color shader
        "out vec4 FragColor;\n"
        "void main() {\n"
        "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\0";

        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);

        // check if fragment shader is compiled successfully
        int isFragmentShaderCompiled;
        char infoLogFragmentShader[512];

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isFragmentShaderCompiled);
        if(isFragmentShaderCompiled) {
            std::cout << "[Log] Compiled fragment shader: ok" << std::endl;

            shaderProgram = glCreateProgram();
            glAttachShader(shaderProgram, vertexShader);
            glAttachShader(shaderProgram, fragmentShader);
            glLinkProgram(shaderProgram);

            // check if shader program is linked successfully
            int isShaderProgramLinked;
            glGetProgramiv(shaderProgram, GL_LINK_STATUS, &isShaderProgramLinked);

            if(isShaderProgramLinked) {
                std::cout << "[Log] Linked shader program: ok" << std::endl;

                // need to delete shaders now cause we linked it successfully
                glDeleteShader(vertexShader);
                glDeleteShader(fragmentShader);

                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); // vertex data
                glEnableVertexAttribArray(0);

                glUseProgram(shaderProgram);
            } else {
                std::cout << "[Log] Can't link shader program ;(" << std::endl;
            }

        } else {
            std::cout << "[Log] Can't compile fragment shader ;( | OpenGL error: " << infoLogFragmentShader << std::endl;
        }

    } else {
        std::cout << "[Log] Can't compile vertex shader ;( | OpenGL error: " << infoLogVertexShader << std::endl;
    }
}

void VBO::destruct() {
    
}