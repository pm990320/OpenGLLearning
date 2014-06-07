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
	VertexShader vs { GLSLSource::FromFile("C:/Users/Patrick/Documents/PROGRAMMING/OPENGL/Eclipse/Source/pyramid_vs.glsl") };
	FragmentShader fs { GLSLSource::FromFile("C:/Users/Patrick/Documents/PROGRAMMING/OPENGL/Eclipse/Source/pyramid_fs.glsl") };
	Program program;
	VertexArray vao;
	Buffer vbo;
	Buffer ebo;

	const int nVertices = 3;
	float positions[9] = {  // TODO finish vertices
		//	X		Y		Z
			0,		0.5,	0,
			-0.25,	0,		-0.25,
			0.25,	0,		-0.25,	
	};
	VertexArrayAttrib position{ program, VertexAttribSlot{0} };
	Uniform<Mat4f> Model;
	Uniform<Mat4f> View;
	Uniform<Mat4f> Projection;
	Uniform<Vec3f> color;
public:
	Pyramid(sf::Window& w);

	void draw(Context gl);
	void update();

	virtual ~Pyramid();
};


