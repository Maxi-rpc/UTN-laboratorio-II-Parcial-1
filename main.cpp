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
    } else { // INGRESAR DESARROLLO DE FUNCIONES PARA PRUEBAS
        initUI();
        cTitulo("ESTAS EN MODO DEV PARA PRUEBAS");
        bool test;
        int dia=9, mes=11, anio=2007, edad=13;
        test = validarEdad(dia , mes , anio, edad);
        if(test){cout << "MAYOR A 13";}
        else{cout << "MENOR A 13";}

    }


    return 0;
}
