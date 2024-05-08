cmake_minimum_required(VERSION 3.11)

############## Sources ###############
file(GLOB sources src/*.cpp)
file(GLOB headers include/*.hpp)

add_library(rg-engine ${sources} ${headers})

target_include_directories(rg-engine PUBLIC include/)
target_link_libraries(rg-engine glfw glad OpenGL::GL spdlog::spdlog)
add_dependencies(rg-engine glfw glad OpenGL::GL spdlog::spdlog)