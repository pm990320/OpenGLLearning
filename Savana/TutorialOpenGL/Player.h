#pragma once

#include "Texture.h"
#include <GL/glew.h>
#include <vector>
#include <array>

using namespace Utilities;

class Player
{
private:
	double val = 0.0;

	GLuint _vao;
	GLuint _vbo;
	GLuint _program;
	GLuint _vs;
	GLuint _fs;
	GLuint _texHyena;
	GLuint _texPumba;

	GLuint att_position;
	GLuint att_texcoord;
	GLuint uni_texHyena;
	GLuint uni_texPumba;
	GLuint uni_time;

public:
	Player();
	~Player();

	void update();
	void draw();
};
