/**
    Trabajo practico 1,2 y 3 de Laboratorio 2

    Autores:    •Maximiliano Miranda

*/
#include <iostream>
#include <locale.h> ///Para poner idioma en español
#include <windows.h> ///Para funciones system
#include "ui.h"
#include "rlutil.h"
using namespace std;
#include "funciones.h"
#include "strUsuario.h"

int main()
{
    int modoDev = 0;
    if(modoDev == 0){
        initUI();
        menuPrincipal();
    } else { // INGRESAR DESARROLLO DE FUNCIONES PARA PRUEBAS
        Usuario u;
        cargarDatos();
        mostrarDatos(u);
    }


    return 0;
}
