#include <iostream>
#include <windows.h> ///Para funciones system
#include "ui.h"
#include "rlutil.h"
using namespace std;

int main()
{
    int modoDev = 0;
    if(modoDev == 0){
        initUI();
        menuPrincipal();
    } else { // INGRESAR DESARROLLO DE FUNCIONES PARA PRUEBAS

    }


    return 0;
}
