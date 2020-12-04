#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menuPrincipal();
// SUB MENUS
void menuUsuario();
void menuEntrenamiento();
void menuReporte();
void menuConfiguracion();
// SUB MENU USUARIO
void crearUsuario();
void modificarUsuario();
void listarUsuarioPorID();
void listarTodoLosUsuarios();
void eliminarUsuario();
// SUB MENU ENTRENAMIENTO
void crearEntrenamiento();
void modificarEntrenamiento();
void listarEntrenamientoPorID();
void listarEntrenamientoPorIDUsuario();
void listarTodoLosEntrenamientos();
// SUB MENU REPORTE


// SUB MENU CONFIGURACION
void realizarCopSeguridad();
void recupCopSeguridad();

#endif // MENU_H_INCLUDED

