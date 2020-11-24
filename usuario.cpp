#include <iostream>
#include <string.h>
#include "ui.h"
#include "rlutil.h"
using namespace std;
#include "usuario.h"
#include "cartel.h"

Usuario cargarDatos(){
    Usuario user;
    cout << "INGRESAR LOS SIGUIENTES DATOS:" << endl;
    cout << "ID: ";
    cin >> user.id;
    cout << "NOMBRES: ";
    cin >> user.nombres;
    cout << "APELLIDOS: ";
    cin >> user.apellidos;
    cout << "FECHA DE NACIMIENTO: " << endl;
    user.nacimiento = cargarFecha();
    cout << "ALTURA: ";
    cin >> user.altura;
    cout << "PESO: ";
    cin >> user.peso;
    cout << "PERFIL DE ACTIVIDAD: ";
    cin >> user.perfilActividad;
    cout << "APTO MEDICO 1 / 0 : ";
    cin >> user.aptoMedico;
    user.estado = true;

    return user;
}

void mostrarDatos(Usuario user, int modo){
    if(modo == 1){
        cout << "ID: " << user.id << endl;
        cout << "NOMBRES: " << user.nombres << endl;
        cout << "APELLIDOS: " << user.apellidos << endl;
        cout << "FECHA DE NACIMIENTO: " << user.nacimiento.dia << " / " << user.nacimiento.mes << " / " << user.nacimiento.anio << endl;
        cout << "ALTURA: " << user.altura << endl;
        cout << "PESO: " << user.peso << endl;
        cout << "PERFIL DE ACTIVIDAD: " << user.perfilActividad << endl;
        cout << "APTO MEDICO: " << user.aptoMedico << endl;
        cout << "ESTADO: ";
        if(user.estado){cout << "ACTIVO";}
        else{cout << "INACTIVO";}
    }

}

bool guardarUsuario(Usuario user){
    bool guardo;
    FILE *f = fopen("datos/usuario.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(&user, sizeof(Usuario), 1, f);
    fclose(f);
    return guardo;
}

Usuario leerUsuario(int pos){
    Usuario user;
    FILE *f = fopen("datos/usuario.dat", "rb");
    if(f == NULL){
        user.id = 0;
        return user;
    }
    fseek(f, pos *sizeof(Usuario), SEEK_SET);
    fread(&user, sizeof(Usuario), 1, f);
    fclose(f);
    return user;
}

int buscarUsuario(int id){
    int pos=0;
    Usuario user;
    FILE *f = fopen("datos/usuario.dat", "rb");
    if(f == NULL){
        cout << "No se puede leer el usuario.dat .";
        return -1;
    }
    while(fread(&user, sizeof(Usuario), 1, f)){
        if(id == user.id){
            fclose(f);
            return pos;
        }
        pos++;
    }
    fclose(f);
    return -1;
}

int cantidadUsuarios(){
    FILE *f = fopen("datos/usuario.dat", "rb");
    if(f == NULL){
        return 0;
    }
    int bytes, cant;
    fseek(f, 0, SEEK_END);
    bytes = ftell(f);
    fclose(f);
    cant = bytes / sizeof(Usuario);
    return cant;
}

Usuario modUsuario(int pos){
    cout << "USUARIO A MODIFICAR: " << endl;
    cLinea();
    Usuario user = leerUsuario(pos);
    mostrarDatos(user,1);
    cout << endl;
    cLinea();
    cout << "INGRESAR OPCI�N A MODIFICAR: " << endl;
    cout << "1) PESO" << endl;
    cout << "2) ACTIVIDAD" << endl;
    cout << "3) APTO M�DICO" << endl;
    int opc;
    cin >> opc;
    switch(opc){
        case 1:
            cout << "NUEVO PESO: ";
            cin >> user.peso;
        break;
        case 2:
            cout << "NUEVA ACTIVIDAD: ";
            cin >> user.perfilActividad;
        break;
        case 3:
            cout << "NUEVO APTO M�DICO: ";
            cin >> user.aptoMedico;
        break;
    }
    return user;
}

bool guardarModificacion(Usuario user, int pos){
    bool guardo;
    FILE *f = fopen("datos/usuario.dat", "rb+");
    if(f == NULL){
        cout << "No se puede modificar usuario.dat.";
        return false;
    }
    fseek(f, pos *sizeof(Usuario), SEEK_SET);
    guardo = fwrite(&user, sizeof(Usuario), 1, f);
    fclose(f);
    return guardo;
}
