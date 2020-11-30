#include <iostream>
#include "ui.h"
#include "rlutil.h"
using namespace std;
#include "fecha.h"
#include "validar.h"
#include "cartel.h"

Fecha cargarFecha(int modo){
    bool existe = false, mayor;
    int fut = 1, edad = 13;
    Fecha f;
    while(existe == false || fut == 1){
        cout << "INGRESAR DIA: ";
        cin >> f.dia;
        cout << "INGRESAR MES: ";
        cin >> f.mes;
        cout << "INGRESAR AÑO: ";
        cin >> f.anio;
        existe = validarFechaExistente(f.dia, f.mes, f.anio);
        fut = validarFechaFuturaPresentePasada(f.dia, f.mes, f.anio);
        if(modo == 1 && fut == -1){
            mayor  = validarEdad(f.dia , f.mes , f.anio, edad);
            if(mayor == false){existe=false;}
        }
        if(existe==false || fut == 1){
            if(mayor==false){cout << "DEBE SER MAYOR A "<< edad << " AÑOS DE EDAD"<<endl;}
            else{cout << "*FECHA INCORRECTA, VOLVER A INGRESAR" << endl;}
        }
    }
    return f;
}
