/*
 * Pyramid.h
 *
 *  Created on: 6 Jun 2014
 *      Author: Patrick
 */

#ifndef PYRAMID_H_
#define PYRAMID_H_

#include "Shape.h"
#include "Camera.h"
#include <oglplus/gl.hpp>
#include <oglplus/all.hpp>
#include <oglplus/shader.hpp>
#include <oglplus/vertex_attrib.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <cmath>
using namespace oglplus;

class Pyramid : Shape {
	VertexShader vs { GLSLSource::FromFile("C:/Users/Patrick/Documents/PROGRAMMING/OPENGL/Eclipse/Source/pyramid_vs.glsl") };
	FragmentShader fs { GLSLSource::FromFile("C:/Users/Patrick/Documents/PROGRAMMING/OPENGL/Eclipse/Source/pyramid_fs.glsl") };
	Program program;
	VertexArray vao;
	Buffer vbo;
	Buffer ebo;

	float positions[6] = {  // TODO finish vertices
		//	X		Y		Z
			0,		0.5,	0,
			-0.25,	0,
	};
	VertexArrayAttrib position;
	Uniform<Mat4f> Model;
	Uniform<Mat4f> View;
	Uniform<Mat4f> Projection;
	Uniform<Vec3f> color;
public:
	Pyramid(sf::Window& w);

	void draw(Context gl) override;
	void update() override;

	virtual ~Pyramid();
};

#endif /* PYRAMID_H_ */
