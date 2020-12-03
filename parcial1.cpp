#include <iostream>
#include <windows.h>
#include "ui.h"
#include "rlutil.h"
#include <stdio.h>
#include <string.h>
using namespace std;
#include <iomanip>
#include "menu.h"
#include "cartel.h"
#include "fecha.h"
#include "usuario.h"
#include "entrenamiento.h"
#include "validar.h"

#include "parcial1.h"

void puntoUno(){
    int id, pos;
    cTitulo("PUNTO UNO");
    cout << "*A partir de un IDUsuario que se ingresa por teclado, listar todos los códigos de actividades que no haya realizado nunca."<<endl;
    cout << "> ";
    cin >> id;
    cLinea();
    pos = buscarUsuario(id);
    if(pos >= 0){
        Usuario user = leerUsuario(pos);
        if(user.estado == true){
            cout << "IDUSUARIO: " << user.id << endl;
            cout << "NOMBRES: " << user.nombres << endl;
            cout << "APELLIDOS: " << user.apellidos << endl;
            cout << "ACTIVIDAD NO REALIZADA: ";
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
            cout << actividad[v] << "-";
        }
    }
}

void puntoDos(){
    int cant = cantidadUsuarios(), col=2;
    float calorias=0;
    cTitulo("PUNTO DOS");
    cout << "*Por cada usuario, listar los Apellidos y nombres y la cantidad total de calorías quemadas." << endl;
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

void punto1A(){
    int id, pos;
    cTitulo("PUNTO 1 A");
    cout << "*A partir de un IDUsuario que se ingresa por teclado, listar el entrenamiento de mayor cantidad de calorías y la fecha en que las registró. Si hay dos registro con misma cantidad, mostrar el primero de ellos."<<endl;
    cout << "> ";
    cin >> id;
    cLinea();
    pos = buscarUsuario(id);
    if(pos >= 0){
        Usuario user = leerUsuario(pos);
        if(user.estado == true){
            cout << "IDUSUARIO: " << user.id << endl;
            cout << "NOMBRES: " << user.nombres << endl;
            listarCalFec(user.id);
            cMsj(6);
        }else{cMsj(7);}
    }else {cMsj(4);}
}

void listarCalFec(int idUsuario){
    string actividad[5] = {"CAMINATA","CORRER","BICICLETA","NATACIÓN","PESAS"};
    int cant = cantidadEntren(), act=0;
    float aux=0;
    Fecha faux;
    for(int i=0; i<cant; i++){
        Entrenamiento reg = leerEntren(i);
        if(idUsuario == reg.idUsuario){
            if(reg.calorias > aux){
                aux = reg.calorias;
                act = reg.actividad;
                faux.dia = reg.diaEntrenamiento.dia;
                faux.mes = reg.diaEntrenamiento.mes;
                faux.anio = reg.diaEntrenamiento.anio;
            }
        }
    }
    cout << "ENTRENAMIENTO CON MAYOR CANTIDAD DE CALORIAS: " << actividad[act-1] << endl;
    cout << "TOTAL DE CALORÍAS: " << aux << endl;
    cout << "FECHA: " << faux.dia << "/" << faux.mes << "/" << faux.anio << endl;
}

void punto2B(){
    cTitulo("PUNTO 2 A");
    cout << "*Por cada tipo de actividad, listar la cantidad de entrenamientos discriminado por perfil de usuario."<<endl;
    int col=2;
    cout << setw(2) << "N°";
    cout << setw(col) << " ";
    cout << setw(11) << "ACTIVIDAD";
    cout << setw(col) << " ";
    cout << setw(4) << "A";
    cout << setw(col) << " ";
    cout << setw(4) << "B";
    cout << setw(col) << " ";
    cout << setw(4) << "C";
    cLinea(100,1);
    listarCantPorPerfil();
    cMsj(6);
}

void listarCantPorPerfil(){
    string actividad[5] = {"CAMINATA","CORRER","BICICLETA","NATACIÓN","PESAS"};
    int cant = cantidadEntren();
    int act[5][3]={}, pos;
    for(int i=0; i<cant; i++){
        Entrenamiento reg = leerEntren(i);
        pos = buscarUsuario(reg.idUsuario);
        Usuario user = leerUsuario(pos);
        if(user.perfilActividad == 'A' || user.perfilActividad == 'a'){act[reg.actividad-1][0]++;}
        if(user.perfilActividad == 'B' || user.perfilActividad == 'b'){act[reg.actividad-1][1]++;}
        if(user.perfilActividad == 'C' || user.perfilActividad == 'c'){act[reg.actividad-1][2]++;}
    }
    for(int v=0; v<5; v++){
        int col=2;
        cout << setw(2) << v+1;
        cout << setw(col) << " ";
        cout << setw(11) << actividad[v];
        cout << setw(col) << " ";
        cout << setw(4) << act[v][0];
        cout << setw(col) << " ";
        cout << setw(4) << act[v][1];
        cout << setw(col) << " ";
        cout << setw(4) << act[v][2];
        cLinea(100,1);
    }
}
