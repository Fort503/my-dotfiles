#include <iostream>

using namespace std;

int main()
{
    string cadena;
    string *punteroDeCadena;

    cout << "ingrese una cadena de texto" << endl;
    cin >> cadena;

    punteroDeCadena = &cadena;

    cout << "-----------------------------------------------------" << endl;
    cout << "la cadena esta en la direccion: " << punteroDeCadena << endl;
    cout << "la cadena escrita es: " << *punteroDeCadena << endl;

    return 0;
}
