#include"header.h"
using namespace std;

void fileReader(string fileName) {
  ifstream myReadFile;

  try {

  myReadFile.open(fileName);
  } catch (exception e) {
    cout << "Arquivo não existe" << endl;
  }

 string line;
 list<list<double>> verices;


 if (myReadFile.is_open()) {
 while (!myReadFile.eof()) {


    getline(myReadFile,line);
    if(line[0] == 'v' & line[1] == ' '){
      int pos, tam;
      list<double> vertex;

      pos = line.find(" ", 0);
      cout << line.substr(0, pos) << endl;         // imprime "teste"

      tam = pos+1;
      pos = line.find(" ", pos+1);
      cout << line.substr(tam, pos-tam) << endl;   // imprime "teste1"

      tam = pos+1;
      pos = line.find(" ", pos+1);
      cout<<line.substr(tam, pos-tam);
      vertex.push_back(stod(line.substr(tam, pos-tam)));   // imprime "teste2"

      tam = pos+1;
      pos = line.find(" ", pos+1);
      vertex.push_back(stod(line.substr(tam, pos-tam)));  // imprime "teste2"

      tam = pos+1;
      pos = line.find(" ", pos+1);
      vertex.push_back(stod(line.substr(tam, pos-tam)));

      verices.push_back(vertex);
    }


 }
}
//  for (list n : verices) {
//      cout << n << '\n';
//         for(double x : vertices[n]){
//           cout << x << endl;
//         }
// }

cout << verices.front().front();

myReadFile.close();
}