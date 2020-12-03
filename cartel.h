#ifndef CARTEL_H_INCLUDED
#define CARTEL_H_INCLUDED

// PREDETERMINADOS
void cTitulo(char *titulo); // Titulo dinamico
void gotoXYPred(int x=1, int y=3); // Predeterminar x e y
void cLinea(int cantidad=20, int modo=0); // Cartel DIBUJA UNA LINEA DETERMINADA
void cMsj(int modo); // MSJ DINAMICO
void cBarraProgreso(); // Barra de progreso
// MENU
void cMenu(); // Cartel Menu Principal
void cMenuUsuario(); // Cartel Menu Usuario
void cMenuEntrenamiento(); // Cartel Menu Entrenamiento
void cMenuConfiguracion(); // Cartel Menu Configuracion
void cMenuReporte(); // Cartel Menu Reportes
// LISTAR
void cListar(int modo);

#endif // CARTEL_H_INCLUDED

