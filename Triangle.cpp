#include "Triangle.h"

void Triangle::Load()
{
	GLfloat Verts[] = {800 / 2, 600, 0, /**/ 0, 0, 0, /**/  800, 0, 0}; // all the verts
	GLubyte Index[] = {0, 1, 2}; // index

	glGenBuffers (1 , &VBO); // create the buffers
	glGenBuffers (1 , &Indices);

	glBindBuffer (GL_ARRAY_BUFFER , VBO); // bind the buffers for verts
	glBufferData (GL_ARRAY_BUFFER , sizeof (Verts) , Verts  , GL_STATIC_DRAW);

	glBindBuffer (GL_ELEMENT_ARRAY_BUFFER , Indices); // indices
	glBufferData (GL_ELEMENT_ARRAY_BUFFER , sizeof (Index) , Index , GL_STATIC_DRAW);
} // Simple so far.

void Triangle::Draw()
{
	glPushMatrix();
	glLoadIdentity ();
	glTranslatef (0 , 0 , -10);
	glRotatef (ZRot , 0 , 0 , 1);

	glColor3f (1 , 0 , 0);

	glBindBuffer (GL_ARRAY_BUFFER , VBO);
	glBindBuffer (GL_ELEMENT_ARRAY_BUFFER , Indices);

	glEnableVertexAttribArray (0);
	glVertexAttribPointer (0 , 3 , GL_FLOAT , GL_FALSE , sizeof (float) * 3 , 0);

	glDrawElements (GL_TRIANGLES , 3 , GL_UNSIGNED_BYTE , 0);

	glPopMatrix();

/*	glPushMatrix();
	glTranslatef(0,0,0);
	glBegin(GL_TRIANGLES);
		glVertex2f(800/2,600);
		glVertex2f(0,0);
		glVertex2f(800,0);
	glEnd();
	glPopMatrix();*/  // immediate mode, use if vbo is not working (debugging yay)



	

}