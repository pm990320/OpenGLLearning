#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Utils.h"

int mamma() {
	// context creation
	glfwInit();
	glfwWindowHint(GLFW_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(1920, 1080, "Mamma", glfwGetPrimaryMonitor(), nullptr);
	glfwMakeContextCurrent(window);

	// GLEW
	glewExperimental = true;
	glewInit();


	// vertex data (VBO)
	GLfloat vertices[] = {
		//	  X        Y		 R      G      B
			  0.0f,     0.0f,   1.0f,  1.0f,  1.0f,
			 -0.25f,    0.5f,	0.0f,  0.0f,  1.0f,
			  0.25f,    0.5f,	1.0f,  0.0f,  0.0f,
			  0.433f, 0.0f, 1.0f, 1.0f, 0.0f,
			  0.25f,   -0.5f,	0.0f,  1.0f,  0.0f,
			 -0.25f,   -0.5f,	1.0f,  0.0f,  0.5f,
			 -0.433f, 0.0f, 0.4f, 0.2f, 0.0f
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// shader stuff
	GLint vertexShader = ShaderUtils::loadShaderFromFile("shaders/mamma.vertexshader", true);
	GLint fragmentShader = ShaderUtils::loadShaderFromFile("shaders/mamma.fragmentshader", false);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);


	// VAO
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint pos = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GL_FLOAT), 0);

	GLuint color = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(color);
	glVertexAttribPointer(color, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GL_FLOAT), (void*)(2*sizeof(GL_FLOAT)));

	// element buffer object
	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	GLushort order[] = {
		0, 1, 2,
		0, 2, 3,
		0, 3, 4,
		0, 4, 5,
		0, 5, 6,
		0, 6, 1
	};
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(order), order, GL_STATIC_DRAW);

	// main loop
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
			glfwSetWindowShouldClose(window, GL_TRUE);
		}

		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_SHORT, 0);

		glfwSwapBuffers(window);
	}

	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
	glDeleteProgram(shaderProgram);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glDeleteVertexArrays(1, &vao);

	return 0;
}