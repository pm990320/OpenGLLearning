/*
 * Pyramid.h
 *
 *  Created on: 6 Jun 2014
 *      Author: Patrick
 */

#pragma once

#include <GL/glew.h>
#include "Camera.h"
#include "Shape.h"
#include "Window.h"
#include <oglplus/site_config.hpp>
#include <oglplus/all.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <cmath>
using namespace oglplus;

class Pyramid : public Shape {
	VertexShader vs;
	FragmentShader fs;
	Program program;
	VertexArray vao;
	Buffer vbo;
	Buffer ebo;

	Uniform<Mat4f> Model;
	Uniform<Mat4f> View;
	Uniform<Mat4f> Projection;
	Uniform<Vec3f> color;

	Cam::Camera& camera;
	Window& window;
public:
	Pyramid(Window& w, Cam::Camera& c);

	void draw() const override;
	void update() override;

	virtual ~Pyramid();
};


