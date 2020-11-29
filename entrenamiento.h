#ifndef ENTRENAMIENTO_H_INCLUDED
#define ENTRENAMIENTO_H_INCLUDED
#include "fecha.h"
#include "usuario.h"
struct Entrenamiento{
    int id; // autonumerico
    int idUsuario;
    Fecha diaEntrenamiento;
    int actividad; //1 - Caminata, 2 - Correr, 3 - Bicicleta, 4 - Natación y 5 - Pesas
    float calorias;
    int tiempo;
};

Entrenamiento cargarEntrenamiento();
void mostrarEnt(Entrenamiento, int modo);
bool guardarEntren(Entrenamiento); // Guarda el registro de ENTRENAMIENTO dentro de entrenamiento.dat
Entrenamiento leerEntren(int pos); //lee el archivo y devuelve un reg
int buscarEnt(int id); // Busca el entrenamiento ID y devuelve la posicion
int cantidadEntren(); // Indica la cantidad total de entrenamientos registrados
Entrenamiento modificarEnt(int pos); // Modifica entrenamiento
bool guardarModificacionEnt(Entrenamiento, int pos); // Guarda el reg en la pos del entrenamiento
bool copiaSeguridadEnt(); // crea una copia de entrenamiento.dat
bool recCopiaSeguridadEnt(); // restaura la copia .bkp a .dat
#endif // ENTRENAMIENTO_H_INCLUDED
