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
