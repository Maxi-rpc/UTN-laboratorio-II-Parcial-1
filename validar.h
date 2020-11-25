#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED

int validarIDUsuario(); // valida id POSITIVO, ENTERO, Y NO REPITE ID
char validarNombre();
char validarApellido();
bool validarFechaExistente(int dia , int mes , int anio);
int validarFechaFuturaPresentePasada(int dia , int mes , int anio);
float validarNumReal();

bool validarAptoMedico();

#endif // VALIDAR_H_INCLUDED
