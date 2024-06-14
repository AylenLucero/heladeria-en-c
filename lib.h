#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct { //Estructura datos de cuenta de administradores
    int dni;
    char contrasena[20];
} DatosCuentaAdmin;

typedef struct { //Estructura datos de cuenta de cajeros
    int codUnico;
    char contrasena[20];
} DatosCuentaCajeros;

void menuPrincipal(DatosCuentaAdmin *datos);
void crearArchivoBinario(char *nombreArchivoBinario);
int archivoEstaVacio(char *nombreArchivo);
void ingresarDatosCuentaAdmin(DatosCuentaAdmin *datos);
void guardarDatos(const char *nombreArchivoBinario, DatosCuentaAdmin *datos);
void leerArchivoBinario(char *nombreArchivoBinario, DatosCuentaAdmin *datos, char *puesto);
void menuAdmin(DatosCuentaAdmin *datos);


#endif // LIB_H_INCLUDED
