/*
 * Pyramid.h
 *
 *  Created on: 6 Jun 2014
 *      Author: Patrick
 */

#pragma once

#include "Camera.h"
#include <oglplus/site_config.hpp>
#include <oglplus/all.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <cmath>
using namespace oglplus;

class Pyramid {
	Context gl;
	VertexShader vs;
	FragmentShader fs;
	Program program;
	VertexArray vao;
	Buffer vbo;
	Buffer ebo;

	const int nVertices = 5;
	const int nIndices = 18;
	
	Uniform<Mat4f> Model;
	Uniform<Mat4f> View;
	Uniform<Mat4f> Projection;
	Uniform<Vec3f> color;
	Cam::Camera& camera;
public:
	Pyramid(sf::Window& w, Cam::Camera& c);

	void draw();
	void update();

	virtual ~Pyramid();
};


