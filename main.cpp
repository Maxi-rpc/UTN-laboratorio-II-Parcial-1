#include <iostream>
#include <windows.h> ///Para funciones system
#include "ui.h"
#include "rlutil.h"
using namespace std;
#include "menu.h"
/// ELIMINAR ESTOS INCLUDES
#include "usuario.h"
#include "entrenamiento.h"

int main()
{
    int modoDev = 0; // en 0 , inicia el programa normal, valor 1 inicia el modo de test
    if(modoDev == 0){
        initUI();
        menuPrincipal();
    } else { // INGRESAR DESARROLLO DE FUNCIONES PARA PRUEBAS
        cout << "ESTAS EN MODO DEV PARA PRUEBAS" << endl;

    }


    return 0;
}
