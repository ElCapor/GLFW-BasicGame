#include "Game.hpp"

Game::Game() {

}

Game::~Game() {
    
}

void Game::init(int width, int height, const char* name) {
    glfwInit();

    // OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // only moderns functions available
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window = glfwCreateWindow(width, height, name, NULL, NULL);

    if(window == NULL) {
        std::cout << "Can't create GLFW window" << std::endl;
        glfwTerminate();
    }
}

void Game::input() {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void Game::viewport(int width, int height) {
    glfwMakeContextCurrent(window);
    gladLoadGL(); // loading glad
    
    glViewport(0, 0, width, height);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //rgba
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
}

void Game::update() {
    while(!glfwWindowShouldClose(window)) {
        Game::input();
        glfwPollEvents();
    }
}

void Game::clean() {
    glfwDestroyWindow(window);
    glfwTerminate();
}