#include <iostream>
#include <string.h>
#include <iomanip>
#include "ui.h"
#include "rlutil.h"
using namespace std;
#include "entrenamiento.h"
#include "cartel.h"

Entrenamiento cargarEntrenamiento(){
    Entrenamiento reg;
    reg.id = cantidadEntren()+1;
    cout << "ID: " << reg.id << endl;
    cout << "INGRESAR LOS SIGUIENTES DATOS" << endl;
    cout << "ID USUARIO: ";
    cin >> reg.idUsuario;
    cout << "FECHA DE ENTRENAMIENTO: ";
    reg.diaEntrenamiento = cargarFecha();
    cout << "ACTIVIDAD: ";
    cin >> reg.actividad;
    cout << "CALORÍAS: ";
    cin >> reg.calorias;
    cout << "TIEMPO EN MINUTOS: ";
    cin >> reg.tiempo;

    return reg;
}

void mostrarEnt(Entrenamiento reg){
    cout << "ID: " << reg.id << endl;
    cout << "ID USUARIO: " << reg.idUsuario << endl;
    cout << "FECHA DE ENTRENAMIENTO: " << reg.diaEntrenamiento.dia << " / " << reg.diaEntrenamiento.mes << " / " << reg.diaEntrenamiento.anio << endl;
    switch(reg.actividad){
        case 1: cout << "Actividad: Caminata" << endl;
        break;
        case 2: cout << "Actividad: Correr" << endl;
        break;
        case 3: cout << "Actividad: Bicicleta" << endl;
        break;
        case 4: cout << "Actividad: Natacion" << endl;
        break;
        case 5: cout << "Actividad: Pesas" << endl;
        break;
    }
    cout << "Calorias: " << reg.calorias << endl;
    cout << "Tiempo: " << reg.tiempo << " Min" << endl;
}

bool guardarEntren(Entrenamiento reg){
    bool guardo;
    FILE *f = fopen("datos/entrenamiento.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(&reg, sizeof(Entrenamiento), 1, f);
    fclose(f);
    return guardo;
}

int cantidadEntren(){
    FILE *f = fopen("datos/entrenamiento.dat", "rb");
    if(f == NULL){
        fclose(f);
        return 0;
    }
    int bytes, cant;
    fseek(f, 0, SEEK_END);
    bytes = ftell(f);
    fclose(f);
    cant = bytes / sizeof(Entrenamiento);
    return cant;
}

