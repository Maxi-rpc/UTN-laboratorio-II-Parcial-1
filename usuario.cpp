#include <iostream>
#include <string.h>
#include <iomanip>
#include "ui.h"
#include "rlutil.h"
using namespace std;
#include "usuario.h"
#include "cartel.h"
#include "validar.h"

Usuario cargarUsuario(){
    Usuario user;
    cout << "INGRESAR LOS SIGUIENTES DATOS" << endl;
    cout << "ID: ";
    user.id = validarIDUsuario();
    cin.ignore();
    cout << "NOMBRES: ";
    cin.getline(user.nombres,50);
    validarTextoSinespacios(user.nombres);
    cout << "APELLIDOS: ";
    cin.getline(user.apellidos,50);
    validarTextoSinespacios(user.apellidos);
    cout << "*FECHA DE NACIMIENTO: " << endl;
    user.nacimiento = cargarFecha(1);
    cout << "ALTURA: ";
    user.altura = validarNumReal();
    cout << "PESO: ";
    user.peso = validarNumReal();
    cout << "PERFIL DE ACTIVIDAD: ";
    user.perfilActividad = validarPerfilActividad();
    cout << "APTO MEDICO 1 / 0 : ";
    user.aptoMedico = validarAptoMedico();
    user.estado = true;

    return user;
}

void mostrarUsuario(Usuario user, int modo){
    if(modo == 0){
        cout << "ID: " << user.id << endl;
        cout << "NOMBRES: " << user.nombres << endl;
        cout << "APELLIDOS: " << user.apellidos << endl;
        cout << "FECHA DE NACIMIENTO: " << user.nacimiento.dia << "/" << user.nacimiento.mes << "/" << user.nacimiento.anio << endl;
        cout << "ALTURA: " << user.altura << endl;
        cout << "PESO: " << user.peso << endl;
        cout << "PERFIL DE ACTIVIDAD: " << user.perfilActividad << endl;
        cout << "APTO MEDICO: " << user.aptoMedico << endl;
        cout << "ESTADO: ";
        if(user.estado){cout << "ACTIVO";}
        else{cout << "INACTIVO";}
    }
    int col = 2;
    if(modo == 1){ //MODO 1 PARA USUARIO LISTAR
        int ancho1 = 13;
        cout << setw(4) << user.id;
        cout << setw(col) << " ";
        cout << setw(ancho1) << user.nombres;
        cout << setw(col) << " ";
        cout << setw(ancho1) << user.apellidos;
        cout << setw(col) << " ";
        cout << setw(3) << user.nacimiento.dia << setw(1) << "/" << setw(2)<< user.nacimiento.mes << setw(1) << "/" << setw(4) << user.nacimiento.anio;
        cout << setw(col) << " ";
        cout << setw(7) << user.altura;
        cout << setw(col) << " ";
        cout << setw(5) << user.peso;
        cout << setw(col) << " ";
        cout << setw(10) << user.perfilActividad;
        cout << setw(col) << " ";
        cout << setw(8) << user.aptoMedico;
        if(user.estado){cout << setw(9) << "ACTIVO";}
        else{cout << setw(9) << "INACTIVO";}
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
    mostrarUsuario(user,0);
    cout << endl;
    cLinea();
    cout << "INGRESAR OPCIÓN A MODIFICAR: " << endl;
    cout << "1) PESO" << endl;
    cout << "2) ACTIVIDAD" << endl;
    cout << "3) APTO MÉDICO" << endl;
    int opc;
    cin >> opc;
    switch(opc){
        case 1:
            cout << "NUEVO PESO: ";
            user.peso = validarNumReal();
        break;
        case 2:
            cout << "NUEVA ACTIVIDAD: ";
            user.perfilActividad = validarPerfilActividad();
        break;
        case 3:
            cout << "NUEVO APTO MÉDICO: ";
            user.aptoMedico = validarAptoMedico();
        break;
        default: cMsj(3);
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

Usuario elimUsuario(int pos){
    cout << "USUARIO A ELIMINAR: " << endl;
    cLinea();
    Usuario user = leerUsuario(pos);
    mostrarUsuario(user,0);
    cout << endl;
    cLinea();
    cout << "ELIMINAR USUARIO?" << endl;
    cout << "1) SI" << endl;
    cout << "2) NO" << endl;
    int opc;
    cin >> opc;
    switch(opc){
        case 1:
            user.estado = false;
        break;
        case 2:
            user.estado = true;
        break;
        default: cMsj(3);
        break;
    }
    return user;
}

bool copiaSeguridadUsuario(){
    Usuario user;
    FILE *f = fopen("datos/usuario.dat", "rb");
    FILE *backup = fopen("datos/usuario.bkp", "wb"); //Seteo a 0 el archivo de bk
    fclose(backup);
    if(f == NULL){
        cout << "No se puede leer usuario.dat .";
        system("pause");
        return false;
    }
    while(fread(&user, sizeof(Usuario), 1, f)){
        FILE *bk = fopen("datos/usuario.bkp", "ab");
        if(bk == NULL){
            cout << "No se puede guardar en usuario.bkp.";
            system("pause");
            return false;
        }
        fwrite(&user, sizeof(Usuario), 1, bk);
        fclose(bk);
    }
    fclose(f);
    return true;
}

bool recCopiaSeguridadUsuario(){
    Usuario user;
    FILE *bk = fopen("datos/usuario.bkp", "rb");
    FILE *orig = fopen("datos/usuario.dat", "wb"); //Seteo a 0 el archivo original
    fclose(orig);
    if(bk == NULL){
        cout << "No se puede leer el usuario.bkp .";
        system("pause");
        return false;
    }
    while(fread(&user, sizeof(Usuario), 1, bk)){
        FILE *f = fopen("datos/usuario.dat", "ab");
        if(f == NULL){
            cout << "No se puede guardar en usuario.dat.";
            system("pause");
            return false;
        }
        fwrite(&user, sizeof(Usuario), 1, f);
        fclose(f);
    }
    fclose(bk);
    return true;
}
