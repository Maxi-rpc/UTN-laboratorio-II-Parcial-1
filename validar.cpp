#include <iostream>
#include <string.h>
#include <iomanip>
#include "ui.h"
#include "rlutil.h"
using namespace std;
#include "cartel.h"
#include "usuario.h"
#include "entrenamiento.h"
#include "validar.h"

/// VALIDAR USUARIO
int validarIDUsuario(){
    int id;
    while(!(cin >> id) || id < 0 || buscarUsuario(id) > 0){
        if(cin.fail()){
            cout << "INGRESAR SOLO NUMEROS" << endl;
        }
        if(id<0){
            cout << "INGRESAR NÚMERO POSITIVO" << endl;
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

void validarTextoSinespacios(char *texto){
    long int longitud;
    longitud = strlen(texto);

    while(texto[0] == ' ' || texto[longitud-1] == ' ' || longitud == 0){
        cout << "NO ESTA PERMITIDO INICIO VACIO" << endl;
        cin.getline(texto, 50);
        longitud = strlen(texto);
    }
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

bool validarEdad(int dia , int mes , int anio, int edad){
    bool resp = false;
    time_t tiempo;
    struct tm *tmPtr;
    tiempo=time(NULL);
    tmPtr=localtime(&tiempo);
    int diaActual = tmPtr->tm_mday;
    int mesActual = tmPtr->tm_mon + 1;
    int anioActual = 1900+tmPtr->tm_year;

    if(anioActual >= edad + anio){
        if(anioActual == edad + anio && mesActual >= mes && diaActual >= dia){resp = true;}
        if(anioActual == edad + anio && mesActual > mes){resp = true;}
        if(anioActual == edad + anio && mesActual < mes){resp = false;}
        if(anioActual == edad + anio && mesActual <= mes && diaActual < dia){resp = false;}
        if(anioActual > edad + anio){resp = true;}
    }else{resp = false;}

    return resp;
}

float validarNumReal(){
    float num;
    while(!(cin >> num) || num < 0){
        if(cin.fail()){
            cout << "INGRESAR SOLO NUMEROS" << endl;
        }
        if(num<0){
            cout << "INGRESAR NÚMERO POSITIVO" << endl;
        }
        cin.clear();
        cin.ignore(123, '\n');
        cout << "> ";
    }
    return num;
}

char validarPerfilActividad(){
    char perfil;
    cin >> perfil;
    while(perfil!='A' && perfil!='a' && perfil!='B' && perfil!='b' && perfil!='C' && perfil!='c'){
        cout << "INGRESAR UNA LETRA (A B C)" << endl;
        cin.clear();
        cin.ignore(123, '\n');
        cout << "> ";
        cin >> perfil;
    }
    if(perfil == 'A' || perfil == 'a'){return perfil;}
    if(perfil == 'B' || perfil == 'b'){return perfil;}
    if(perfil == 'C' || perfil == 'c'){return perfil;}
}

bool validarAptoMedico(){
    bool apto;
    int resp;
    while(!(cin >> resp) || resp > 1 || resp < 0){
        if(cin.fail()){
            cout << "INGRESAR NÚMERO UNO O CERO" << endl;
        }
        if(resp<0 || resp>1){
            cout << "INGRESAR NÚMERO UNO O CERO" << endl;
        }
        cin.clear();
        cin.ignore(123, '\n');
        cout << "> ";
    }
    if(resp == 0){apto = false;}
    if(resp == 1){apto = true;}
    return apto;
}

/// VALIDAR ENTRENAMIENTO
int validarEntID(){
    int id = cantidadEntren()+1;
    return id;
}

int validarUsuarioID(){
    int id;
    while(!(cin >> id) || id < 0 || buscarUsuario(id) < 0){
        if(cin.fail()){
            cout << "INGRESAR SOLO NUMEROS" << endl;
        }
        if(id<0){
            cout << "INGRESAR NÚMERO POSITIVO" << endl;
        }
        if(buscarUsuario(id)<0){
            cout << "ID NO EXISTE, INGRESAR ID VALIDO" << endl;
        }
        cin.clear();
        cin.ignore(123, '\n');
        cout << "> ";
    }
    return id;
}

int validarActividad(int id){
    string actividad[5] = {"CAMINATA","CORRER","BICICLETA","NATACIÓN","PESAS"};
    int act;
    bool apto = buscarApto(id);

    if(apto){
        cout << "1-CAMINATA 2-CORRER 3-BICICLETA 4-NATACIÓN 5-PESAS" << endl;
        while(!(cin >> act) || act > 5 || act < 1){
            if(act<1 || act>5){
                cout << "INGRESAR NÚMERO ENTRE 1 O 5" << endl;
            }
            cin.clear();
            cin.ignore(123, '\n');
            cout << "> ";
        }
    }else{
        cout << "1-CAMINATA 2-CORRER 3-BICICLETA" << endl;
        while(!(cin >> act) || act > 3 || act < 1){
            if(act<1 || act>3){
                cout << "INGRESAR NÚMERO ENTRE 1 O 3" << endl;
            }
            cin.clear();
            cin.ignore(123, '\n');
            cout << "> ";
        }
    }


    return act;
}

int validarNumEntero(){
    int num;
    while(!(cin >> num) || num < 1){
        if(cin.fail()){
            cout << "INGRESAR SOLO NUMEROS" << endl;
        }
        if(num<1){
            cout << "INGRESAR NÚMERO POSITIVO" << endl;
        }
        cin.clear();
        cin.ignore(123, '\n');
        cout << "> ";
    }
    return num;
}

bool buscarApto(int id){
    bool apto;
    int pos = buscarUsuario(id);
    Usuario user = leerUsuario(pos);
    apto = user.aptoMedico;
    return apto;
}
