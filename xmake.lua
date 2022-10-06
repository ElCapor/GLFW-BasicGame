add_rules("mode.debug", "mode.release")

add_requires("fmt ^7.1.3", "glad ^0.1.34", "glfw ^3.3.4", "glm ^0.9.9", "spdlog ^1.8.5", "stb")
add_requires("imgui", {configs = {glfw_opengl3 = true}})

target("Game")
    set_kind("binary")
    set_targetdir("bin") 
    set_languages("cxx20")
    add_files("src/*.cpp")
    add_files("src/Core/*.cpp")
    add_files("src/Graphics/*.cpp")
    add_packages("fmt", "glad", "glfw", "glm", "spdlog", "stb", "imgui")
