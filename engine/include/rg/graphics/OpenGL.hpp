//
// Created by spaske on 12/3/24.
//

#ifndef OPENGL_HPP
#define OPENGL_HPP
#include <cstdint>
#include <filesystem>
#include <rg/resources/Shader.hpp>

// TODO(mspasic): Add GL_ASSERT(...)

namespace rg::resources {
    class Skybox;
}

namespace rg::graphics {
    class OpenGL {
    public:
        using ShaderProgramId = uint32_t;

        static bool initialize(void *(*loader)(const char *name));

        static uint32_t generate_texture(const std::filesystem::path &path, bool flip_uvs);

        static int32_t texture_format(int32_t number_of_channels);

        static uint32_t init_skybox_vao();

        static bool shader_compiled_successfully(uint32_t shader_id);

        static bool compile_shader(uint32_t shader_id, const std::string &shader_source);

        static uint32_t load_skybox_textures(const std::filesystem::path &path, bool flip_uvs = false);

        static void enable_depth_testing();

        static void clear_buffers();

        static void terminate();

        static std::string get_compilation_error_message(uint32_t shader_id);
    };
}
#endif //OPENGL_HPP