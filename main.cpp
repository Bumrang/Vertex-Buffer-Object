#include <iostream>
#include <GL\glew.h>
#include <glfw.h>
#include "Triangle.h"

int Width = 800;
int Height = 600;

int main()
{	
	if (!glfwInit()) // init
   {
      std::cout << "GLFW failed to initialize!\n";
      return 1;
   }
   glfwOpenWindow(Width,Height,0,0,0,0,0,0,GLFW_WINDOW); // open the window 
   glfwSetWindowTitle("VBO"); // title
   glViewport(0,0,Width, Height); // stuff
   glMatrixMode(GL_PROJECTION); // matrix mode
   glLoadIdentity(); // stuff
   glOrtho(0,Width,0,Height,0,1); // stuff
   glMatrixMode(GL_MODELVIEW); // matrix mode
   glClearColor(0,0,0,1); // back color

   glewInit();

   Triangle Tri;

   Tri.Load();

	while (true)
	{

		if (!glfwGetWindowParam(GLFW_OPENED)) // Closed the window? That's pretty cool.
		 {
           std::cout << "Window was closed! Exiting...\n";
           break; 
		 }

		Tri.ZRot += 0.5;

		// Updates above clear.
		glClear(GL_COLOR_BUFFER_BIT);
		// Draws under clear.
	
		Tri.Draw();

		glfwSwapBuffers();
	}
}