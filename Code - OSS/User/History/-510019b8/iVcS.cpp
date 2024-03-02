#include<iostream>

using namespace std;

int main() {
  string palabra = "";
  string palabraAlreves = "";

  cout << "ingresa la palabra: ";
  cin >> palabra;

  for(int i = palabra.length() - 1; i >= 0; i--) {
    char caracter = palabra[i];
    palabraAlreves += caracter;
  }

  if(palabra == palabraAlreves) {
    cout << "la palabra " << palabra << " es palindroma ";
  } else {
    cout << "la palabra " << palabra << " no es palindroma"; 
  }

  return 0;
}
