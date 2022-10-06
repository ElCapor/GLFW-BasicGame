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
    unsigned int VBOs; // i suggest refactor this to "ID" as it makes more sense
    unsigned int vertexShader; // remove all of this when shader class is done
    unsigned int fragmentShader;
    unsigned int shaderProgram;
};

#endif