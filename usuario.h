#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include "fecha.h"
struct Usuario {
    int id;
    char nombres[50];
    char apellidos[50];
    Fecha nacimiento;
    float altura;
    float peso;
    char perfilActividad;
    bool aptoMedico;
    bool estado;
};

Usuario cargarDatos(); // Carga los datos de un user
void mostrarDatos(Usuario, int modo); // Muestra el reg de un user
bool guardarUsuario(Usuario); // Guarda el registro de un user dentro de usuario.dat
Usuario leerUsuario(int pos); // Lee el reg del usuario por la posicion
int buscarUsuario(int id); // Busca el usuario y devuelve la posicion
int cantidadUsuarios(); // Indica la cantidad total de usuarios registrados

#endif // USUARIO_H_INCLUDED
