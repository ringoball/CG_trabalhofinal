#include"header.h"
#include <iterator>
#include <iostream>

using namespace std;

void drawTriangleMesh(string fileName) {
	ifstream myReadFile;
	ofstream outFile;

	try {

		myReadFile.open(fileName);
	} catch (exception e) {
		cout << "Arquivo não existe" << endl;
	}

	string line;
	list<list<string> > verices;


	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {


			getline(myReadFile,line);
			if(line[0] == 'v' & line[1] == ' ') {
				int pos, tam;
				list<string> vertex;

				vertex.push_back("v");
				tam = 0;
				pos = line.find(" ", pos+1);

				tam = pos+1;
				pos = line.find(" ", pos+1);
				vertex.push_back((line.substr(tam, pos-tam)));  // imprime "teste2"

				tam = pos+1;
				pos = line.find(" ", pos+1);
				vertex.push_back((line.substr(tam, pos-tam)));  // imprime "teste2"

				tam = pos+1;
				pos = line.find(" ", pos+1);
				vertex.push_back((line.substr(tam, pos-tam)));

				verices.push_back(vertex);
			}


		}
	}
	outFile.open("triangleMeshObject.obj");
	int i =0;
	if (outFile.is_open()) {
	 	for (list<string> n : verices) {
			if((i%9)==0){
				glBegin(GL_TRIANGLES);
	       glColor3f(0.1, 0.2, 0.3);
			}
			float x[4];
			for(string x : n){
				//cout<<x<<endl;
				outFile << x << " ";
				x[(i%3)-1];
				i++;

			}
			if((i%3)==0){
				glVertex3f(float(x[1]), float(x[2]), float(x[3]));
				cout << x[1], x[2], x[3];
				cout << "vaiii";
			}
			if((i%9)==0){
				glEnd();
			}
			outFile << endl;
		}

	}

	cout <<verices.front().front();

	outFile.close();
	myReadFile.close();

}
