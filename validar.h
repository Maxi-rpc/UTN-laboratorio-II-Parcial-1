#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED
/// VALIDAR USUARIO
int validarIDUsuario(); // Valida id POSITIVO, ENTERO, Y NO REPITE ID
char validarNombre();
char validarApellido();
bool validarFechaExistente(int dia , int mes , int anio); // Devuelve si existe o no
int validarFechaFuturaPresentePasada(int dia , int mes , int anio); // Devuelve fecha pasada, presente o futuro
float validarNumReal(); // Valida numero real
char validarPerfilActividad(); // Valida que ingrese la letra A,B o C, mayuscula o minuscula
bool validarAptoMedico(); // Valida true o false mediante un numero
/// VALIDAR ENTRENAMIENTO

#endif // VALIDAR_H_INCLUDED
