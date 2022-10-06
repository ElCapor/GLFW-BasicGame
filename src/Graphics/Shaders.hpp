#ifndef SHADERS_HPP
#define SHADERS_HPP
#include <string>
#include <fstream>
#include <iostream>
// sample shader class
class Shader{
public:
unsigned int ID;
std::string vertex_Path; // path to vertex
std::string fragment_Path; // path to frag

//is_string = inputed vertex are just strings
// else = path by default
Shader(const char* vertexPath, const char* fragmentPath, bool is_string=false)
{
    std::ifstream vertexShaderFile, fragmentShaderFile;
    vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit); // make sure these exceptions are enabled
    fragmentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {

    }
    catch (std::ifstream::failure &exception)
    {
        std::cout << "[ERROR] SHADER::SHADER() reading file failed for reason " << e.what()
    }
}

};
#endif