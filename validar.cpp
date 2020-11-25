#include <iostream>
#include <string.h>
#include <iomanip>
#include "ui.h"
#include "rlutil.h"
using namespace std;
#include "cartel.h"
#include "usuario.h"

int validarIDUsuario(){
    int id;
    while(!(cin >> id) || id < 0 || buscarUsuario(id) > 0){
        if(cin.fail()){
            cout << "INGRESAR SOLO NUMEROS" << endl;
        }
        if(id<0){
            cout << "INGRESAR NUMERO POSITIVO" << endl;
        }
        if(buscarUsuario(id)>0){
            cout << "ID YA EXISTE" << endl;
        }
        cin.clear();
        cin.ignore(123, '\n');
        cout << "> ";
    }
    return id;
}

char validarNombre(){

}

char validarApellido(){

}

bool validarFechaExistente(int dia , int mes , int anio){
    bool bisiesto=false;
    int cantidadDias;
    //A�o bisiesto
    if(anio%4==0){
        if(anio%100==0){
            if(anio%400==0){bisiesto=true;}
        }
        else{bisiesto=true;}
    }
    //Cantidad de d�as
    if(mes==2){
        if(bisiesto){cantidadDias=29;}
        else{cantidadDias=28;}
    }
    else{
        if(mes==4||mes==6||mes==9||mes==11){cantidadDias=30;}
        else{cantidadDias=31;}
    }
    //Validaci�n
    if(anio<0){return false;}
    if(mes<1||mes>12){return false;}
    if(dia<1||dia>cantidadDias){return false;}
    return true;
}

int validarFechaFuturaPresentePasada(int dia , int mes , int anio){
    //Devuelve 0 si es la fecha actual, 1 si es fecha futura y -1 se es fecha pasada
    tm *date;
    time_t marcaDeTiempo;
    marcaDeTiempo=time(NULL);
    date=localtime(&marcaDeTiempo);
    if(anio>date->tm_year+1900){return 1;}
    if(anio<date->tm_year+1900){return -1;}
    if(mes>date->tm_mon+1){return 1;}
    if(mes<date->tm_mon+1){return -1;}
    if(dia>date->tm_mday){return 1;}
    if(dia<date->tm_mday){return -1;}
    return 0;
}

float validarNumReal(){
    float altura;
    while(!(cin >> altura) || altura < 0){
        if(cin.fail()){
            cout << "INGRESAR SOLO NUMEROS" << endl;
        }
        if(altura<0){
            cout << "INGRESAR NUMERO POSITIVO" << endl;
        }
        cin.clear();
        cin.ignore(123, '\n');
        cout << "> ";
    }
    return altura;
}

