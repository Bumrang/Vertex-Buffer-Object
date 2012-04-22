#include <iostream>
#include <GL/glew.h>
#include <glfw.h>

#ifndef TRIANGLE
#define TRIANGLE

class Triangle
{
public:
	GLuint Buffer;


	float ZRot;

	void Load();
	void Draw();
};

#endif