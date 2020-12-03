#include <iostream>
#include <windows.h>
#include "ui.h"
#include "rlutil.h"
#include <stdio.h>
#include <string.h>
using namespace std;
#include <iomanip>
#include "cartel.h"
#include "fecha.h"
#include "usuario.h"
#include "entrenamiento.h"

#include "recup1.h"

void recPuntoUno(){
    cTitulo("RECUPERATORIO PUNTO UNO");
    cout << "*Listar todos los usuarios cuya altura supere la altura promedio de los usuarios de perfil 'B'." << endl;
    cout << endl;
    listarPunto1();
    float promedio = promAlturaB();
    int cant = cantidadUsuarios(), col=2;
    for(int i=0; i<cant; i++){
        Usuario user = leerUsuario(i);
        if(user.altura > promedio){
            cout << setw(15) << user.nombres;
            cout << setw(col) << " ";
            cout << setw(15) << user.apellidos;
            cout << setw(col) << " ";
            cout << setw(9) << user.altura;
            cLinea(100,1);
        }
    }
    cMsj(6); // ELIMINAR SI NO ES NECESARIO
}

void listarPunto1(){
    int col = 2;
    cout << setw(15) << "NOMBRES";
    cout << setw(col) << " ";
    cout << setw(15) << "APELLIDOS";
    cout << setw(col) << " ";
    cout << setw(9) << "ALTURA";
    cLinea(100,1);
}

float promAlturaB(){
    float promedio=0;
    int total=0;
    int cant = cantidadUsuarios();
    for(int i=0; i<cant; i++){
        Usuario user = leerUsuario(i);
        if(user.perfilActividad == 'B' || user.perfilActividad == 'b'){
            total++;
            promedio += user.altura;
        }
    }
    promedio /=  total;
    return promedio;
}

void recPuntoDos(){
    cTitulo("RECUPERATORIO PUNTO DOS");
    cout << "*CONSIGNA" << endl;

    cMsj(6); // ELIMINAR SI NO ES NECESARIO
}
