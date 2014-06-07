#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Utils.h"
#include <iostream>
#include <ctime>

int cube() {
	// Context Creation
	glfwInit();
	glfwWindowHint(GLFW_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(1920, 1080, "3D", glfwGetPrimaryMonitor(), nullptr);
	glfwMakeContextCurrent(window);

	// GLEW
	glewExperimental = true;
	glewInit();

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	GLfloat position[] = {
	//	X		Y		Z
		-0.5,	0.5,	0.0,
		0.5,	0.5,	0.0,
		-0.5,	-0.5,	0.0,
		0.5,	-0.5,	0.0,
		0.5,	-0.5,	-1.0,
		0.5,	0.5,	-1.0,
		-0.5,	-0.5,	-1.0,
		-0.5,	0.5,	-1.0
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(position), position, GL_STATIC_DRAW);

	// shaders

	GLint vs = ShaderUtils::loadShaderFromFile("shaders/3D.vertexshader", true);
	GLint fs = ShaderUtils::loadShaderFromFile("shaders/3D.fragmentshader", false);
	GLuint program = glCreateProgram();
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glBindFragDataLocation(program, 0, "outColor");
	glLinkProgram(program);
	glUseProgram(program);

	// VAO
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLint pos = glGetAttribLocation(program, "pos");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GLfloat), 0);

	GLint color = glGetUniformLocation(program, "color");

	// main loop
	glClearColor(0.0, 0.0, 0.0, 1.0);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
			glfwSetWindowShouldClose(window, GL_TRUE);
		}

		// clear
		glClear(GL_COLOR_BUFFER_BIT);

		// loop items
		glUniform4f(color, sin(time(0)), cos(time(0)), tan(time(0)), 0.8);


		// draw
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 8);

		// display
		glfwSwapBuffers(window);
	}
	
	// cleanup
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteShader(vs);
	glDeleteShader(fs);
	glDeleteProgram(program);
	return 0;
}