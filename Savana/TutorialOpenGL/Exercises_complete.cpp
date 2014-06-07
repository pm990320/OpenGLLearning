#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Utils.h"
#include <cmath>

/*
Diferent Vertex Datas

Rectangle with Color
	-0.5f, 0.5f, 1.0f, 0.0f, 0.0f, // Vertex 1: Red
	0.5f, 0.5f, 0.0f, 1.0f, 0.0f, // Vertex 2: Green
	-0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  // Vertex 3: Blue
	0.5f, -0.5f, 1.0f, 1.0f, 1.0f   // Vertex 4: White

Basic Triangle
	0.0f,  0.5f, // Vertex 1 (X, Y)
	0.5f, -0.5f, // Vertex 2 (X, Y)
	-0.5f, -0.5f  // Vertex 3 (X, Y)

Triangle with Color
	0.0f,  0.5f, 1.0f, 0.0f, 0.0f,
	0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
	-0,5f, -0.5f, 0.0f, 0.0f, 1.0f



// Shader sources
const GLchar* vertexSource = {
	"#version 150 core\n"

	"in vec2 position;"
	"in float color;"

	"out vec3 Color;"

	"void main() {"
	"   Color = vec3(color, color, color);"
	"   gl_Position = vec4(position, 0.0, 1.0);"
	"}" };

const GLchar* fragmentSource = {
	"#version 150 core\n"

	"in vec3 Color;"
	"out vec4 outColor;"

	"void main() {"
	"   outColor = vec4(Color, 1.0);"
	"}" };

int ma()
{
	// context creation
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	//GLFWwindow* window = glfwCreateWindow(1920, 1080, "Tutorial", glfwGetPrimaryMonitor(), nullptr);  // fullscreen
	GLFWwindow* window = glfwCreateWindow(640, 360, "Tutorial", nullptr, nullptr);  // windowed
	glfwMakeContextCurrent(window);

	// glew initialisation
	glewExperimental = true;
	glewInit();

	// Create a Vertex Buffer Object and copy the vertex data to it
	GLuint vbo;
	glGenBuffers(1, &vbo);
	GLfloat vertices[] = {
		0.0f, 0.5f, 1.0f,
		0.5f, -0.5f, 0.55f,
		-0.5f, -0.5f, 0.25f,
	};
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Create and compile the vertex shader
	GLuint vertexShader = ShaderUtils::createShader(vertexSource, true);

	// Create and compile the fragment shader
	GLuint fragmentShader = ShaderUtils::createShader(fragmentSource, false);

	// Link the vertex and fragment shader into a shader program
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	// Create Vertex Array Object
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Specify the layout of the vertex data
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 3*sizeof(GL_FLOAT), 0);

	GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 1, GL_FLOAT, GL_FALSE, 3*sizeof(GL_FLOAT), (void*)(2*sizeof(GL_FLOAT)));

	while (glfwWindowShouldClose(window) != GL_TRUE)
	{
		glfwPollEvents();
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwDestroyWindow(window);
			break;
		}

		// Clear the screen to black
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw a triangle from the 3 vertices
		glDrawArrays(GL_TRIANGLES, 0, 3);
		// Swap buffers
		glfwSwapBuffers(window);
	}

	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);

	glDeleteBuffers(1, &vbo);

	glDeleteVertexArrays(1, &vao);

	return 0;
}

*/