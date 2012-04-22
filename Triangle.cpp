#include "Triangle.h"

void Triangle::Load()
{
	ZRot = 0;

	const GLfloat Verts[] = {
		800 / 2, 600 , 0,
		0 , 0 , 0,
		800 , 0 , 0};

	glBindBuffer (GL_ARRAY_BUFFER , Buffer);
	glBufferData (GL_ARRAY_BUFFER , sizeof (Verts) , Verts , GL_STATIC_DRAW);
} // Simple so far.

void Triangle::Draw()
{
	glPushMatrix();
	glEnableVertexAttribArray (0);

		glBindBuffer (GL_ARRAY_BUFFER , Buffer);

		glVertexAttribPointer (
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			(void*)0
			);

		glDrawArrays (GL_TRIANGLES , 0 , 3);

	glDisableVertexAttribArray (0);
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