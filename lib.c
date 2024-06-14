#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

void menuPrincipal(DatosCuentaAdmin *datos)
{
    int opPuesto = 0;
    do
    {
        system("cls");
        printf("BIENVENIDO A LA HELADERIA ICE!!!\n");
        printf("Indique su puesto para continuar\n1)Cajero\n2)Administrador\n3)Salir\n");
        fflush(stdin);
        scanf("%d",&opPuesto);
        switch(opPuesto)
        {
        case 1:
            break;
        case 2:
            if (archivoEstaVacio("cuentaAdmin.bin"))
            {
                ingresarDatosCuentaAdmin(&datos);
                guardarDatos("cuentaAdmin.bin", &datos);
            }
            leerArchivoBinario("cuentaAdmin.bin", &datos, "ADMINISTRADOR");
            break;
        default:
            break;
        }
    }
    while(opPuesto!=3);
}

void crearArchivoBinario(char *nombreArchivoBinario)
{
    FILE *archivo = fopen(nombreArchivoBinario, "ab");
    if(archivo == NULL)
    {
        printf("No se pudo crear el arcrivo\n");
    }
    else
    {
        printf("Se creo el archivo correctamente\n");
    }
    fclose(archivo);
}

int archivoEstaVacio(char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL)
    {
        perror("No se pudo abrir el archivo");
        return 0;
    }

    fseek(archivo, 0, SEEK_END);
    long size = ftell(archivo);
    fclose(archivo);

    return size <= sizeof(DatosCuentaAdmin);
}

void ingresarDatosCuentaAdmin(DatosCuentaAdmin *datos)
{
    printf("Bienvenido! Administrador, cree su cuenta\n");
    printf("Ingrese su DNI: ");
    fflush(stdin);
    scanf("%d",&datos->dni);
    printf("\n");
    printf("Ingrese su nueva constrasena: ");
    scanf("%s",&datos->contrasena);
    printf("%s",datos->contrasena);
}

void guardarDatos(const char *nombreArchivoBinario, DatosCuentaAdmin *datos)
{
    FILE *archivo = fopen(nombreArchivoBinario, "ab");
    if (archivo == NULL)
    {
        perror("No se pudo abrir el archivo para escritura");
        exit(EXIT_FAILURE);
    }

    fwrite(datos, sizeof(DatosCuentaAdmin), 1, archivo);
    fclose(archivo);
    printf("Datos guardados exitosamente en '%s'.\n", nombreArchivoBinario);
}

void leerArchivoBinario(char *nombreArchivoBinario, DatosCuentaAdmin *datos, char *puesto)
{
    system("cls");
    FILE *archivo = fopen(nombreArchivoBinario, "rb");
    int dato;
    if(archivo != NULL)
    {
        int dniBuscar;
        char contrasena[20];
        printf("INICIAR SESION\nPara ingresar a su cuenta de %s, debe:\n", puesto);
        printf("Ingresar DNI: ");
        fflush(stdin);
        scanf("%d",&dniBuscar);
        printf("Ingresar contrasena: ");
        fflush(stdin);
        scanf("%s",&contrasena);
        while (fread(datos, sizeof(DatosCuentaAdmin), 1, archivo))
        {
            if ((datos->dni == dniBuscar) && (strcmp(contrasena,datos->contrasena)==0))
            {
                menuAdmin(datos);
                break;
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }
}

void menuAdmin(DatosCuentaAdmin *datos)
{
    int op = 0;
    do
    {
        system("cls");
        printf("Bienvenido al ADMINISTRADOR\n");
        printf("Elija una de las opciones:\n1)Agregar nuevo cajero\n2)Agregar nuevo administrador\n3)Revisar stock\n4)Realizar compra\n5)Volver al menu principal\n6)Salir\n");
        fflush(stdin);
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            break;
        case 2:
            ingresarDatosCuentaAdmin(&datos);
            guardarDatos("cuentaAdmin.bin", &datos);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            menuPrincipal(&datos);
            break;
        default:
            break;
        }
    }
    while (op != 6);
}
