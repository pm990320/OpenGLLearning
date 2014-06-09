#include "Penguin.h"


Penguin::Penguin(Cam::Camera& c, Window& w) : window{ w }, camera{ c }
{
	vs.Source(GLSLSource::FromFile(""));
	vs.Compile();
	program.AttachShader(vs);

	fs.Source(GLSLSource::FromFile(""));
	fs.Compile();
	program.AttachShader(fs);

	program.Link();
	program.Use();

	vao.Bind();

	vertexPositionBuffer.Bind(Buffer::Target::Array);
	float vertex_positions[] = {
		1.0f,  // FINISH POSITIONS
	};
	Buffer::Data(Buffer::Target::Array, vertex_positions);
	VertexArrayAttrib position{ program, "position" };
	position.Setup<Vec3f>().Enable();

	vertexColorBuffer.Bind(Buffer::Target::Array);
	float vertex_colors[] = {
		1.0f,
	};
	Buffer::Data(Buffer::Target::Array, vertex_colors);
	VertexArrayAttrib color{ program, "position" };
	color.Setup<Vec3f>().Enable();

	Model		= Uniform < Mat4f > { program, "Model" };
	View		= Uniform < Mat4f > { program, "View" };
	Projection	= Uniform < Mat4f > { program, "Projection" };

	Model.SetValue(ModelMatrixf::Scale(1, 1, 1));
	Projection.SetValue(camera.getProjectionMatrix());

	ebo.Bind(Buffer::Target::ElementArray);
	unsigned short indices[] = {
		1,
	};
	Buffer::Data(Buffer::Target::ElementArray, indices);


}


void Penguin::draw() const {
	vao.Bind();
	ebo.Bind(Buffer::Target::ElementArray);
	gl.DrawElements(PrimitiveType::Triangles, nIndices, DataType::UnsignedShort);
}


void Penguin::update() {
	vao.Bind();
	View.SetValue(camera.getWorldToViewMatrix());
}


Penguin::~Penguin()
{
}
