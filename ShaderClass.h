#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string Get_File_contents(const char* filename);

class Shader {
public:
	GLuint ID;
	Shader(const char* VertexFile, const char* FragmentFile);

	void Active();
	void Delete();
};