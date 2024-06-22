#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define ValoresCuentasAdmin "cuentaAdmin.dat"

void menuPrincipal(TDatosCuentaAdmin *datos)
{
    int opPuesto = 0;
    do
    {
        printf("BIENVENIDO A LA HELADERIA ICE!!!\n");
        printf("Indique su puesto para continuar\n1)Cajero\n2)Administrador\n3)Salir\n");
        fflush(stdin);
        scanf("%d",&opPuesto);
        switch(opPuesto)
        {
        case 1:
            break;
        case 2:/*
            if (archivoEstaVacio(ValoresCuentasAdmin) == 1)
            {
                ingresarYGuardarDatosCuentaAdmin(ValoresCuentasAdmin);
            } else {
                leerArchivoBinarioInicioSesion(ValoresCuentasAdmin, "ADMINISTRADOR");
            }*/
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

    return size <= sizeof(TDatosCuentaAdmin);
}

void ingresarYGuardarDatosCuentaAdmin(char *nomArchivo) {
    FILE *archivo = fopen(nomArchivo, "ab");
    if (!archivo) {
        printf("No se pudo encontrar el archivo");
    } else {
        TDatosCuentaAdmin datoCuentaAdmin;
        int op;
        do {
            printf("Cree su cuenta de Administrador\n");
            printf("Ingrese su DNI:");
            fflush(stdin);
            scanf("%d",&datoCuentaAdmin.dni);
            while (existeEnArchivo(nomArchivo, datoCuentaAdmin.dni) == 1) {
                printf("\nEse DNI ya tiene una cuenta registrada como Administrador, reingrese:\n");
                fflush(stdin);
                scanf("%d", &datoCuentaAdmin.dni);
            }
            printf("\nIngrese su nueva contraseña:");
            fflush(stdin);
            scanf("%s",&datoCuentaAdmin.contrasena);
            fwrite(&datoCuentaAdmin, sizeof(TDatosCuentaAdmin), 1, archivo);
            printf("Desea cargar otro administrador?\n1)Si\n2)No\n");
            fflush(stdin);
            scanf("%d",&op);
        } while (op != 2);
        fclose(archivo);
    }
}

void leerArchivoBinarioInicioSesion(char *nombreArchivoBinario, char *puesto) {
    FILE *archivo = fopen(nombreArchivoBinario, "rb");
    if (archivo != NULL) {
        TDatosCuentaAdmin dato;
        int dniBuscar;
        char contrasena[20];
        printf("INICIAR SESION\nPara ingresar a su cuenta de %s, debe:\n", puesto);
        printf("Ingresar DNI: ");
        fflush(stdin);
        scanf("%d", &dniBuscar);
        printf("Ingresar contrasena: ");
        fflush(stdin);
        scanf("%s",&contrasena);
        while (!feof(archivo)) {
        if(fread(&dato, sizeof(TDatosCuentaAdmin), 1, archivo)==1) {
                printf("DNI buscado: %d\n", dniBuscar);
                printf("DNI en archivo: %d\n", dato.dni);
                printf("Contraseña buscada: %s\n", contrasena);
                printf("Contraseña en archivo: %s\n", dato.contrasena);
            if ((dato.dni == dniBuscar) && (strcmp(dato.contrasena, contrasena) == 0)) {
                printf("DNI buscado: %d\n", dniBuscar);
                printf("DNI en archivo: %d\n", dato.dni);
                printf("Contraseña buscada: %s\n", contrasena);
                printf("Contraseña en archivo: %s\n", dato.contrasena);

                fclose(archivo);
                return;
            }
        }else{
            printf("ERROR: %s\n",strerror(errno));
        }

        }
        printf("DNI no encontrado en el archivo\n");
        fclose(archivo);
    } else {
        printf("No se pudo abrir el archivo\n");
    }
}


void menuAdmin(TDatosCuentaAdmin *datos)
{
    int op = 0;
    do
    {
        printf("Bienvenido al ADMINISTRADOR\n");
        printf("Elija una de las opciones:\n1)Agregar nuevo cajero\n2)Agregar nuevo administrador\n3)Revisar stock\n4)Realizar compra\n5)Volver al menu principal\n6)Salir\n");
        fflush(stdin);
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            break;
        case 2:
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

int existeEnArchivo(char *nombreArchivoBinario, int dniBuscar) {
    FILE *archivo = fopen(nombreArchivoBinario, "rb");
    if (archivo == NULL) {
        return 0;
    }

    TDatosCuentaAdmin datos;
    while (fread(&datos, sizeof(TDatosCuentaAdmin), 1, archivo)) {
            if (datos.dni == dniBuscar) {
                fclose(archivo);
                return 1; // DNI encontrado
            }
    }

    fclose(archivo);
    return 0; // DNI no encontrado
}

void ingresarDatosCuentaAdmin(TDatosCuentaAdmin *datos)
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

void guardarDatos(const char *nombreArchivoBinario, TDatosCuentaAdmin *datos)
{
    FILE *archivo = fopen(nombreArchivoBinario, "ab");
    if (archivo == NULL)
    {
        perror("No se pudo abrir el archivo para escritura");
        exit(EXIT_FAILURE);
    }

    fwrite(datos, sizeof(TDatosCuentaAdmin), 1, archivo);
    fclose(archivo);
    printf("Datos guardados exitosamente en '%s'.\n", nombreArchivoBinario);
}

void leerArchivoBinario(char *nombreArchivoBinario, TDatosCuentaAdmin *datos, char *puesto)
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
        while (fread(datos, sizeof(TDatosCuentaAdmin), 1, archivo))
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
