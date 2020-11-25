#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED

int validarIDUsuario(); // Valida id POSITIVO, ENTERO, Y NO REPITE ID
char validarNombre();
char validarApellido();
bool validarFechaExistente(int dia , int mes , int anio); // Devuelve si existe o no
int validarFechaFuturaPresentePasada(int dia , int mes , int anio); // Devuelve fecha pasada, presente o futuro
float validarNumReal(); // Valida numero real
char validarPerfilActividad(); //
bool validarAptoMedico(); // Valida true o false mediante un numero

#endif // VALIDAR_H_INCLUDED
