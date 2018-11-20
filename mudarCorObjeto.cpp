#include"header.h"

void mudarCorObjeto()
{
  float i,j,k;
	printf("Escolha a cor no formato R[0-1] G[0-1] B[0-1]:");
	scanf("%f %f %f: ", &i, &j, &k);
	changeColor(i,j,k);
	glutDisplayFunc(display);
	printf("Alterado");
}
