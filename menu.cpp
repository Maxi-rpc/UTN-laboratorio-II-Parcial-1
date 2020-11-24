#include <iostream>
#include <windows.h> ///Para funciones system
#include "ui.h"
#include "rlutil.h"
using namespace std;
#include "menu.h"
#include "cartel.h"
// STRUCT
#include "usuario.h"

void menuPrincipal(){
    bool menu = true;
    int opc;
    while(menu){
        cMenu();
        while(!(cin >> opc)){
            cMsj(3);
            cin.clear();
            cin.ignore(123, '\n');
            cMenu();
        }
        switch(opc){
            case 1:
                menuUsuario();
            break;
            case 2:
                menuEntrenamiento();
            break;
            case 3:
                menuReporte();
            break;
            case 4:
                menuConfiguracion();
            break;
            case 0:
                menu = false;
            break;
            default: cMsj(3);
            break;
        }
    }
}

void menuUsuario(){
    bool menu = true;
    int opc;
    while(menu){
        cMenuUsuario();
        while(!(cin >> opc)){
            cMsj(3);
            cin.clear();
            cin.ignore(123, '\n');
            cMenuUsuario();
        }
        switch(opc){
            case 1:
                crearUsuario();
            break;
            case 2:
                modificarUsuario();
            break;
            case 3:
                listarUsuarioPorID();
            break;
            case 4:
                listarTodoLosUsuarios();
            break;
            case 5:
                eliminarUsuario();
            break;
            case 0:
                menu = false;
            break;
            default: cMsj(3);
            break;
        }
    }
}

void menuEntrenamiento(){

}

void menuReporte(){

}

void menuConfiguracion(){

}

// SUB MENU USUARIO
void crearUsuario(){
    cTitulo("NUEVO USUARIO");
    Usuario u = cargarUsuario();
    if(guardarUsuario(u)){
        cMsj(1);
    } else {
        cMsj(2);
    }
}

void modificarUsuario(){
    int id, pos;
    cTitulo("MODIFICAR USUARIO");
    cout << "INGRESAR ID: ";
    cin >> id;
    pos = buscarUsuario(id);
    if(pos >= 0){
        Usuario user = modUsuario(pos);
        if(guardarModificacion(user, pos)){cMsj(1);}
        else{cMsj(2);}
    } else {cMsj(4);}
}

void listarUsuarioPorID(){
    int id, pos;
    cTitulo("LISTAR USUARIO POR ID");
    cout << "INGRESAR ID: ";
    cin >> id;
    pos = buscarUsuario(id);
    if(pos >= 0){
        Usuario user = leerUsuario(pos);
        if(user.estado == true){
            mostrarUsuario(user,1);
            cMsj(6);
        }else{cMsj(7);}
    }else {cMsj(4);}
}

void listarTodoLosUsuarios(){
    int cant = cantidadUsuarios();
    cTitulo("LISTAR TODO LOS USUARIOS");
    for(int i=0; i<cant; i++){
        Usuario user = leerUsuario(i);
        mostrarUsuario(user,1);
        cout << endl;
        cLinea();
    }
    cMsj(6);
}

void eliminarUsuario(){
    int id, pos;
    cTitulo("ELIMINAR USUARIO");
    cout << "INGRESAR ID: ";
    cin >> id;
    pos = buscarUsuario(id);
    if(pos >= 0){
        Usuario user = elimUsuario(pos);
        if(guardarModificacion(user, pos)){cMsj(1);}
        else{cMsj(2);}
    } else {cMsj(4);}
}


