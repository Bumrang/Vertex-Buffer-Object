#include <iostream>  // Mainly for 
#include <fstream>   // loading
#include <string>    // the
#include <vector>    // shader

#include <GL/glew.h>
#include <glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#ifndef TRIANGLE
#define TRIANGLE

class Triangle
{
public:
	GLuint Buffer;
	GLuint Indices;
	GLuint programID;

	/*GLuint MatrixID;
	glm::mat4 Projection;
	glm::mat4 View;
	glm::mat4 Model;
	glm::mat4 MVP;*/

	std::vector <glm::vec3> Verts;

	float ZRot;

	Triangle();
	void Load();
	void Draw();
	void LoadMatrix();
	GLuint LoadShader(const char * VertFilepath , const char * FragFilepath);
};

#endif