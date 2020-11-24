#include <iostream>
#include <windows.h> ///Para funciones system
#include "ui.h"
#include "rlutil.h"
using namespace std;
#include "menu.h"
#include "cartel.h"

void menuPrincipal(){
    bool menu = true;
    int opc;
    while(menu){
        cMenu();
        while(!(cin >> opc)){
            cMsj(3);
            cin.clear();
            cin.ignore(123, '\n');
            cMenu();
        }
        switch(opc){
            case 1:
                menuUsuario();
            break;
            case 2:
                menuEntrenamiento();
            break;
            case 3:
                menuReporte();
            break;
            case 4:
                menuConfiguracion();
            break;
            case 0:
                menu = false;
            break;
            default: cMsj(3);
            break;
        }
    }
}

void menuUsuario(){
    bool menu = true;
    int opc;
    while(menu){
        cMenuUsuario();
        while(!(cin >> opc)){
            cMsj(3);
            cin.clear();
            cin.ignore(123, '\n');
            cMenuUsuario();
        }
        switch(opc){
            case 1:
                menuUsuario();
            break;
            case 2:
                menuEntrenamiento();
            break;
            case 3:
                menuReporte();
            break;
            case 4:
                menuConfiguracion();
            break;
            case 0:
                menu = false;
            break;
            default: cMsj(3);
            break;
        }
    }
}

void menuEntrenamiento(){

}

void menuReporte(){

}

void menuConfiguracion(){

}
