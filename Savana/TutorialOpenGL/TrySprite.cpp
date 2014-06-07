#include "TrySprite.h"

TrySprite::TrySprite()
{
	vs.Compile();
	fs.Compile();

	program.AttachShader(vs);
	program.AttachShader(fs);
	program.Link();
	program.Use();

	vao.Bind();

	float pos[8] = {
		-0.0, 0.5,
		 0.5, 0.5,
		 0.5, -0.5,
		-0.5, -0.5
	};
	posbuf.Bind(Buffer::Target::Array);
	Buffer::Data(Buffer::Target::Array, 6, pos);
	position.Setup<Vec2f>().Enable();

	float texcoord[8] = {
		1.0, 1.0,
		0.0, 1.0,
		0.0, 0.0,
		1.0, 0.0
	};
	texcoordbuf.Bind(Buffer::Target::Array);
	Buffer::Data(Buffer::Target::Array, 6, texcoord);
	tex.Setup<Vec2f>().Enable();

	texHyena = UniformSampler(program, "texHyena");
	texPumba = UniformSampler(program, "texPumba");
	time = Uniform<float>(program, "time");

	Texture::Active(0);
	texHyena.SetValue(0);
	text.Bind(Texture::Target::_2D);
	Texture::Image2D(Texture::Target::_2D, images::LoadTexture("hyena.png"));
	
	Texture::Active(1);
	texHyena.SetValue(1);
	text_p.Bind(Texture::Target::_2D);
	Texture::Image2D(Texture::Target::_2D, images::LoadTexture("pumba.png"));

}


void TrySprite::Render(Context gl) {
	time.SetValue(clock());
	gl.DrawArrays(PrimitiveType::Triangles, 0, 3);
}


TrySprite::~TrySprite()
{
}
