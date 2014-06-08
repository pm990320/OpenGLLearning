/*
 * Pyramid.cpp
 *
 *  Created on: 6 Jun 2014
 *      Author: Patrick
 */

#include "Pyramid.h"

Pyramid::Pyramid(Window& w, Cam::Camera& c) : window{ w }, camera{ c } {
	nVertices = 5;
	nIndices = 18;

	vs.Source(GLSLSource::FromFile("shaders/pyramid_vs.glsl"));
	vs.Compile();
	program.AttachShader(vs);

	fs.Source(GLSLSource::FromFile("shaders/pyramid_fs.glsl"));
	fs.Compile();
	program.AttachShader(fs);
	program.Link();
	program.Use();

	vao.Bind();
	vbo.Bind(Buffer::Target::Array);
	float positions[] = {  // TODO finish vertices
		//	X		Y		Z
			0,		0.5,	0,			// 0
			-0.25,	0,		-0.25,		// 1
			0.25,	0,		-0.25,		// 2
			-0.25,	0,		0.25,		// 3
			0.25,	0,		0.25		// 4
	};
	Buffer::Data(Buffer::Target::Array, sizeof(positions), positions, BufferUsage::StaticDraw);
	VertexArrayAttrib position{ program, "position" };
	position.Setup<Vec3f>();
	position.Enable();

	ebo.Bind(Buffer::Target::ElementArray);
	unsigned short indices[] = {
		0, 1, 2,
		0, 1, 3,
		0, 3, 4,
		0, 2, 4,
		1, 2, 3,
		2, 3, 4
	};
	Buffer::Data(Buffer::Target::ElementArray, sizeof(indices), indices, BufferUsage::StaticDraw);

	Model 		= Uniform<Mat4f>{ program, "Model"};
	View 		= Uniform<Mat4f>{ program, "View" };
	Projection 	= Uniform<Mat4f>{ program, "Projection" };

	Model.SetValue(ModelMatrixf::TranslationZ(-2.0f));
	Projection.SetValue(camera.getProjectionMatrix());

	color = Uniform<Vec3f>{program, "color"};

}

void Pyramid::draw() const {
	vao.Bind();
	vbo.Bind(Buffer::Target::Array);
	ebo.Bind(Buffer::Target::ElementArray);

	window.gl.DrawElements(PrimitiveType::Triangles, nIndices, DataType::UnsignedShort);
}

void Pyramid::update() {
	vao.Bind();
	View.SetValue(camera.getWorldToViewMatrix());
	color.SetValue(Vec3f{0.0f, 1.0f, 0.0f});
}

Pyramid::~Pyramid() {
	
}
