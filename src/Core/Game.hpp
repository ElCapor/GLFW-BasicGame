#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>

class Game {

public:
    Game();
    ~Game();
    
    void init(int width, int height, const char* name);
    void input();
    void viewport(int width, int height);
    void update();
    void clean();
    
private:
    GLFWwindow* window = nullptr;
};

#endif