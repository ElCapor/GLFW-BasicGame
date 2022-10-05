#ifndef VBO_HPP
#define VBO_HPP

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VBO {

public:
    VBO();
    ~VBO();

    void construct();
    void destruct();
private:
    unsigned int VBOs;
    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int shaderProgram;
};

#endif