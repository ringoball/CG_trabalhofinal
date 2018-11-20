#include"header.h"

void mudarEscalaObjeto()
{
	float x,y,z;
	printf("Coloque a nova escala: ");
	scanf("%f %f %f", &x,&y, &z);
	changeScale(x, y, z);
	printf("Alterado: ");
	glutDisplayFunc(display);
}
