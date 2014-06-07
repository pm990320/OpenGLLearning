#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Utils.h"

// Shader sources 
/*
const GLchar* vertexSource = {
	"#version 150 core\n"
	"in vec2 position;"
	"void main() {"
	"   gl_Position = vec4(position, 0.0, 1.0);"
	"}" };
const GLchar* fragmentSource = {
	"#version 150 core\n"
	"out vec4 outColor;"
	"void main() {"
	"   outColor = vec4(1.0, 1.0, 1.0, 1.0);"
	"}" };

int asdf()
{
	// context creation
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	GLFWwindow* window = glfwCreateWindow(640, 360, "Tutorial", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	// glew initialisation
	glewExperimental = true;
	glewInit();

	std::cout << glGetString(GL_VERSION);

	// Create a Vertex Buffer Object and copy the vertex data to it
	GLuint vbo;
	glGenBuffers(1, &vbo);

	GLfloat vertices[] = {
		0.0f, 0.5f,
		0.5f, -0.5f,
		-0.5f, -0.5f
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
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

	while (glfwWindowShouldClose(window) != GL_TRUE)
	{
		glfwPollEvents();

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

/*

So, just to recap.  

Vertex Data is put in VBOs via the glBindBuffers() and glBufferData() functions.

Then, shaders are compiled and a shader program is made current using glUseProgram().

The VAO is then told the layout of the vertex data with glVertexAttribPointer(). The VAO gets it's data from the buffer which is currently glBindBuffer()ed to GL_ARRAY_BUFFER.
Thus the VAO gets it's info from our vbo.

This means that when glDrawArrays() is called it draws whatever VAO is currently bound, which is vao, and vao takes it's vertex data from vbo.

I FINALLY UNDERSTAND THIS MOTHERFUCKING CONCEPT AAAAHHH


Edit: function name changed to gobldygook so that it does not interfear with main, but this one was a real learning curve.

*/