#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Utils.h"
#include "TrySprite.h"
#include <oglplus/site_config.hpp>
#include <oglplus/all.hpp>

using namespace oglplus;

int ogl() {
	glfwInit();
	glfwWindowHint(GLFW_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	GLFWwindow* window = glfwCreateWindow(640, 480, "Textures", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glewInit();
	Context ogl;

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glClearColor(0.0, 0.5, 1.0, 1.0);

	TrySprite ty;

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
			glfwSetWindowShouldClose(window, GL_TRUE);
		}

		ty.Render(ogl);

		glfwSwapBuffers(window);
	}

	return 0;
}