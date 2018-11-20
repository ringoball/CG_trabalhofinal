#include "header.h"

void visualizacao()//(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ, GLdouble centerX,  GLdouble centerY,  GLdouble centerZ,  GLdouble upX,
//GLdouble upY, GLdouble upZ)
{
		glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-80.0,80.0,-80.0,80.0,-80.0,80.0);
		gluLookAt(120.0,120.0,120.0,0.0,0.0,0.0,0.0,-120.0,0.0);


    // define the viewing transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}		//gluLookAt(0, 80, 200, 0, 0, 0, 0, 1, 0);
/*		switch (opt){
		case '!' :
			break;
		case '@':
			gluLookAt(-1.0,1.0,1.0,0.0,0.0,0.0,0.0,-1.0,0.0);
			break;
		case '#':
			gluLookAt(1.0,-1.0,1.0,0.0,0.0,0.0,0.0,-1.0,0.0);
			break;
		case '$':
			gluLookAt(1.0,1.0,-1.0,0.0,0.0,0.0,0.0,-1.0,0.0);
			break;
		case '%':
			gluLookAt(1.0,1.0,1.0,0.0,0.0,0.0,0.0,-1.0,0.0);
			break;
		case '"':
			gluLookAt(-1.0,-1.0,1.0,0.0,0.0,0.0,0.0,-1.0,0.0);
			break;
		case '&':
			gluLookAt(1.0,-1.0,-1.0,0.0,0.0,0.0,0.0,-1.0,0.0);
			break;
		case 'a':
			gluLookAt(-1.0,-1.0,-1.0,0.0,0.0,0.0,0.0,-1.0,0.0);
			break;
		}
}*/
