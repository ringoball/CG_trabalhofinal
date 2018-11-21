#include "header.h"

void corJanela(float rJanela, float hJanela, float bJanela)
{
	printf("Escolha a cor da janela: ");
	scanf("%f %f %f: ", &rJanela, &hJanela, &bJanela);
	changeColorJanela(rJanela, hJanela, bJanela);
	glClearColor(rJanela, hJanela, bJanela, 1.0f);
}
