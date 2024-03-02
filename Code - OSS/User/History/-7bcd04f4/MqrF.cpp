#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct {
    int codigo;
    char nombre[50];
    char numeroDeTelefono[50];
} tclientes;

void continuar() {
    printf("\nPresione una tecla para continuar\n\n");
    getchar();
}

void crear() {
    FILE *arch;
    arch = fopen("clientes.dat", "wb");
    if (arch == NULL)
        exit(1);
    fclose(arch);
    continuar();
}

void cargar() {
    FILE *arch;
    arch = fopen("clientes.dat", "ab");
    if (arch == NULL)
        exit(1);

    tclientes cliente;

    printf("Ingrese el codigo del cliente:");
    scanf("%i", &cliente.codigo);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Ingrese el nombre del clientes:");
    fgets(cliente.nombre, sizeof(cliente.nombre), stdin);
    cliente.nombre[strcspn(cliente.nombre, "\n")] = '\0';

    printf("Ingrese el numero de telefono del clientes:");
    fgets(cliente.numeroDeTelefono, sizeof(cliente.numeroDeTelefono), stdin);
    cliente.numeroDeTelefono[strcspn(cliente.numeroDeTelefono, "\n")] = '\0';

    fwrite(&cliente, sizeof(tclientes), 1, arch);
    fclose(arch);

    continuar();
}

void listado() {
    FILE *arch;
    arch = fopen("clientes.dat", "rb");
    if (arch == NULL)
        exit(1);

    tclientes cliente;

    fread(&cliente, sizeof(tclientes), 1, arch);
    while (!feof(arch)) {
        printf("\n%i %s %s", cliente.codigo, cliente.nombre, cliente.numeroDeTelefono);
        fread(&cliente, sizeof(tclientes), 1, arch);
    }

    fclose(arch);
    continuar();
}

void consulta() {
    FILE *arch;
    arch = fopen("clientes.dat", "rb");
    if (arch == NULL)
        exit(1);

    printf("Ingrese el codigo del cliente a consultar:");
    int cod;
    scanf("%i", &cod);

    tclientes cliente;
    int existe = 0;

    fread(&cliente, sizeof(tclientes), 1, arch);
    while (!feof(arch)) {
        if (cod == cliente.codigo) {
            printf("%i %s %s\n", cliente.codigo, cliente.nombre, cliente.numeroDeTelefono);
            existe = 1;
            break;
        }
        fread(&cliente, sizeof(tclientes), 1, arch);
    }

    if (existe == 0)
        printf("No existe un cliente con dicho codigo\n");

    fclose(arch);
    continuar();
}

void modificacion() {
    FILE *arch;
    arch = fopen("clientes.dat", "r+b");
    if (arch == NULL)
        exit(1);

    printf("Ingrese el codigo del cliente a modificar:");
    int cod;
    scanf("%i", &cod);

    tclientes cliente;
    int existe = 0;

    fread(&cliente, sizeof(tclientes), 1, arch);
    while (!feof(arch)) {
        if (cod == cliente.codigo) {
            printf("%i %s %s\n", cliente.codigo, cliente.nombre, cliente.numeroDeTelefono);
            printf("Ingrese nuevo numero de telefono:");
            scanf("%s", cliente.numeroDeTelefono);

            int pos = ftell(arch) - sizeof(tclientes);
            fseek(arch, pos, SEEK_SET);
            fwrite(&cliente, sizeof(tclientes), 1, arch);

            printf("Se modifico el numero de telefono para dicho cliente\n");
            existe = 1;
            break;
        }
        fread(&cliente, sizeof(tclientes), 1, arch);
    }

    if (existe == 0)
        printf("No existe un cliente con dicho codigo\n");

    fclose(arch);
    continuar();
}

int main() {
    int opcion;
    do {
        printf("1 - Crear un archivo binario llamado \"clientes.dat\"\n");
        printf("2 - Carga de registros de tipo tproducto\n");
        printf("3 - Listado completo de clientes.\n");
        printf("4 - Consulta de un cliente por su codigo.\n");
        printf("5 - Modificacion del numero de telefono de un cliente. \n");
        printf("6 - Finalizar\n\n");
        printf("Ingrese su opcion:");
        scanf("%i", &opcion);

        switch (opcion) {
            case 1:
                crear();
                break;
            case 2:
                cargar();
                break;
            case 3:
                listado();
                break;
            case 4:
                consulta();
                break;
            case 5:
                modificacion();
                break;
        }
    } while (opcion != 6);

    return 0;
}



//-----------------------

void llamadasFrame::OnbotonMostrarClick(wxCommandEvent& event)
{
    typedef struct {
        wxString codigo;
        wxString nombre;
        wxString numeroDeTelefono;
    } tclientes;

    FILE* arch = fopen("clientes.dat", "rb");

    if (arch == NULL) {
        wxMessageBox("Error al abrir el archivo", "Error", wxOK | wxICON_ERROR);
    } else {
        wxMessageBox("archivo abierto", "Información", wxOK | wxICON_INFORMATION);
    }

    tclientes cliente;
    wxMessageBox("estructura creada", "Información", wxOK | wxICON_INFORMATION);


    int index = 0;

    while (fread(&cliente, sizeof(tclientes), 1, arch) == 1) {
        wxMessageBox("entro al bucle", "Información", wxOK | wxICON_INFORMATION);
        wxString codigo = cliente.codigo;
        wxString nombre = cliente.nombre;
        wxString telefono = cliente.numeroDeTelefono;

        wxMessageBox("Código: " + codigo, "Información", wxOK | wxICON_INFORMATION);
        wxMessageBox("Nombre: " + nombre, "Información", wxOK | wxICON_INFORMATION);
        wxMessageBox("Teléfono: " + telefono, "Información", wxOK | wxICON_INFORMATION);

    wxMessageBox("definio las variables", "Información", wxOK | wxICON_INFORMATION);

        datosList->InsertItem(index, codigo);

        datosList->SetItem(index, 1, nombre);
        datosList->SetItem(index, 2, telefono);

        index++;
    }

    if (feof(arch)) {
        wxMessageBox("Fin del archivo", "Información", wxOK | wxICON_INFORMATION);
    } else {
        wxMessageBox("Error durante la lectura", "Error", wxOK | wxICON_ERROR);
    }

    fclose(arch);
}