// Um programa OpenGL que exemplifica a visualiza��o de objetos 3D com a inser��o de uma fonte de luz.
// Este c�digo est� baseado nos c�digos:
// ==> "Iluminacao.c" de Isabel H. Manssour (https://www.inf.pucrs.br/~manssour/OpenGL/Iluminacao.html).
// ==> "Interacao.c" de Isabel H. Manssour (https://www.inf.pucrs.br/~manssour/OpenGL/Eventos.html).
// ==> "braco.h" de Agostinho de Medeiros Brito J�nior (https://www.dca.ufrn.br/~ambj/opengl/transformacoes.html).

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <string.h>
#include "header.h"

bool changeObject=false;
float R = 1, G = 0, B = 0;
float scaleX = 1, scaleY = 1, scaleZ = 1;
int shape = 1;
int it = 0;
int nObject = 1;
bool drawFormat = false;
double eyeX = 0, eyeY = 80, eyeZ = 200, centerX = 0, centerY = 0, centerZ = 0, upX = 0, upY = 1, upZ = 0;
//0, 80, 200, 0, 0, 0, 0, 1, 0

void changePerspectiva(double i, double j, double k, double l, double m, double n,double o, double p, double q)
{
	eyeX = i;
	eyeY = j;
	eyeZ = k;
	centerX = l;
	centerY = m;
	centerZ = n;
	upX = o;
 	upY = p;
	upZ = q;
}

void changeColor(float i, float j, float k) {
	R = i;
	G = j;
	B = k;
}

void changeScale(float i, float j, float k) {
	scaleX = i;
	scaleY = j;
	scaleZ = k;
}

// fun��o callback chamada para fazer o desenho
void display()
{
	// limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(R,G,B);

	for(int i=0;i<nObject;i++) {

		glPushMatrix();

		// cria matrizes de transforma��o
		glRotatef ((GLfloat) rotationX[i], 1.0, 0.0, 0.0);
		glRotatef ((GLfloat) rotationY[i], 0.0, 1.0, 0.0);
		glRotatef ((GLfloat) rotationZ[i], 0.0, 0.0, 1.0);

		glTranslatef ((GLfloat) i*100, 0.0, 0.0);
		glTranslatef (0.0, (GLfloat) translationY[i], 0.0);

		glScalef(scaleX, scaleY, scaleZ);

		// desenha o objeto
		if(drawFormat)
			drawWire(shape);
		else
			draw(shape);
		glPopMatrix();
	}

	glutSwapBuffers();
}



// inicializa par�metros de rendering
void init(void)
{
	GLfloat luz_ambiente[4]={0.2, 0.2, 0.2, 1.0};
	GLfloat luz_difusa[4]={0.7, 0.7, 0.7, 1.0};	 // "cor"
	GLfloat luz_especular[4]={1.0, 1.0, 1.0, 1.0};    // "brilho"
	GLfloat posicao_luz[4]={0.0, 50.0, 50.0, 1.0};

	// capacidade de brilho do material
	GLfloat especularidade[4]={1.0, 1.0, 1.0, 1.0};
	GLint espec_material = 60;

 	// especifica que a cor de fundo da janela ser� preta
        glClearColor(xj, yj, zj, 1.0f);

	// habilita o modelo de coloriza��o de Gouraud
	glShadeModel(GL_SMOOTH);

	// define a reflet�ncia do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);

	// define a concentra��o do brilho
	glMateriali(GL_FRONT,GL_SHININESS, espec_material);

	// ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luz_ambiente);

	// define os par�metros da luz de n�mero 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luz_especular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicao_luz );

	// habilita a defini��o da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);

	// habilita o uso de ilumina��o
	glEnable(GL_LIGHTING);

	// habilita a luz de n�mero 0
	glEnable(GL_LIGHT0);

	// habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

	// habilita normaliza��o dos vetores ap�s as transforma��es
	glEnable(GL_RESCALE_NORMAL);

    	angle=45;

}

/*void visualization(){
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(angle, f_aspect, 0.4, 500);
gluLookAt(120.0,120.0,120.0,0.0,0.0,0.0,0.0,-120.0,0.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}*/

// fun��o usada para especificar o volume de visualiza��o
void visualization(void)
{
	// especifica sistema de coordenadas de proje��o
	glMatrixMode(GL_PROJECTION);

	// inicializa sistema de coordenadas de proje��o
	glLoadIdentity();

	// especifica a proje��o perspectiva
    	gluPerspective(angle, f_aspect, 0.4, 500);

	// especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);

	// inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// especifica posi��o do observador e do alvo
			//gluLookAt(120.0,120.0,120.0,0.0,0.0,0.0,0.0,-120.0,0.0);
 //eyeX eyeY eyeZ centerX centerY centerZ upX upY upZ
// eyeX eyeY eyeZ centerX centerY centerZ upX upY upZ
			gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
			//gluLookAt(0, 80, 200, 0, 0, 0, 0, 1, 0);

}

