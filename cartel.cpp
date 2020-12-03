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

void cLinea(int cantidad, int modo){ // Determinamos la cantidad de repeticiones
    string linea = "-", lineas; // Determinamos el separador
    for(int i=0; i<cantidad; i++){
        lineas += linea;
    }
    if(modo == 0){cout << lineas << endl;}
    if(modo == 1){
        cout << endl;
        cout << lineas << endl;
    }

}

void cMsj(int modo){
    if(modo == 1){msj("SE GUARDO CON EXITO", rlutil::WHITE, rlutil::GREEN);}
    if(modo == 2){msj("ERROR AL GUARDAR", rlutil::WHITE, rlutil::RED);}
    if(modo == 3){msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);}
    if(modo == 4){msj("NO EXISTE ID", rlutil::WHITE, rlutil::RED);}
    if(modo == 6){msj("PRESIONE UNA TECLA PARA VOLVER", rlutil::WHITE, rlutil::GREEN);}
    if(modo == 7){msj("USUARIO INACTIVO", rlutil::WHITE, rlutil::RED);}
    if(modo == 8){msj("SE CREO CON ÉXITO LA COPIA DE SEGURIDAD", rlutil::WHITE, rlutil::GREEN);}
    if(modo == 9){msj("ERROR AL CREAR COPIA DE SEGURIDAD", rlutil::WHITE, rlutil::RED);}
    if(modo == 10){msj("SE RESTAURO CON ÉXITO LA COPIA DE SEGURIDAD", rlutil::WHITE, rlutil::GREEN);}
    if(modo == 11){msj("ERROR AL RESTAURAR COPIA DE SEGURIDAD", rlutil::WHITE, rlutil::RED);}
    if(modo == 12){msj("PIN DE SEGURIDAD INCORRECTO", rlutil::WHITE, rlutil::RED);}
    if(modo == 13){msj("FECHA INCORRECTA", rlutil::WHITE, rlutil::RED);}
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

void cMenuReporte(){
    cTitulo("MENÚ REPORTES");
    cout << "*RECUPERATORIO PRIMER PARCIAL" << endl;
    cout << "1) PUNTO UNO" << endl;
    cout << "2) PUNTO DOS" << endl;
    cLinea();
    cout << "0) SALIR DEL PROGRAMA" << endl;
    cout << endl;
    cout << "> ";
}

void cMenuConfiguracion(){
    cTitulo("MENÚ CONFIGURACIÓN");
    cout << "1) REALIZAR COPIA DE SEGURIDAD" << endl;
    cout << "2) RESTAURAR COPIA DE SEGURIDAD" << endl;
    cLinea();
    cout << "0) VOLVER AL MENÚ PRINCIPAL" << endl;
    cout << endl;
    cout << "> ";
}

void cListar(int modo){
    int col = 2;
    if(modo == 1){ //MODO 1 PARA USUARIO
        int ancho1 = 13;
        cout << setw(4) << "ID";
        cout << setw(col) << " ";
        cout << setw(ancho1) << "NOMBRES";
        cout << setw(col) << " ";
        cout << setw(ancho1) << "APELLIDOS";
        cout << setw(col) << " ";
        cout << setw(11) << "FECHA";
        cout << setw(col) << " ";
        cout << setw(7) << "ALTURA";
        cout << setw(col) << " ";
        cout << setw(5) << "PESO";
        cout << setw(col) << " ";
        cout << setw(10) << "PERFIL ACT";
        cout << setw(col) << " ";
        cout << setw(8) << "APTO M";
        cout << setw(col) << " ";
        cout << setw(7) << "ESTADO";
    }
    if(modo == 2){ //MODO 2 PARA ENTRENAMIENTO
        int ancho2 = 11;
        cout << setw(4) << "ID";
        cout << setw(col) << " ";
        cout << setw(ancho2) << "IDUSUARIO";
        cout << setw(col) << " ";
        cout << setw(11) << "FECHA";
        cout << setw(col) << " ";
        cout << setw(10) << "ACTIVIDAD";
        cout << setw(col) << " ";
        cout << setw(9) << "CALORÍAS";
        cout << setw(col) << " ";
        cout << setw(7) << "TIEMPO";
    }
    cLinea(100,1);
}

void cBarraProgreso(){
    int porcentaje = 0;
    gotoxy(43,10);
    cout << "CARGANDO...";
    for(int a=0; a<=100; a++){
        gotoxy(54,10);
        cout << a << "%";
        for(int b=50; b<80; b++){
            for(int c=1; c<80; c++){
                gotoxy(54,10);
            }
        }
    }
    // BARRA DE PROGRESO
    for(int i=1; i<100; i++){
        gotoxy(i,13);
        setColors(rlutil::WHITE, rlutil::BLUE);
        printf("_");
        for(int x=50; x<70; x++){
            for(int y=1; y<70; y++){
                gotoxy(y,24);
            }
        }
    }
    rlutil::resetColor();
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
    // FIN BARRA DE PROGRESO
}
