#include "Player.h"

using namespace Utilities;

Player::Player()
{
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	GLfloat _vert[]{
		-0.5f, 0.5f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.0f, 0.0f,
		-0.5f, -0.5f, 1.0f, 0.0f
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vert) * sizeof(GLfloat), _vert, GL_STATIC_DRAW);


	_vs = ShaderUtils::loadShaderFromFile("shaders/texture.vertexshader", true);
	_fs = ShaderUtils::loadShaderFromFile("shaders/texture.fragmentshader", false);
	_program = ShaderUtils::createProgramFromShaders(_vs, _fs);
	glBindFragDataLocation(_program, 0, "outColor");
	glLinkProgram(_program);
	glUseProgram(_program);


	att_position = glGetAttribLocation(_program, "position");
	glEnableVertexAttribArray(att_position);
	glVertexAttribIPointer(att_position, 2, GL_FLOAT, GL_FALSE, 0);
	att_texcoord = glGetAttribLocation(_program, "texcoord");
	glEnableVertexAttribArray(att_texcoord);
	glVertexAttribIPointer(att_texcoord, 2, GL_FLOAT, GL_FALSE, (void*)(2*sizeof(float)));

	uni_texHyena = glGetUniformLocation(_program, "texHyena");
	uni_texPumba = glGetUniformLocation(_program, "texPumba");
	uni_time = glGetUniformLocation(_program, "time");

	glActiveTexture(GL_TEXTURE0);
	_texHyena = TextureUtils::loadTexture("textures/hyena.png");
	glBindTexture(GL_TEXTURE_2D, _texHyena);
	glActiveTexture(GL_TEXTURE1);
	_texPumba = TextureUtils::loadTexture("textures/pumba.png");
	glBindTexture(GL_TEXTURE_2D, _texPumba);

	glUniform1i(uni_texHyena, 0);
	glUniform1i(uni_texPumba, 1);
}


Player::~Player()
{
	glDeleteProgram(_program);
	glDeleteShader(_vs);
	glDeleteShader(_fs);
	glDeleteBuffers(1, &_vbo);
	glDeleteVertexArrays(1, &_vao);
	
}


void Player::update() {
	glBindVertexArray(_vao);

	val += 0.1;

	glUniform1f(uni_time, val);
}


void Player::draw() {
	glBindVertexArray(_vao);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glUseProgram(_program);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}
