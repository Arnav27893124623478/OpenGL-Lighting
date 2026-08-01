#pragma once
#include <glad/glad.h>

class Texture {
public:
	GLuint ID;

	Texture(const char* imgPath);
	void Bind(GLenum TextureUnit);
	void Unbind();
	void Delete();

};
