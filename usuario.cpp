#include <iostream>
#include <string.h>
#include "ui.h"
#include "rlutil.h"
using namespace std;
#include "usuario.h"

Usuario cargarDatos(){
    Usuario u;
    cout << "INGRESAR LOS SIGUIENTES DATOS:" << endl;
    cout << "ID: ";
    cin >> u.id;
    cout << "NOMBRES: ";
    cin >> u.nombres;
    cout << "APELLIDOS: ";
    cin >> u.apellidos;
    cout << "FECHA DE NACIMIENTO: " << endl;
    u.nacimiento = cargarFecha();
    cout << "ALTURA: ";
    cin >> u.altura;
    cout << "PESO: ";
    cin >> u.peso;
    cout << "PERFIL DE ACTIVIDAD: ";
    cin >> u.perfilActividad;
    cout << "APTO MEDICO 1 / 0 : ";
    cin >> u.aptoMedico;
    u.estado = true;

    return u;
}

void mostrarDatos(Usuario u, int modo){
    if(modo == 1){
        cout << "ID: " << u.id << endl;
        cout << "NOMBRES: " << u.nombres << endl;
        cout << "APELLIDOS: " << u.apellidos << endl;
        cout << "FECHA DE NACIMIENTO: " << u.nacimiento.dia << " / " << u.nacimiento.mes << " / " << u.nacimiento.anio << endl;
        cout << "ALTURA: " << u.altura << endl;
        cout << "PESO: " << u.peso << endl;
        cout << "PERFIL DE ACTIVIDAD: " << u.perfilActividad << endl;
        cout << "APTO MEDICO: " << u.aptoMedico << endl;
        cout << "ESTADO: ";
        if(u.estado){cout << "ACTIVO";}
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
