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
/*
int buscarNombre(char *nombreB){
	int pos=0;
	Usuario u;
	while(u.leerDisco(pos)==1){
		if(strcmp(nombreB,u.getNombre())==0 && u.getEstado()==1){
            return pos;
		}
		pos++;
    }
	return -1;
}*/
