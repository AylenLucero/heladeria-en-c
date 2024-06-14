#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main()
{
    DatosCuentaAdmin datos;
    crearArchivoBinario("cuentaAdmin.bin");
    menuPrincipal(&datos);

    return 0;
}
