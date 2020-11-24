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
void mostrarEnt(Entrenamiento);
bool guardarEntren(Entrenamiento); // Guarda el registro de ENTRENAMIENTO dentro de entrenamiento.dat

int cantidadEntren(); // Indica la cantidad total de entrenamientos registrados

#endif // ENTRENAMIENTO_H_INCLUDED
