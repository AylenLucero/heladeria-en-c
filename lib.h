#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct DatosCuentaAdmin { //Estructura datos de cuenta de administradores
    int dni;
    char contrasena[20];
} TDatosCuentaAdmin;

typedef struct DatosCuentaCajeros { //Estructura datos de cuenta de cajeros
    int codUnico;
    char contrasena[20];
} TDatosCuentaCajeros;

void menuPrincipal(TDatosCuentaAdmin *datos);
void crearArchivoBinario(char *nombreArchivoBinario);
int archivoEstaVacio(char *nombreArchivo);

void leerArchivoBinarioInicioSesion(char *nombreArchivoBinario, char *puesto);
void menuAdmin(TDatosCuentaAdmin *datos);


#endif // LIB_H_INCLUDED
