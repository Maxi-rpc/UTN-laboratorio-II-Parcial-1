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

Usuario cargarUsuario(); // Carga los datos de un user
void mostrarUsuario(Usuario, int modo); // Muestra el reg de un user
bool guardarUsuario(Usuario); // Guarda el registro de un user dentro de usuario.dat
Usuario leerUsuario(int pos); // Lee el reg del usuario por la posicion
int buscarUsuario(int id); // Busca el usuario y devuelve la posicion
int cantidadUsuarios(); // Indica la cantidad total de usuarios registrados
Usuario modUsuario(int pos); // Modifica un usuario
bool guardarModificacion(Usuario, int pos); // Guarda las modificaciones en la pos del usuario
Usuario elimUsuario(int pos); // Elimina un usuario
bool copiaSeguridadUsuario(); // crea una copia de usuario.dat
bool recCopiaSeguridadUsuario(); // restaura la copia .bkp a .dat
#endif // USUARIO_H_INCLUDED

