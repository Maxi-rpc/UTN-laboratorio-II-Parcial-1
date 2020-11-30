#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED
/// VALIDAR USUARIO
int validarIDUsuario(); // Valida id POSITIVO, ENTERO, Y NO REPITE ID
void validarTextoSinespacios(char *texto); // Valida que el texto ingresado sea sin espacios al principio o vacio
bool validarFechaExistente(int dia , int mes , int anio); // Devuelve si existe o no
int validarFechaFuturaPresentePasada(int dia , int mes , int anio); // Devuelve fecha pasada, presente o futuro
bool validarEdad(int dia , int mes , int anio, int edad); // devuelve si es menor o mayor
float validarNumReal(); // Valida numero real
char validarPerfilActividad(); // Valida que ingrese la letra A,B o C, mayuscula o minuscula
bool validarAptoMedico(); // Valida true o false mediante un numero
/// VALIDAR ENTRENAMIENTO
int validarEntID(); // valida que sea un numero unico autonumerico
int validarUsuarioID(); // busca el id de usuario en usuario.dat y lo trae si es correcto
int validarActividad(int id); // Valida si es un numero entero entre 1,5 y que el usuario tenga apto medico
int validarNumEntero(); // Valida si el ingreso es un numero entero positivo
bool buscarApto(int id); // Valida si es Apto para su actividad
#endif // VALIDAR_H_INCLUDED
