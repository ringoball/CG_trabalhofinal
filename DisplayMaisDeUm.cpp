#include "header.h"

void display()
{
	// limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(R,G,B);

	glPushMatrix();

	        // cria matrizes de transforma��o
	glRotatef ((GLfloat) rotationX, 1.0, 0.0, 0.0);
	glRotatef ((GLfloat) rotationY, 0.0, 1.0, 0.0);
	glRotatef ((GLfloat) rotationZ, 0.0, 0.0, 1.0);

	glTranslatef ((GLfloat) translationX, 0.0, 0.0);
	glTranslatef (0.0, (GLfloat) translationY, 0.0);

	glScalef(scaleX, scaleY, scaleZ);

	// desenha o objeto
	if(drawFormat)
		drawWire(shape);
	else{
		draw(shape);
		}
	glPopMatrix();

	glutSwapBuffers();
}