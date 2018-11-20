#include "header.h"

void corJanela(float rJanela, float gJanela, float bJanela)
{
	printf("Escolha a cor: ");
	scanf("%f %f %f: ", &rJanela, &gJanela, &bJanela);
	glClearColor(rJanela, gJanela, bJanela, 1.0f);
}