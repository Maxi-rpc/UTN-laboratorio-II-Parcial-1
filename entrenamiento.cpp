#include <iostream>
#include <string.h>
#include <iomanip>
#include "ui.h"
#include "rlutil.h"
using namespace std;
#include "entrenamiento.h"
#include "cartel.h"
#include "validar.h"

Entrenamiento cargarEntrenamiento(){
    Entrenamiento reg;
    reg.id = validarEntID();
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

int buscarEnt(int id){
    int pos=0;
    Entrenamiento reg;
    FILE *f = fopen("datos/entrenamiento.dat", "rb");
    if(f == NULL){
        cout << "No se puede leer el entrenamiento.dat.";
        return -1;
    }
    while(fread(&reg, sizeof(Entrenamiento), 1, f)){
        if(id == reg.id){
            fclose(f);
            return pos;
        }
        pos++;
    }
    fclose(f);
    return -1;
}

Entrenamiento leerEntren(int pos){
    Entrenamiento reg;
    FILE *f = fopen("datos/entrenamiento.dat", "rb");
    if(f == NULL){
        reg.id = 0;
        return reg;
    }
    fseek(f, pos *sizeof(Entrenamiento), SEEK_SET);
    fread(&reg, sizeof(Entrenamiento), 1, f);
    fclose(f);
    return reg;
}

Entrenamiento modificarEnt(int pos){
    cout << "ENTRENAMIENTO A MODIFICAR: " << endl;
    cLinea();
    Entrenamiento reg = leerEntren(pos);
    mostrarEnt(reg);
    cout << endl;
    cLinea();
    cout << "INGRESAR OPCIÓN A MODIFICAR: " << endl;
    cout << "1) TIEMPO" << endl;
    cout << "2) CALORÍAS" << endl;
    int opc;
    cin >> opc;
    switch(opc){
        case 1:
            cout << "NUEVO TIEMPO: ";
            cin >> reg.tiempo;
        break;
        case 2:
            cout << "NUEVA CALORÍAS: ";
            cin >> reg.calorias;
        break;
        default: cMsj(3);
        break;
    }
    return reg;
}

bool guardarModificacionEnt(Entrenamiento reg, int pos){
    bool guardo;
    FILE *f = fopen("datos/entrenamiento.dat", "rb+");
    if(f == NULL){
        cout << "No se puede modificar.";
        return false;
    }
    fseek(f, pos *sizeof(Entrenamiento), SEEK_SET);
    guardo = fwrite(&reg, sizeof(Entrenamiento), 1, f);
    fclose(f);
    return guardo;
}

bool copiaSeguridadEnt(){
    Entrenamiento reg;
    FILE *f = fopen("datos/entrenamiento.dat", "rb");
    FILE *backup = fopen("datos/entrenamiento.bkp", "wb"); //Seteo a 0 el archivo de bk
    fclose(backup);
    if(f == NULL){
        cout << "No se puede leer entrenamiento.dat .";
        system("pause");
        return false;
    }
    while(fread(&reg, sizeof(Entrenamiento), 1, f)){
        FILE *bk = fopen("datos/entrenamiento.bkp", "ab");
        if(bk == NULL){
            cout << "No se puede guardar en entrenamiento.bkp.";
            system("pause");
            return false;
        }
        fwrite(&reg, sizeof(Entrenamiento), 1, bk);
        fclose(bk);
    }
    fclose(f);
    return true;
}

bool recCopiaSeguridadEnt(){
    Entrenamiento reg;
    FILE *bk = fopen("datos/entrenamiento.bkp", "rb");
    FILE *orig = fopen("datos/entrenamiento.dat", "wb"); //Seteo a 0 el archivo original
    fclose(orig);
    if(bk == NULL){
        cout << "No se puede leer el entrenamiento.bkp .";
        system("pause");
        return false;
    }
    while(fread(&reg, sizeof(Entrenamiento), 1, bk)){
        FILE *f = fopen("datos/entrenamiento.dat", "ab");
        if(f == NULL){
            cout << "No se puede guardar en entrenamiento.dat.";
            system("pause");
            return false;
        }
        fwrite(&reg, sizeof(Entrenamiento), 1, f);
        fclose(f);
    }
    fclose(bk);
    return true;
}
