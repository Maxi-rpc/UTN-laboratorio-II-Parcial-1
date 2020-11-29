#include <iostream>
#include <windows.h> ///Para funciones system
#include "ui.h"
#include "rlutil.h"
#include <stdio.h>
#include <string.h>
using namespace std;
#include "menu.h"
/// ELIMINAR ESTOS INCLUDES
#include "cartel.h"
#include "fecha.h"
#include "usuario.h"
#include "entrenamiento.h"
#include "validar.h"

int main()
{
    int modoDev = 0; // en 0 , inicia el programa normal, valor 1 inicia el modo de test
    if(modoDev == 0){
        initUI();
        menuPrincipal();
    } else { // INGRESAR DESARROLLO DE FUNCIONES PARA TEST
        initUI();
        cTitulo("ESTAS EN MODO DEV PARA PRUEBAS");


    } // FINALIZA EL MODO TEST


    return 0;
}

