#include <iostream>
#include "ui.h"
#include "rlutil.h"
using namespace std;
#include "fecha.h"

Fecha cargarFecha(){
    Fecha f;
    cout << "INGRESAR DIA: ";
    cin >> f.dia;
    cout << "INGRESAR MES: ";
    cin >> f.mes;
    cout << "INGRESAR AÑO: ";
    cin >> f.anio;

    return f;
}

bool validarFechaExistente(int dia , int mes , int anio){
    bool bisiesto=false;
    int cantidadDias;
    //Año bisiesto
    if(anio%4==0){
        if(anio%100==0){
            if(anio%400==0){bisiesto=true;}
        }
        else{bisiesto=true;}
    }
    //Cantidad de días
    if(mes==2){
        if(bisiesto){cantidadDias=29;}
        else{cantidadDias=28;}
    }
    else{
        if(mes==4||mes==6||mes==9||mes==11){cantidadDias=30;}
        else{cantidadDias=31;}
    }
    //Validación
    if(anio<0){return false;}
    if(mes<1||mes>12){return false;}
    if(dia<1||dia>cantidadDias){return false;}
    return true;
}
