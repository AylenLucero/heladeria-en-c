#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define ValoresCuentasAdmin "cuentaAdmin.bin"

int main()
{
    TDatosCuentaAdmin datos;
    crearArchivoBinario(ValoresCuentasAdmin);
    menuPrincipal(&datos);

    return 0;
}
