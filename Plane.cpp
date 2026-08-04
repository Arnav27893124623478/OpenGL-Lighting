#include "Plane.h"

GLfloat PlaneVertices[] = {

	-1.0f, -1.0f, 1.0f,     1.0f, 1.0f, 1.0f,       0.0f, 0.0f,     0.0f, 1.0f, 0.0f, // Vertex 0
	1.0f, -1.0f, 1.0f,      1.0f, 1.0f, 1.0f,       1.0f, 0.0f,     0.0f, 1.0f, 0.0f, // Vertex 1
	-1.0f, -1.0f,-1.0f,     1.0f, 1.0f, 1.0f,       0.0f, 1.0f,     0.0f, 1.0f, 0.0f, // Vertex 2 
	1.0f, -1.0f, -1.0f,     1.0f, 1.0f, 1.0f,       1.0f, 1.0f,     0.0f, 1.0f, 0.0f, // Vertex 3


};

GLuint PlaneIndiecs[] =
{
	0, 1, 2,
	2, 1, 3
};


GLsizeiptr PlaneIndiecsSize = sizeof(PlaneIndiecs);
GLsizeiptr PlaneVerticeSize = sizeof(PlaneVertices);