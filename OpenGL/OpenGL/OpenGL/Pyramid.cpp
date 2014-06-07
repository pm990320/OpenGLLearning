/*
 * Pyramid.cpp
 *
 *  Created on: 6 Jun 2014
 *      Author: Patrick
 */

#include "Pyramid.h"

Pyramid::Pyramid(sf::Window& w) {
	vs.Compile();
	fs.Compile();
	program.AttachShader(vs);
	program.AttachShader(fs);

	vao.Bind();
	vbo.Bind(Buffer::Target::Array);
	Buffer::Data(Buffer::Target::Array, sizeof(positions), positions, BufferUsage::StaticDraw);
	position.Bind("position");
	position.Setup<Vec3f>().Enable();

	Model 		= Uniform<Mat4f>{ program, "Model"};
	View 		= Uniform<Mat4f>{ program, "View" };
	Projection 	= Uniform<Mat4f>{ program, "Projection" };

	Model.SetValue(ModelMatrixf::TranslationZ(3.0f));
	Projection.SetValue(CamMatrixf::PerspectiveY(Degrees(60), (float)w.getSize().x/w.getSize().y, 0.3f, 100.0f));

	color = Uniform<Vec3f>{program, "color"};

}

void Pyramid::draw(Context gl){
	vao.Bind();
	vbo.Bind(Buffer::Target::Array);

	gl.DrawArrays(PrimitiveType::Triangles, 0, 2);
}

void Pyramid::update() {
	vao.Bind();
	View.SetValue(Camera::camera.getWorldToViewMatrix());
	color.SetValue(Vec3f{(float)sin(clock()), 0.0f, 0.0f});
}

Pyramid::~Pyramid() {

}
