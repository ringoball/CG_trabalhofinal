#include "header.h"


void updateMenu(){
    system("clear");
    cout << "-----------------Menu Usuario-------------"<<endl;
    cout << endl;
    cout << "Mudança de Objetos: Objeto,numero"<<endl;
    cout << "---------------------------------"<<endl;
    cout << "Seu Objeto,0"<<endl;
    cout << "TEAPOT,1"<<endl;
    cout << "CUBE,2"<<endl;
    cout << "SPHERE,3"<<endl;
    cout << "CONE,4"<<endl;
    cout << "TORUS,5"<<endl;
    cout << "ICOSAHEDRON,6"<<endl;
    cout << "OCTAHEDRON,7"<<endl;
    cout << "TETRAHEDRON,8"<<endl;
    cout << "DODECAHEDRON,9"<<endl;
    cout << endl;
	cout << "_Funcionalidades: Função, Tecla de controle_"<<endl;
    cout << "---------------------------------"<<endl;
    cout << "____Funções de Zoom____________"<<endl;
    cout << endl;
	cout << "1. Aproximar Objeto, Botão esquerdo do mouse  "<<endl;
	cout << "2. Distanciar Objeto, Botão direito do mouse  "<<endl<<endl;
    cout << "____Funções de rotação____________"<<endl;
    cout << endl;
	cout << "3. Rotacionar no eixo X (Anti Horário), Tecla x "<<endl;
    cout << "4. Rotacionar no eixo Y (Anti Horário), Tecla y "<<endl;
    cout << "5. Rotacionar no eixo Z (Anti Horário), Tecla z "<<endl;
	cout << "6. Rotacionar no eixo X (Horário), Tecla X "<<endl;
    cout << "7. Rotacionar no eixo Y (Horário), Tecla Y "<<endl;
    cout << "8. Rotacionar no eixo Z (Horário), Tecla Z "<<endl<<endl;
    cout << "____Funções de transformação____________"<<endl;
    cout << endl;
    cout << "9. Mudança de cor, Tecla m"<<endl;
    cout << "10. Mudança de escala, Tecla s"<<endl;
    cout << "11. Mudança de Cor de Fundo, tecla c"<<endl;
    cout << "12. Para mudar de sólido para arame ou arame para sólido aperte = " << endl;
    cout << "____Funções de perspectiva______________"
    cout << "13. Para mudar de perspectiva use os seguintes caracteres especiais: !, @, #, $, %, &, *, " <<endl;
    cout << "14. Para volar a perspectiva inicial use / " << endl;
}
