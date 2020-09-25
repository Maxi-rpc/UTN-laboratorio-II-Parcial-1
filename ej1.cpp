#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;
#include <cstdio>
#include <ctime>
#include "funciones.h"
#include "strUsuario.h"
#include "entrenamiento.h"
#include "ui.h"
#include "ej1.h"
const char *FILEENTRENAMIENTO2 = "datos/archEntrenamiento.dat";

void reporteUno(){
    int con=0;
    int id, tam=0;
    int total = cantidadEntren();
    int vec[]={};
    bool vecEn[5];
    Entrenamiento reg;

    cout << "Ingresar ID Usuario a buscar: ";
    reg.idUsuario;
    id = reg.idUsuario;

    FILE *f = fopen(FILEENTRENAMIENTO2, "rb");
    if(f == NULL){
        cout << "No se puede leer el archivo.dat .";
    }
    for(tam=0; tam < total; tam++){
        fread(&reg, sizeof(Entrenamiento), 1, f);
        if(id == reg.idUsuario){
            con++;
            vec[con] = reg.actividad;
        }
    }

    /*for(int v=0; v < con; v++){
        vecEn[vec[v]] = false;
    }

    for(int u=0; u<5; u++){
        if(vecEn[u] == true){

        }
    }*/
    bool entren;
    int i;
    for(int v=0; v<con; v++){

        for(i=0; i<5; i++){
            if(vec[v] == i+1){
                entren = false;
            }

        }
        if(entren){
            cout << "Actividad no realizada" << i << endl;
        }
    }

    fclose(f);

}
