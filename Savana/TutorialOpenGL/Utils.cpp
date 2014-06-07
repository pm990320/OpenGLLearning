#include "Utils.h"

using namespace Utilities;

std::string ShaderUtils::get_file_contents(const char* filename) {
	std::ifstream in{ filename, std::ios::in };
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	in.close();
	throw (errno);
}

GLuint ShaderUtils::loadShaderFromFile(const char* path, bool vertex) {
	GLint shaderID;
	if (vertex) { shaderID = glCreateShader(GL_VERTEX_SHADER); }
	else { shaderID = glCreateShader(GL_FRAGMENT_SHADER); }

	std::string str = get_file_contents(path);

	const GLchar* source = str.c_str();
	glShaderSource(shaderID, 1, &source, NULL);
	glCompileShader(shaderID);

	GLint compileStatus;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus != 1) {
		std::cout << "The shader did not compile" << std::endl;

		GLint infoLogLength;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

		char* infoLog = new char[infoLogLength+1];
		glGetShaderInfoLog(shaderID, infoLogLength+1, NULL, infoLog);

		std::cout << infoLog << std::endl;
		delete infoLog;
		return 0;
	}

	return shaderID;
}

GLuint ShaderUtils::createProgramFromShaders(GLuint& vs, GLuint& fs) 
/* Does not bind frag data or link the program, these are to be done!!
 */
{
	GLuint program = glCreateProgram();
	glAttachShader(program, vs);
	glAttachShader(program, fs);

	return program;
}

bool TextureUtils::IL_INIT = false;

GLuint TextureUtils::loadTexture(char* path) {
	if (!IL_INIT) {
		ilInit();
		ilEnable(IL_ORIGIN_SET);
		ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
		ilutRenderer(ILUT_OPENGL);
		ilutEnable(ILUT_OPENGL_CONV);
		IL_INIT = true;
	}

	return ilutGLLoadImage(path);
}

template<typename T>
void* BUFFER_OFFSET(int x, T type){
	return (void*)(x*sizeof(T));
}
