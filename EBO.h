#pragma once
#include <glad/glad.h>

class EBO {
public:
	GLuint ID;
	EBO(GLuint* Indeices, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();
};