// fun��o callback chamada quando o tamanho da janela � alterado
void reshape(GLsizei w, GLsizei h)
{
	// para previnir uma divis�o por zero
	if ( h == 0 ) h = 1;

	// especifica o tamanho da viewport
        glViewport(0, 0, w, h);

	// calcula a corre��o de aspecto
	f_aspect = (GLfloat)w/(GLfloat)h;

	// especifica volume da visualiza��o
	visualization();

	// exibe objetos na tela
	glutPostRedisplay();

}

// fun��o callback chamada para gerenciar eventos do mouse
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}

	// especifica volume da visualiza��o
	visualization();

	// exibe objetos na tela
	glutPostRedisplay();
}

// teclado
void keyboard (unsigned char key, int x, int y){


	switch (key) {

		// rota��o em torno do eixo X
		
		case'-':
			changeObject = changeObject ? false:true;

		case 'x':
			rotationX[it] = (rotationX[it] + 5) % 360;
			break;

		case 'X':
			rotationX[it] = (rotationX[it] - 5) % 360;
			break;

		// rota��o em torno do eixo Y
		case 'y':
			rotationY[it] = (rotationY[it] + 5) % 360;
			break;

		case 'Y':
			rotationY[it] = (rotationY[it] - 5) % 360;
			break;

		// rota��o em torno do eixo Z
		case 'z':
			rotationZ[it] = (rotationZ[it] + 5) % 360;
			break;

		case 'Z':
			rotationZ[it] = (rotationZ[it] - 5) % 360;
			break;

		case ',':
			it > 0 ? it-- : it = nObject - 1;
			break;

		case '.':
			it < nObject-1 ? it++ : it = 0;
			break;

		case '{':
			nObject--;
			break;

		case '}':
			nObject++;
			break;



		// mudan�a de objetos
		case '0':
			shape = MESH;
			break;

		case '1':
			shape = TEAPOT;
			break;

		case '2':
			shape = CUBE;
			break;

		case '3':
			shape = SPHERE;
			break;

		case '4':
			shape = CONE;
			break;

		case '5':
			shape = TORUS;
			break;

		case '6':
			shape = ICOSAHEDRON;
			break;

		case '7':
			shape = OCTAHEDRON;
			break;

		case '8':
			shape = TETRAHEDRON;
			break;

		case '9':
			shape = DODECAHEDRON;
			break;

		case 'm' :
			mudarCorObjeto();
			printf("Alterado\n");
			system("clear");
			updateMenu();
			break;
		case 's':
			mudarEscalaObjeto();
			break;
		case '!':
			mudarPerspectivaObjeto(120, 120, 120, 40, 10, 30, -120, 1,  0);
			break;
		case '@':
			mudarPerspectivaObjeto (-120.0, 120.0, 120.0, 60.0, 20.0, 10.0, 0.0, -120.0, 0.0);
			break;
		case '#':
			mudarPerspectivaObjeto(140.0, -150.0, 130.0, 10.0, 10.0, 10.0, 0.0, -120.0, 0.0);
			break;
		case '$':
			mudarPerspectivaObjeto(150.0, 110.0, -100.0, 30.0, 0.0, 20.0, 0.0, 120.0, 0.0);
			break;
		case '%':
			mudarPerspectivaObjeto(110.0, 150.0, 120.0, 0.0, 40.0, 50.0, 0.0, -120.0, 0.0);
			break;
		case '"':
			mudarPerspectivaObjeto(-110.0, -130.0, 120.0, 20.0, 20.0, 0.0, 0.0, -120.0, 0.0);
			break;
		case '&':
			mudarPerspectivaObjeto(180.0, -150.0, -90.0, 70.0, 100.0, 40.0, 0.0, 120.0, 0.0);
			break;
		case '*':
			mudarPerspectivaObjeto(-190.0, -130.0, -110.0, 20.0, 30.0, 10.0, 80.0, 120.0, 90.0);
			break;
		case '/':
			mudarPerspectivaObjeto(0.0, 80.0, 200.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			break;
		case '=':
			drawFormat = drawFormat ? false : true;
			break;

		// case 'p':
		// 	perspectiva();
		// 	break;

		// fecha a janela
		case 27:
			exit(0);
			break;

		default:
			break;
	}

	// especifica volume da visualiza��o
	visualization();

	// exibe objetos na tela
	glutPostRedisplay();
}


// teclas especiais
void specialkey (int key, int x, int y){

	switch (key) {
		// transla��o na dire��o do eixo X
		case GLUT_KEY_RIGHT:
			translationX[it] = (translationX[it] + 5);
			break;

		case GLUT_KEY_LEFT:
			translationX[it] = (translationX[it] - 5);
			break;

		// rota��o na dire��o do eixo Y
		case GLUT_KEY_UP:
			translationY[it] = (translationY[it] + 5);
			break;

		case GLUT_KEY_DOWN:
			translationY[it] = (translationY[it] - 5);
			break;

		default:
			break;
	}

	// especifica volume da visualiza��o
	visualization();

	// exibe objetos na tela
	glutPostRedisplay();

}


// programa principal
int main(int argc, char** argv)
{
	char sair;
//	ler();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Visualizacao 3D");
	init();
	updateMenu();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkey);
	glutMainLoop();


	return 0;
}
