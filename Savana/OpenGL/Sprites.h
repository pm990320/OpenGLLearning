#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Sprites {
	class Player {
	private:
		
	public:
		GLuint vbo;
		GLuint vertexshader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
		GLuint shaderProgram = glCreateProgram();

		const char* vs_src = "player_v.vertexshader";
		const char* fs_src = "player_f.fragmentshader";

		const float width = 308.0f;
		const float height = 290.0f;

		GLfloat vertices[8];

		Player() {
			glGenBuffers(1, &vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glShaderSource(vertexshader, 1, &vs_src, NULL);
			glCompileShader(vertexshader);

			glShaderSource(fragmentshader, 1, &fs_src, NULL);
			glCompileShader(fragmentshader);

			glAttachShader(shaderProgram, vertexshader);
			glAttachShader(shaderProgram, fragmentshader);

			glBindFragDataLocation(shaderProgram, 0, "outColor");

			glLinkProgram(shaderProgram);

			glUseProgram(shaderProgram);


		}
		
	};

	extern Player player;

}