#include <iostream>
#include "cliente.h"
#include "Productos.h"
#include "Fecha.h"

#define NUMEROMAXCLIENTES 5
#define NUMEROMAXPRODUCTOS 5
#define NUMEROMAXVENTAS 5

using namespace std;

int mostrarMenu() {
    int opcion = 0;

    cout << "seleccione la accion a realizar: " << endl;
    cout << "1. Agregar clientes" << endl;
    cout << "2. Agregar productos" << endl;
    cout << "3. Registrar ventas" << endl;
    cout << "4. Mostrar lista de cientes" << endl;
    cout << "5. Mostrar lista productos" << endl;
    cout << "6. Mostrar lista clientes" << endl;
    cout << "7. Ver factura" << endl;
    cout << "8. Salir" << endl;

    cin >> opcion;
    return opcion;
}


int main()
{
    int contadorCliente = 0;
    int contador
    
    Cliente* miCliente = new Cliente(1, "prueba", "prueba");  


    cout << "Hello world!" << endl;
    return 0;
}
