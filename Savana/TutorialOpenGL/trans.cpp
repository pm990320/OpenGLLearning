#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Utils.h"
#include <ctime>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int trans() {
	// context creation
	glfwInit();
	glfwWindowHint(GLFW_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(640, 480, "Mamma", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	// GLEW
	glewExperimental = true;
	glewInit();


	// vertex data (VBO)
	GLfloat vertices[] = {
		//	  X        Y		 R      G      B
		0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		-0.25f, 0.5f, 0.0f, 0.0f, 1.0f,
		0.25f, 0.5f, 1.0f, 0.0f, 0.0f,
		0.433f, 0.0f, 1.0f, 1.0f, 0.0f,
		0.25f, -0.5f, 0.0f, 1.0f, 0.0f,
		-0.25f, -0.5f, 1.0f, 0.0f, 0.5f,
		-0.433f, 0.0f, 0.4f, 0.2f, 0.0f
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// shader stuff
	GLint vertexShader = Utilities::ShaderUtils::loadShaderFromFile("shaders/trans_vs.vertexshader", true);
	GLint fragmentShader = Utilities::ShaderUtils::loadShaderFromFile("shaders/trans_fs.fragmentshader", false);

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
	glVertexAttribPointer(color, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GL_FLOAT), (void*)(2 * sizeof(GL_FLOAT)));

	GLuint unimodel = glGetUniformLocation(shaderProgram, "model");
	GLuint uniview = glGetUniformLocation(shaderProgram, "view");
	GLuint uniproj = glGetUniformLocation(shaderProgram, "proj");

	int width, height;
	glfwGetWindowSize(window, &width, &height);

	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 proj = glm::perspective(45.0f, (float)width/height, 1.0f, 10.0f);
	view = glm::lookAt(
		glm::vec3(0.0f, 0.0f, 2.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
		);
	model = glm::rotate(model, 0.25f, glm::vec3(1.0, 0.0, 0.0));
	glUniformMatrix4fv(uniproj, 1, GL_FALSE, glm::value_ptr(proj));
	glUniformMatrix4fv(uniview, 1, GL_FALSE, glm::value_ptr(view));

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

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glClearColor(0.0, 0.5, 1.0, 1.0);

	// main loop
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
			glfwSetWindowShouldClose(window, GL_TRUE);
		}

		model = glm::rotate(model, 0.01f, glm::vec3(0.0, 0.0, 1.0));
		glUniformMatrix4fv(unimodel, 1, GL_FALSE, glm::value_ptr(model));

		glClear(GL_COLOR_BUFFER_BIT);

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