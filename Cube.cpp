#include "Cube.h"



GLfloat CubeVertices[] =
{ //   X     Y      Z  /    R     G     B       /TexCoord/          / Normal's/

	// Front Face
	-1.0f,  1.0f, 1.0f,     1.0f, 1.0f, 1.0f,     0.0f, 1.0f,      0.0f, 0.0f, 1.0f, // Vertex 0 
	 1.0f,  1.0f, 1.0f,     1.0f, 1.0f, 1.0f,     1.0f, 1.0f,      0.0f, 0.0f, 1.0f, // Vertex 1
	 1.0f, -1.0f, 1.0f,     1.0f, 1.0f, 1.0f,     1.0f, 0.0f,      0.0f, 0.0f, 1.0f, // Vertex 2
	-1.0f, -1.0f, 1.0f,     1.0f, 1.0f, 1.0f,     0.0f, 0.0f,      0.0f, 0.0f, 1.0f, // Vertex 3

	// Left Face
	-1.0f,  1.0f, 1.0f,     1.0f, 1.0f, 1.0f,     1.0f, 1.0f,     -1.0f, 0.0f, 0.0f, // Vertex 4
	-1.0f, -1.0f, 1.0f,     1.0f, 1.0f, 1.0f,     1.0f, 0.0f,     -1.0f, 0.0f, 0.0f, // Vertex 5
	-1.0f,  1.0f,-1.0f,     1.0f, 1.0f, 1.0f,     0.0f, 1.0f,     -1.0f, 0.0f, 0.0f, // Veretx 6
	-1.0f, -1.0f,-1.0f,     1.0f, 1.0f, 1.0f,     0.0f, 0.0f,     -1.0f, 0.0f, 0.0f, // Vertex 7

	// Back Face 
	-1.0f,  1.0f, -1.0f,     1.0f, 1.0f, 1.0f,     1.0f, 1.0f,     0.0f, 0.0f, -1.0f,// Vertex 8
	-1.0f, -1.0f, -1.0f,     1.0f, 1.0f, 1.0f,     1.0f, 0.0f,     0.0f, 0.0f, -1.0f,// Vertex 9
	 1.0f,  1.0f, -1.0f,     1.0f, 1.0f, 1.0f,     0.0f, 1.0f,     0.0f, 0.0f, -1.0f,// Veretx 10
	 1.0f, -1.0f, -1.0f,     1.0f, 1.0f, 1.0f,     0.0f, 0.0f,     0.0f, 0.0f, -1.0f,// Vertex 11

	 // Right Side
	  1.0f,  1.0f,  1.0f,     1.0f, 1.0f, 1.0f,     0.0f, 1.0f,     1.0f, 0.0f,  0.0f,// Vertex 12
	  1.0f, -1.0f,  1.0f,     1.0f, 1.0f, 1.0f,     0.0f, 0.0f,     1.0f, 0.0f,  0.0f,// Vertex 13
	  1.0f,  1.0f, -1.0f,     1.0f, 1.0f, 1.0f,     1.0f, 1.0f,     1.0f, 0.0f,  0.0f,// Vertex 14
	  1.0f, -1.0f, -1.0f,     1.0f, 1.0f, 1.0f,     1.0f, 0.0f,     1.0f, 0.0f,  0.0f,// Vertex 15

	  // Top Side
	  -1.0f, 1.0f, 1.0f,      1.0f, 1.0f,  1.0f,     0.0f, 0.0f,     0.0f, 1.0f, 0.0f,// Vertex 16
	   1.0f, 1.0f, 1.0f,      1.0f, 1.0f,  1.0f,     1.0f, 0.0f,     0.0f, 1.0f, 0.0f,// Vertex 17
	  -1.0f, 1.0f,-1.0f,      1.0f, 1.0f,  1.0f,     0.0f, 1.0f,     0.0f, 1.0f, 0.0f,// Vertex 18
	   1.0f, 1.0f,-1.0f,      1.0f, 1.0f,  1.0f,     1.0f, 1.0f,     0.0f, 1.0f, 0.0f,// Vertex 19

	   // Down Side
	   -1.0f, -1.0f, 1.0f,     1.0f, 1.0f, 1.0f,      0.0f, 0.0f,     0.0f, -1.0f, 0.0f,// Vertex 20
		1.0f, -1.0f, 1.0f,     1.0f, 1.0f, 1.0f,      1.0f, 0.0f,     0.0f, -1.0f, 0.0f,// Vertex 21
	   -1.0f, -1.0f,-1.0f,     1.0f, 1.0f, 1.0f,      0.0f, 1.0f,     0.0f, -1.0f, 0.0f,// Vertex 22
		1.0f, -1.0f, -1.0f,    1.0f, 1.0f, 1.0f,      1.0f, 1.0f,     0.0f, -1.0f, 0.0f// Vertex 23

};

GLuint CubeIndiecs[] =
{
	// Front
	0, 1, 2,
	0, 2, 3,

	// Left
	4, 5, 6,
	5, 7, 6,

	// Back
	8, 9, 10,
	9, 11, 10,

	// Right
	12, 13, 14,
	13, 15, 14,

	// Top
	16, 17, 18,
	17, 19, 18,

	// Bottom
	20, 21, 22,
	21, 23, 22
};
GLsizeiptr CubeVerticesSize = sizeof(CubeVertices);
GLsizeiptr CubeIndiecsSize = sizeof(CubeIndiecs);

