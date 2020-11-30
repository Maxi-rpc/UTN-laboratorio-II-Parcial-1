#include <iostream>
#include <windows.h> ///Para funciones system
#include "ui.h"
#include "rlutil.h"
#include <stdio.h>
#include <string.h>
using namespace std;
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
    int id, pos, cant = cantidadUsuarios();
    cTitulo("PUNTO UNO");
    cout << "A partir de un IDUsuario que se ingresa por teclado, listar todos los códigos de actividades que no haya realizado nunca."<<endl;
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


