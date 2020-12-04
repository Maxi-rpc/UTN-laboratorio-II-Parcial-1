#include <iostream>
#include <windows.h> ///Para funciones system
#include <time.h> /// para la funcion TIME
#include "ui.h"
#include "rlutil.h"
using namespace std;
#include "menu.h"
#include "cartel.h"
#include "validar.h"
// STRUCT
#include "usuario.h"
#include "entrenamiento.h"
// RECUPERATORIO PARCIAL LAB II 3/12/2020
#include "recup1.h"

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
    bool menu = true;
    int opc;
    while(menu){
        cMenuEntrenamiento();
        while(!(cin >> opc)){
            cMsj(3);
            cin.clear();
            cin.ignore(123, '\n');
            cMenuEntrenamiento();
        }
        switch(opc){
            case 1:
                crearEntrenamiento();
            break;
            case 2:
                modificarEntrenamiento();
            break;
            case 3:
                listarEntrenamientoPorID();
            break;
            case 4:
                listarEntrenamientoPorIDUsuario();
            break;
            case 5:
                listarTodoLosEntrenamientos();
            break;
            case 0:
                menu = false;
            break;
            default: cMsj(3);
            break;
        }
    }
}

void menuReporte(){
    bool menu = true;
    int opc;
    while(menu){
        cMenuReporte();
        while(!(cin >> opc)){
            cMsj(3);
            cin.clear();
            cin.ignore(123, '\n');
            cMenuReporte();
        }
        switch(opc){
            case 1:
                recPuntoUno();
            break;
            case 2:
                recPuntoDos();
            break;
            case 0:
                menu = false;
            break;
            default: cMsj(3);
            break;
        }
    }
}

void menuConfiguracion(){
    bool menu = true;
    int opc;
    while(menu){
        cMenuConfiguracion();
        while(!(cin >> opc)){
            cMsj(3);
            cin.clear();
            cin.ignore(123, '\n');
            cMenuConfiguracion();
        }
        switch(opc){
            case 1:
                realizarCopSeguridad();
            break;
            case 2:
                recupCopSeguridad();
            break;
            case 0:
                menu = false;
            break;
            default: cMsj(3);
            break;
        }
    }
}

// SUB MENU USUARIO
void crearUsuario(){
    cTitulo("NUEVO USUARIO");
    Usuario u = cargarUsuario();
    if(guardarUsuario(u)){cMsj(1);}
    else {cMsj(2);}
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
            mostrarUsuario(user,0);
            cMsj(6);
        }else{cMsj(7);}
    }else {cMsj(4);}
}

void listarTodoLosUsuarios(){
    int cant = cantidadUsuarios();
    cTitulo("LISTAR TODO LOS USUARIOS");
    cListar(1); // MODO 1 USUARIO
    for(int i=0; i<cant; i++){
        Usuario user = leerUsuario(i);
        mostrarUsuario(user,1);
        cLinea(100,1);
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

// SUB MENU ENTRENAMIENTO
void crearEntrenamiento(){
    cTitulo("CREAR ENTRENAMIENTO");
    Entrenamiento reg = cargarEntrenamiento();
    if(guardarEntren(reg)){cMsj(1);}
    else{cMsj(2);}
}

void modificarEntrenamiento(){
    int id, pos;
    cTitulo("MODIFICAR ENTRENAMIENTO");
    cout << "INGRESAR ID: ";
    cin >> id;
    pos = buscarEnt(id);
    if(pos >= 0){
        Entrenamiento reg = modificarEnt(pos);
        if(guardarModificacionEnt(reg, pos)){cMsj(1);}
        else{cMsj(2);}
    } else {cMsj(4);}
}

void listarEntrenamientoPorID(){
    int id, pos;
    cTitulo("LISTAR ENTRENAMIENTO POR ID");
    cout << "INGRESAR ID: ";
    cin >> id;
    pos = buscarEnt(id);
    if(pos >= 0){
        Entrenamiento reg = leerEntren(pos);
        mostrarEnt(reg,0);
        cMsj(6);
    }else {cMsj(4);}
}

void listarEntrenamientoPorIDUsuario(){
    int id, pos, existe;
    int cant = cantidadEntren();
    cTitulo("LISTAR ENTRENAMIENTO POR ID USUARIO");
    cout << "INGRESAR ID: ";
    cin >> id;
    existe = buscarUsuario(id);
    if(existe >= 0){
        for(int i=0; i<cant; i++){
            Entrenamiento reg = leerEntren(i);
            if(id == reg.idUsuario){
                mostrarEnt(reg,1);
                cLinea(100,1);
            }
        }
        cMsj(6);
    }else{cMsj(4);}
}

void listarTodoLosEntrenamientos(){
    int cant = cantidadEntren();
    cTitulo("LISTAR TODO LOS ENTRENAMIENTOS");
    cListar(2); //MODO 2 PARA ENTRENAMIENTO
    for(int i=0; i<cant; i++){
        Entrenamiento reg = leerEntren(i);
        mostrarEnt(reg,1);
        cLinea(100,1);
    }
    cMsj(6);
}

// SUB MENU CONFIGURACION
void realizarCopSeguridad(){
    srand(time(NULL));
    int exito = 0, numR = rand(), conf=0;
    cTitulo("REALIZAR COPIA DE SEGURIDAD");
    cout << "INGRESE EL SIGUIENTE PIN " << numR << endl;
    cin >> conf;
    if(conf == numR){
        exito += copiaSeguridadUsuario();
        exito += copiaSeguridadEnt();
        if(exito == 2){
            cBarraProgreso();
            cMsj(8);
        }
        else{cMsj(9);}
    }else{cMsj(12);}
}

void recupCopSeguridad(){
    srand(time(NULL));
    int exito = 0, numR = rand(), conf=0;
    cTitulo("RESTAURAR COPIA DE SEGURIDAD");
    cout << "INGRESE EL SIGUIENTE PIN " << numR << endl;
    cin >> conf;
    if(conf == numR){
        exito += recCopiaSeguridadUsuario();
        exito += recCopiaSeguridadEnt();
        if(exito == 2){
            cBarraProgreso();
            cMsj(10);
        }
        else{cMsj(11);}
    }else{cMsj(12);}
}

