#ifndef SHUTILS
#define SHUTILS

#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <IL/il.h>
#include <IL/ilut.h>

namespace Utilities {

	class ShaderUtils
	{
	private:
		static std::string get_file_contents(const char* filename);
	public:
		static GLuint loadShaderFromFile(const char* path, bool vertex);
		static GLuint createProgramFromShaders(GLuint& vs, GLuint& fs);
	};


	class TextureUtils {
	private:
		static bool IL_INIT;
	public:
		static GLuint loadTexture(char* path);
	};

	extern void* BUFFER_OFFSET(int x, GLuint type);

}
#endif