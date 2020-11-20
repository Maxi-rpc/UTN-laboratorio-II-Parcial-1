#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;
#include <cstdio>
#include <ctime>
#include "funciones.h"
#include "strUsuario.h"
#include "entrenamiento.h"
#include "rlutil.h"
#include "ui.h"
#include "carteles.h"
#include "ej1.h"

///Funciones generales

void creditos(){
    cout << "\t\t\tTrabajo práctico 1, 2 y 3 de Laboratorio 2";
    cout << "\n\n\tAutores: ";
    cout << "\n\t\tMaximiliano Miranda";
    cout << "\n\t\tGabriel Rolón";
    cout << "\n\t\tCristian Uhrig" << endl << endl;
    Sleep(8000);
}
void menuPrincipal(){
    bool menu = true;
    while(menu){
        cMenu(0);
        int opcion;
        cin >> opcion;
        switch(opcion){
            case 1:
                menuUsuarios();
            break;
            case 2:
                menuEntrenamientos();
            break;
            case 3:
                reporteUno();
            break;
            case 4:
                menuConfiguracion();
            break;
            case 0:
                menu = false;
            break;
        }
    }
}

void menuUsuarios(){
    bool menu = true;
    while(menu){
        cMenu(1);
        int opcion;
        cin >> opcion;
        switch(opcion){
            case 1:
                guardarUsuario(cargarDatos());
            break;
            case 2:
                modificarUser();
            break;
            case 3:
                listarPorId();
            break;
            case 4:
                listarUsuarios();
            break;
            case 5:
                eliminarUser();
            break;
            case 0:
                menu = false;
            break;
        }
    }
}

void menuEntrenamientos(){
    bool menu = true;
    while(menu){
        cMenu(2);
        int opcion;
        cin >> opcion;
        switch(opcion){
            case 1:
               guardarEntren(cargarEntrenamiento());
            break;
            case 2:
                modificarEnt();
            break;
            case 3:
                listarPorIdEnt();
            break;
            case 4:
                //listarEnPorIdUsuario();
            break;
            case 5:
                listarEnTodos();
            break;
            case 0:
                menu = false;
            break;
        }
    }
}
void menuConfiguracion(){
    bool menu = true;
    while(menu){
        cMenu(3);
        int opcion;
        cin >> opcion;

        switch(opcion){
            case 1:
               copiaDeSeguridad();
            break;
            case 2:
                restaurarCopia();
            break;
            case 0:
                menu = false;
            break;
        }
    }
}
///Funciones Externas

void copiaDeSeguridad(){
    int guardo = 0;
    guardo += copiaDeSeguridadUsuario();
    guardo += copiaDeSeguridadEntren();
    if(guardo == 2){
        msj("SE CREO COPIA DE SEGURIDAD", rlutil::WHITE,rlutil::GREEN);
    } else {
        msj("ERROR AL CREAR COPIA DE SEGURIDAD", rlutil::WHITE,rlutil::RED);
    }
}
