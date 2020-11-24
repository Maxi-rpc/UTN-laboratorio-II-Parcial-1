#include <iostream>
#include <windows.h> ///Para funciones system
#include "ui.h"
#include "rlutil.h"
using namespace std;
#include "menu.h"
/// ELIMINAR ESTOS INCLUDES
#include "usuario.h"

int main()
{
    int modoDev = 1; // en 0 , inicia el programa normal, valor 1 inicia el modo de test
    if(modoDev == 0){
        initUI();
        menuPrincipal();
    } else { // INGRESAR DESARROLLO DE FUNCIONES PARA PRUEBAS
        /*Usuario u;
        u = cargarDatos();
        guardarUsuario(u);
        cout << endl;
        */int pos = cantidadUsuarios();
        cout << pos << endl;
        for (int i=0; i<pos; i++){
            Usuario u = leerUsuario(i);
            mostrarDatos(u,1);
        }
    }


    return 0;
}
