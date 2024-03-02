#include<iostream>

using namespace std;

int main() {
  string palabra;

  cout << "ingrese la palabra" << endl;
  cin >> palabra;

  for(char &caracter : palabra) {
    if(caracter >= 'a' && caracter <= 'z') {
      caracter = caracter - ('a' - 'A');
    }
  }
  cout << "esto es una prueba de nano";
  cout << "la palabra en mayuscula es: " << palabra << endl;

  return 0;
}


#include<iostream>

using namespace std;

int main() {
  

  return 0;
}