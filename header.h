#include<iostream>
#include<fstream>
#include<list>
#include <algorithm>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include <string>

#define MAX_NOME 30
#define MESH 0
#define TEAPOT 1
#define CUBE 2
#define SPHERE 3
#define CONE 4
#define TORUS 5
#define ICOSAHEDRON 6
#define OCTAHEDRON 7
#define TETRAHEDRON 8
#define DODECAHEDRON 9

// declara��o de vari�veis globais
static int translationX = 0, translationY = 0, rotationX = 0, rotationY = 0, rotationZ = 0;
static GLfloat angle, f_aspect;
static float xj = 1, yj = 1, zj = 1;

using namespace std;

void draw(int);
void display();
void changeColor(float, float, float);
void changeScale(float, float, float);
void init();
void visualization();
void reshape();
void mouse();
void keyboard(unsigned char, int, int);
void specialkey();
void escala();
void mudarObjetoPosicao();
void mudarEscalaObjeto();
void mudarCorObjeto();
void corJanela(float, float, float);
void drawTriangleMesh(string);
void fileReader(string);
void visualizacao();//(GLdouble, GLdouble, GLdouble,GLdouble, GLdouble, GLdouble,GLdouble, GLdouble, GLdouble);
