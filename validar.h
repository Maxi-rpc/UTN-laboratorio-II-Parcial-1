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
int validarEntID(); // valida que sea un numero unico autonumerico
int validarUsuarioID(); // busca el id de usuario en usuario.dat y lo trae si es correcto
int validarActividad(); // Valida si es un numero entero entre 1 y 5

#endif // VALIDAR_H_INCLUDED
