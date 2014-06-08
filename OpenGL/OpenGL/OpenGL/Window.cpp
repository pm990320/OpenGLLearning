#include "Window.h"

using namespace oglplus;

Window::Window() {
	window.setMouseCursorVisible(true);
	window.setFramerateLimit(30);
	window.setVisible(true);

	gl.ClearColor(0, 0.5, 1, 1);
}
