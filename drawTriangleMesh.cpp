#include"header.h"

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
	if (outFile.is_open()) {
	 	for (list<string> n : verices) {
			for(string x : n){
				cout<<x<<endl;
				outFile << x << " ";
			}
			outFile << endl;
		}
	}

	cout <<verices.front().front();

	outFile.close();
	myReadFile.close();
	

}