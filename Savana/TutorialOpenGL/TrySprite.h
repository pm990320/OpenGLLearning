#pragma once

#include <oglplus\gl.hpp>
#include <oglplus\all.hpp>
#include <oglplus\opt\smart_enums.hpp>
#include <oglplus\images\load.hpp>
#include <ctime>

using namespace oglplus;

class TrySprite
{
private:
	VertexShader vs{ GLSLSource::FromFile("shaders/texture.vertexshader") };
	FragmentShader fs{ GLSLSource::FromFile("shaders/texture.fragmentshader") };
	Program program;

	Texture text;
	Texture text_p;

	Buffer posbuf, texcoordbuf;
	VertexArray vao;

	VertexArrayAttrib position{ program, VertexAttribSlot{ 0 } };
	VertexArrayAttrib tex{ program, VertexAttribSlot{1} };

	UniformSampler texHyena;
	UniformSampler texPumba;
	Uniform<float> time;
public:
	TrySprite();
	virtual ~TrySprite();
	void Render(Context gl);
};

