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
// PROFE POR FAVOR VER CONFIGURACION Y BACKUP PORQUE HICE UNA ANIMACION COPADA JAJA

void recPuntoUno(){
    cTitulo("RECUPERATORIO PUNTO UNO");
    cout << "*Listar todos los usuarios cuya altura supere la altura promedio de los usuarios de perfil 'B'." << endl;
    cout << endl;
    float promedio = promAlturaB();
    cout << "PROMEDIO DE ALTURA DE LOS PERFILES B: " << promedio << endl;
    cout << endl;
    listarRecPunto1();
    int cant = cantidadUsuarios(), col=2;
    for(int i=0; i<cant; i++){
        Usuario user = leerUsuario(i);
        if(user.altura > promedio){
            cout << setw(4) << user.id;
            cout << setw(col) << " ";
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

void listarRecPunto1(){
    int col = 2;
    cout << setw(4) << "ID";
    cout << setw(col) << " ";
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
    cout << "*Listar apellidos y nombres del usuario que más tiempo en promedio haya entrenado." << endl;
    cout << endl;
    int id = mayorTiempoPromedio(), col=2;
    int prom = promedioTiempo(id);
    listarRecPunto2();
    int pos = buscarUsuario(id);
    Usuario reg = leerUsuario(pos);
    cout << setw(15) << reg.apellidos;
    cout << setw(col) << " ";
    cout << setw(15) << reg.nombres;
    cout << setw(col) << " ";
    cout << setw(9) << prom;
    cLinea(100,1);
    cMsj(6); // ELIMINAR SI NO ES NECESARIO
}

void listarRecPunto2(){
    int col = 2;
    cout << setw(15) << "APELLIDOS";
    cout << setw(col) << " ";
    cout << setw(15) << "NOMBRES";
    cout << setw(col) << " ";
    cout << setw(9) << "PROMEDIO";
    cLinea(100,1);
}

int mayorTiempoPromedio(){
    int mayProm = 0, prom=0, cantEnt = cantidadEntren();
    int id=0;
    Entrenamiento reg;
    for(int i=0; i<cantEnt; i++){
        reg = leerEntren(i);
        prom = promedioTiempo(reg.idUsuario);
        if(prom > mayProm){
            mayProm = prom;
            id = reg.idUsuario;
        }
    }
    return id;
}

int promedioTiempo(int id){
    int canEn = cantidadEntren(), total=0, prom=0;
    for(int i=0; i<canEn; i++){
        Entrenamiento reg = leerEntren(i);
        if(reg.idUsuario == id){
            total++;
            prom += reg.tiempo;
        }
    }
    prom = prom / total;
    return prom;
}

