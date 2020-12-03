#include <iostream>
#include <windows.h> ///Para funciones system
#include "ui.h"
#include "rlutil.h"
#include <stdio.h>
#include <string.h>
using namespace std;
#include <iomanip>
#include "menu.h"
/// ELIMINAR ESTOS INCLUDES
#include "cartel.h"
#include "fecha.h"
#include "usuario.h"
#include "entrenamiento.h"
#include "validar.h"

#include "parcial1.h"

/// A partir de un IDUsuario que se ingresa por teclado, listar todos los códigos de actividades que no haya realizado nunca.

void cMenuReporte(){
    cTitulo("MENÚ REPORTES");
    cout << "1) PUNTO UNO" << endl;
    cout << "2) PUNTO DOS" << endl;
    cLinea();
    cout << "0) SALIR DEL PROGRAMA" << endl;
    cout << endl;
    cout << "> ";
}

void puntoUno(){
    int id, pos;
    cTitulo("PUNTO UNO");
    cout << "A partir de un IDUsuario que se ingresa por teclado, listar todos los códigos de actividades que no haya realizado nunca."<<endl;
    cout << "> ";
    cin >> id;
    cLinea();
    pos = buscarUsuario(id);
    if(pos >= 0){
        Usuario user = leerUsuario(pos);
        if(user.estado == true){
            cout << user.id << "," << user.nombres << "," << user.apellidos << endl;
            listarActividadNo(id);
            cMsj(6);
        }else{cMsj(7);}
    }else {cMsj(4);}
}

void listarActividadNo(int idUsuario){
    string actividad[5] = {"CAMINATA","CORRER","BICICLETA","NATACIÓN","PESAS"};
    int cant = cantidadEntren();
    int act[5]={};
    for(int i=0; i<cant; i++){
        Entrenamiento reg = leerEntren(i);
        if(idUsuario == reg.idUsuario){
            act[reg.actividad-1]++;
        }
    }
    for(int v=0; v<5; v++){
        if(act[v] == 0){
            cout << actividad[v] << ",";
        }
    }
}

void puntoDos(){
    int cant = cantidadUsuarios(), col=2;
    float calorias=0;
    cTitulo("PUNTO DOS");
    cout << "Por cada usuario, listar los Apellidos y nombres y la cantidad total de calorías quemadas." << endl;
    cout << endl;
    listarPunto2();
    for(int i=0; i<cant; i++){
        Usuario user = leerUsuario(i);
        calorias = contarCalorias(user.id);
        cout << setw(15) << user.nombres;
        cout << setw(col) << " ";
        cout << setw(15) << user.apellidos;
        cout << setw(col) << " ";
        cout << setw(9) << calorias;
        cLinea(100,1);
    }
    cMsj(6);
}

float contarCalorias(int idUsuario){
    float calorias=0;
    int cant = cantidadEntren();
    for(int i=0; i<cant; i++){
        Entrenamiento reg = leerEntren(i);
        if(idUsuario == reg.idUsuario){
            calorias += reg.calorias;
        }
    }
    return calorias;
}

void listarPunto2(){
    int col = 2;
    cout << setw(15) << "NOMBRES";
    cout << setw(col) << " ";
    cout << setw(15) << "APELLIDOS";
    cout << setw(col) << " ";
    cout << setw(9) << "CALORÍAS";
    cLinea(100,1);
}
