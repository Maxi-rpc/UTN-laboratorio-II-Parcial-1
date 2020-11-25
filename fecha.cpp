#include <iostream>
#include "ui.h"
#include "rlutil.h"
using namespace std;
#include "fecha.h"
#include "validar.h"
#include "cartel.h"
Fecha cargarFecha(){
    bool existe = false;
    int fut = 1;
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
        if(existe==false || fut == 1){
            cout << "*FECHA INCORRECTA, VOLVER A INGRESAR" << endl;
        }
    }
    return f;
}
