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
    reg.idUsuario = validarUsuarioID();
    cout << "*FECHA DE ENTRENAMIENTO: " << endl;
    reg.diaEntrenamiento = cargarFecha(0);
    cout << "*ACTIVIDAD: " << endl;
    reg.actividad = validarActividad(reg.idUsuario);
    cout << "CALORÍAS: ";
    reg.calorias = validarNumReal();
    cout << "TIEMPO EN MINUTOS: ";
    reg.tiempo = validarNumEntero();

    return reg;
}

void mostrarEnt(Entrenamiento reg, int modo){
    string actividad[5] = {"CAMINATA","CORRER","BICICLETA","NATACIÓN","PESAS"};
    if(modo == 0){
        cout << "ID: " << reg.id << endl;
        cout << "ID USUARIO: " << reg.idUsuario << endl;
        cout << "FECHA DE ENTRENAMIENTO: " << reg.diaEntrenamiento.dia << "/" << reg.diaEntrenamiento.mes << "/" << reg.diaEntrenamiento.anio << endl;
        cout << "ACTIVIDAD: " << actividad[reg.actividad-1] << endl;
        cout << "CALORÍAS: " << reg.calorias << endl;
        cout << "TIEMPO: " << reg.tiempo << " Min" << endl;
    }
    int col = 2;
    if(modo == 1){ //MODO 1 PARA ENTRENAMIENTO LISTAR
        int ancho1 = 11;
        cout << setw(4) << reg.id;
        cout << setw(col) << " ";
        cout << setw(ancho1) << reg.idUsuario;
        cout << setw(col) << " ";
        cout << setw(3) << reg.diaEntrenamiento.dia << setw(1) << "/" << setw(2)<< reg.diaEntrenamiento.mes << setw(1) << "/" << setw(4) << reg.diaEntrenamiento.anio;
        cout << setw(col) << " ";
        cout << setw(10) << actividad[reg.actividad-1];
        cout << setw(col) << " ";
        cout << setw(9) << reg.calorias;
        cout << setw(col) << " ";
        cout << setw(7) << reg.tiempo;
    }

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
    mostrarEnt(reg,0);
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
            reg.tiempo = validarNumEntero();
        break;
        case 2:
            cout << "NUEVA CALORÍAS: ";
            reg.calorias = validarNumReal();
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
