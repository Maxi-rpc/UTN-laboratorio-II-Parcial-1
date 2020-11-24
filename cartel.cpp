#include <iostream>
#include <windows.h>
#include <iomanip>
#include "ui.h"
#include "rlutil.h"
using namespace std;
#include "cartel.h"

void cTitulo(char *titulo){
    rlutil::cls();
    title(titulo);
    gotoXYPred();
}

void gotoXYPred(int x, int y){
    gotoxy(x, y);
}

void cLinea(int cantidad){ // Determinamos la cantidad de repeticiones
    string linea = "-", lineas; // Determinamos el separador
    for(int i=0; i<cantidad; i++){
        lineas += linea;
    }
    cout << lineas << endl;
}

void cMsj(int modo){
    if(modo == 1){msj("SE GUARDO CON EXITO", rlutil::WHITE, rlutil::GREEN);};
    if(modo == 2){msj("ERROR AL GUARDAR", rlutil::WHITE, rlutil::RED);};
    if(modo == 3){msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);};
    if(modo == 4){msj("NO EXISTE ID", rlutil::WHITE, rlutil::RED);};
    if(modo == 6){msj("PRESIONE UNA TECLA PARA VOLVER", rlutil::WHITE, rlutil::GREEN);};
    if(modo == 7){msj("USUARIO INACTIVO", rlutil::WHITE, rlutil::RED);};
}

void cMenu(){
    cTitulo("MENÚ PRINCIPAL");
    cout << "1) USUARIOS" << endl;
    cout << "2) ENTRENAMIENTOS" << endl;
    cout << "3) REPORTES" << endl;
    cout << "4) CONFIGURACIÓN" << endl;
    cLinea();
    cout << "0) SALIR DEL PROGRAMA" << endl;
    cout << endl;
    cout << "> ";
}

void cMenuUsuario(){
    cTitulo("MENÚ USUARIOS");
    cout << "1) NUEVO USUARIO" << endl;
    cout << "2) MODIFICAR USUARIO" << endl;
    cout << "3) LISTAR USUARIO POR ID" << endl;
    cout << "4) LISTAR TODOS LOS USUARIOS" << endl;
    cout << "5) ELIMINAR USUARIO" << endl;
    cLinea();
    cout << "0) VOLVER AL MENÚ PRINCIPAL" << endl;
    cout << endl;
    cout << "> ";
}

void cMenuEntrenamiento(){
    cTitulo("MENÚ ENTRENAMIENTOS");
    cout << "1) NUEVO ENTRENAMIENTO" << endl;
    cout << "2) MODIFICAR ENTRENAMIENTO" << endl;
    cout << "3) LISTAR ENTRENAMIENTO POR ID" << endl;
    cout << "4) LISTAR ENTRENAMIENTO POR ID USUARIO" << endl;
    cout << "5) LISTAR TODOS LOS ENTRENAMIENTOS" << endl;
    cLinea();
    cout << "0) VOLVER AL MENÚ PRINCIPAL" << endl;
    cout << endl;
    cout << "> ";
}
