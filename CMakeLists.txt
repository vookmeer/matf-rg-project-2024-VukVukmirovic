cmake_minimum_required(VERSION 3.21)
project(matf-rg-project)

set(CMAKE_CXX_STANDARD 20)

################ Libs ################
# OpenGL
find_package(OpenGL REQUIRED)

# spdlog
add_subdirectory(libs/spdlog)
add_compile_definitions(SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE SPDLOG_DEBUG_ON SPDLOG_TRACE_ON)

#glfw
add_subdirectory(libs/glfw)

# glad
add_subdirectory(libs/glad)

# rg-engine
add_subdirectory(rg-engine)

set(LIBS glfw glad OpenGL::GL spdlog::spdlog rg-engine)

############## Sources ###############

file(GLOB sources src/*.cpp)
file(GLOB headers include/*.hpp)

################ Exec ################
add_executable(${PROJECT_NAME} ${sources} ${headers})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS})
add_dependencies(${PROJECT_NAME} ${LIBS})