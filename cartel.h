#ifndef CARTEL_H_INCLUDED
#define CARTEL_H_INCLUDED

// PREDETERMINADOS
void cTitulo(char *titulo); // Titulo dinamico
void gotoXYPred(int x=1, int y=3); // Predeterminar x e y
void cLinea(int cantidad=10, int modo=0); // Cartel DIBUJA UNA LINEA DETERMINADA
void cMsj(int modo); // MSJ DINAMICO
// MENU
void cMenu();
void cMenuUsuario();
void cMenuEntrenamiento();
void cMenuConfiguracion();
// LISTAR
void cListar(int modo);
#endif // CARTEL_H_INCLUDED
