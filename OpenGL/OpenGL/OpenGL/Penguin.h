#pragma once
#include "Shape.h"
#include "Camera.h"
#include "Window.h"
#include <oglplus/all.hpp>
using namespace oglplus;

class Penguin :
	public Shape
{
	Context gl;
	Program program;
	VertexShader vs;
	FragmentShader fs;
	Buffer vertexPositionBuffer;
	Buffer vertexColorBuffer;
	Buffer ebo;
	VertexArray vao;

	Uniform<Mat4f> Model;
	Uniform<Mat4f> View;
	Uniform<Mat4f> Projection;

	Cam::Camera& camera;
	Window& window;
public:
	Penguin(Cam::Camera& c, Window& w);

	void draw() const override;
	void update() override;

	virtual ~Penguin();
};

