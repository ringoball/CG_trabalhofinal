#include "header.h"

void drawWire(int shape){

	switch(shape){

		case TEAPOT:
			glutWireTeapot(50.0f);
			break;

		case CUBE:
			glutWireCube(50.0f);
			break;

		case SPHERE:
			glutWireSphere(50.0, 50.0, 50.0);
			break;

		case CONE:
			glutWireCone(50.0, 50.0, 50.0, 50.0);
			break;

		case TORUS:
			glutWireTorus(10.0, 50.0, 50.0, 50.0);
			break;

		case ICOSAHEDRON:
			glScalef(50.0, 50.0, 50.0);
			glutWireIcosahedron();
			break;

		case OCTAHEDRON:
			glScalef(50.0, 50.0, 50.0);
			glutWireOctahedron();
			break;

		case TETRAHEDRON:
			glScalef(50.0, 50.0, 50.0);
			glutWireTetrahedron();
			break;

		case DODECAHEDRON:
			glScalef(50.0, 50.0, 50.0);
			glutWireDodecahedron();
			break;

		case MESH:
			drawTriangleMesh("miniCooper.obj");
			break;
		default:
			break;
	}
}
