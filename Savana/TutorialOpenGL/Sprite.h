#pragma once

#include "ShaderProgram.h"
#include <vector>

class Sprite
{
private:
	const char* _vertex_shader_name;
	const char* _fragment_shader_name;
	ShaderProgram _program;
	std::vector<std::string> fragdata;

	GLuint _vbo;
	GLuint _vao;
public:
	Sprite();
	~Sprite();

	GLuint get_vbo();
	GLuint get_vao();
	ShaderProgram get_program();

	void data_upload_vbo(void* data, GLuint drawing_mode);
	void Sprite::data_sub_upload_vbo(int n_arrays, void* data[], GLuint drawing_mode);

	void create_shader_program(std::string vs_name, std::string fs_name, std::vector<std::string> fd);
	void create_attribute(std::string name, int size, GLuint type, GLboolean norm, int stride, void* offset);
	void create_uniform(std::string name);

	virtual void update() =0;
	virtual void draw() =0;
};
