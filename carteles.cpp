#include <iostream>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;

#include "carteles.h"

void cTitulo(const char *titulo){
    cls();
    title(titulo);
    gotoXYPred();
}

void gotoXYPred(int x, int y){
    gotoxy(x, y);
}

void cMenu(int modo){
    if(modo == 0){
        cTitulo("MENU PRINCIPAL");
        cout << "1) USUARIOS" << endl;
        cout << "2) ENTRENAMIENTOS" << endl;
        cout << "3) REPORTES" << endl;
        cout << "4) CONFIGURACION" << endl;
        cout << "--------------" << endl;
        cout << "0) SALIR DEL PROGRAMA" << endl;
    }
    if(modo == 1){
        cTitulo("MENU USUARIOS");
        cout << "1) NUEVO USUARIO" << endl;
        cout << "2) MODIFICAR USUARIO" << endl;
        cout << "3) LISTAR USUARIO POR ID" << endl;
        cout << "4) LISTAR TODOS LOS USUARIOS" << endl;
        cout << "5) ELIMINAR USUARIO" << endl;
        cout << "--------------" << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL" << endl << endl;
    }
    if(modo == 2){
        cTitulo("MENU ENTRENAMIENTOS");
        cout << "1) NUEVO ENTRENAMIENTO" << endl;
        cout << "2) MODIFICAR ENTRENAMIENTO" << endl;
        cout << "3) LISTAR ENTRENAMIENTO POR ID" << endl;
        cout << "4) LISTAR ENTRENAMIENTO POR IDUSUARIO" << endl;
        cout << "5) LISTAR TODOS LOS ENTRENAMIENTOS" << endl;
        cout << "--------------" << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL" << endl << endl;
    }
    if(modo == 3){
        cTitulo("MENU CONFIGURACIÓN");
        cout << "--------------" << endl;
        cout << "1) REALIZAR COPIA DE SEGURIDAD" << endl;
        cout << "2) RESTAURAR COPIA DE SEGURIDAD" << endl;
        cout << "--------------" << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL" << endl << endl;
    }
}
