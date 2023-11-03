#include <stdio.h>
#include <stdlib.h>
#include "string.h"

//ESTRUCTURAS
typedef struct
{
    int nota;
    int legajo;
    char nombreApe[40];
    char materia[40];
    int idMateria;
} registroArchivo;

typedef struct
{
    int nota;
    int legajo;
    char nombreApe[40];
} notaAlumno;

typedef struct _nodo
{
    notaAlumno dato;
    struct _nodo *siguiente;
} nodo;
typedef struct
{
    int idMateria;
    char materia[40];
    nodo * listaDeNotas;
} celda;

registroArchivo cargarRegistro();
void cargarArchivo(char archivo[]);
void printMenu();
void cargarArchivo(char archivo[]);
void mostrarArchivo(char archivo[]);
void mostrarRegistro(registroArchivo registro);

int main()
{
    //VARIABLES
    FILE* archi;
    char archivo[] = {"miArchivo.bin"};
    int opc = 0;
    int loop = 0;

    printMenu();
    scanf("%i", &opc);
    switch(opc)
    {
    case 1:
        cargarArchivo(archivo);
        break;
    case 2:
        mostrarArchivo(archivo);
        break;
    default:
        break;
    }


    return 0;
}

//FUNCIONES
registroArchivo cargarRegistro()
{
    registroArchivo aux;

    printf("INGRESE NOMBRE DEL ALUMNO: \n");
    fflush(stdin);
    gets(aux.nombreApe);

    printf("INGRESE LEGAJO DEL ALUMNO: \n");
    scanf("%i", &aux.legajo);

    printf("INGRESE MATERIA:  \n");
    fflush(stdin);
    gets(aux.materia);

    printf("INGRESE ID DE MATERIA \n");
    scanf("%i", &aux.idMateria);

    printf("INGRESE NOTA \n");
    scanf("%i", &aux.nota);

    return aux;
}

void printMenu()
{
    printf("\n");
    printf("================MENU================\n");
    printf(" 1- Cargar archivo con registros\n");
    printf(" 2- Mostrar archivo\n");
    printf("====================================");
    printf("\nIngrese una opcion: \n");

}

void cargarArchivo(char archivo[])
{
    registroArchivo registro;
    char opc = 's';
    FILE* archi = fopen(archivo, "a+b");
    if (archi)
    {
        while(opc == 's')
        {
            registro = cargarRegistro();
            fwrite(&registro, sizeof(registroArchivo), 1, archi);
            printf("SI DESEA SEGUIR CARGANDO, INGRESE s\n");
            fflush(stdin);
            scanf("%c", &opc);
        }
        fclose(archi);
    }
    else
    {
        printf("EL ARCHIVO NO EXISTE\n");
    }

}

void mostrarArchivo(char archivo[])
{
    registroArchivo registro;
    FILE* archi = fopen(archivo, "rb");
    if (archi)
    {
        while(!feof(archi))
        {
            fread(&registro, sizeof(registroArchivo), 1, archi);
            if(!feof(archi))
            {
                mostrarRegistro(registro);
            }
        }
        fclose(archi);
    }
    else
    {
        printf("EL ARCHIVO NO EXISTE");
    }
}

void mostrarRegistro(registroArchivo registro)
{
    printf("NOMBRE: %s\n", registro.nombreApe);
    printf("LEGAJO: %i\n", registro.legajo);
    printf("MATERIA: %s\n", registro.materia);
    printf("ID: %i\n", registro.idMateria);
    printf("NOTA: %i\n", registro.nota);

}
