#include <iostream>
#include <windows.h>
#include "ui.h"
#include "rlutil.h"
#include <stdio.h>
#include <string.h>
using namespace std;
#include "menu.h"
#include "cartel.h"

/// TP CREADO DE CERO INDIVIDUALMENTE POR MAXIMILIANO MIRANDA
#include "parcial1.h"
int main()
{
    int modoDev = 0; // Default 0 , inicia el programa normal, valor 1 inicia el modo de test
    if(modoDev == 0){
        initUI();
        menuPrincipal();
    } else { // MODO TEST
        initUI();
        cTitulo("ESTAS EN MODO DEV PARA PRUEBAS");
        // INGRESAR DESARROLLO DE FUNCIONES PARA TEST
        punto2B();

    } // FINALIZA EL MODO TEST


    return 0;
}

