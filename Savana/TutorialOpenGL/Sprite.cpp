#include "Sprite.h"

Sprite::Sprite() {
	glGenBuffers(1, &_vbo);
	glGenVertexArrays(1, &_vao);
}

void Sprite::create_shader_program(std::string vs_name, std::string fs_name, std::vector<std::string> fd){
	_program.compile_vertex_shader(vs_name.c_str());
	_program.compile_fragment_shader(fs_name.c_str());
	_program.attach_shaders_to_program();

	fragdata = { fd };
	int no = 0;
	for (auto& x : fd) {
		_program.bind_frag_data_location(no, x.c_str());
		no++;
	}

	_program.link();
}

Sprite::~Sprite()
{
	
}

GLuint Sprite::get_vbo() {
	return _vbo;
}

GLuint Sprite::get_vao() {
	return _vao;
}

ShaderProgram Sprite::get_program() {
	return _program;
}

void Sprite::create_attribute(std::string name, int size, GLuint type, GLboolean norm, int stride, void* offset) {
	glBindVertexArray(_vao);
	_program.add_attribute(name);
	_program.setup_attribute(name, size, type, norm, stride, offset);
	glBindVertexArray(NULL);
}

void Sprite::create_uniform(std::string name) {
	glBindVertexArray(_vao);
	_program.add_uniform(name);
	glBindVertexArray(NULL);
}

void Sprite::data_upload_vbo(void* data, GLuint drawing_mode) {
	glBindVertexArray(_vao);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, drawing_mode);

	glBindBuffer(GL_ARRAY_BUFFER, NULL);
	glBindVertexArray(NULL);
}

void Sprite::data_sub_upload_vbo(int n_arrays, void* data[], GLuint drawing_mode){
	glBindVertexArray(_vao);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

	int size = 0;
	for (int i = 0; i < n_arrays; i++) {
		size += sizeof(data[i]);
	}

	glBufferData(GL_ARRAY_BUFFER, size, NULL, GL_STATIC_DRAW);

	for (int i = 0; i < n_arrays; i++) {
		if (i == 0) {
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(data[i]), data[i]);
		}
		if (i != 0) {
			glBufferSubData(GL_ARRAY_BUFFER, sizeof(data[i - 1]), sizeof(data[i]), data[i]);
		}
	}
	
	glBindBuffer(GL_ARRAY_BUFFER, NULL);
	glBindVertexArray(NULL);
}