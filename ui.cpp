#include <iostream>
using namespace std;
#include <iomanip>
#include <cstring>
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;

void initUI() {

    system("mode con: cols=80 lines=25");
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
    setlocale(LC_ALL, "spanish");


}

void setColors(int foreColor, int backColor){
    setColor(foreColor);
    setBackgroundColor(backColor);
}

void bar(int foreColor, int backColor, int y, int width){
    if (width > SCREEN_WIDTH)
        width = SCREEN_WIDTH;
    if (y > SCREEN_HEIGHT)
        y = SCREEN_HEIGHT;

    setColors(foreColor, backColor);
    for (int x=1; x<=width; x++){
        gotoxy(x, y);
        cout << " ";
    }
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
    resetColor();
}
void msj(const char *mensaje, int foreColor, int backColor, int y, Orientation o){
    bar(foreColor, backColor, y, SCREEN_WIDTH);
    setColors(foreColor, backColor);

    //TODO: Analizar la orientación
    gotoxy(1, y);
    cout << mensaje;
    cin.ignore();
    anykey();
    resetColor();
    bar(APP_FORECOLOR, APP_BACKCOLOR, y, SCREEN_WIDTH);
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
}
void title(const char *mensaje, int foreColor, int backColor){
    bar(foreColor, backColor, 1, SCREEN_WIDTH);
    setColors(foreColor, backColor);
    int centro = (SCREEN_WIDTH - strlen(mensaje))/2;
    gotoxy(centro, 1);
    cout << mensaje;
    resetColor();
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
}
void delline(int line, int foreColor, int backColor){
    setColors(foreColor, backColor);
    for(int x=0; x<=SCREEN_WIDTH; x++){
        gotoxy(x, line);
        cout << " ";
    }
    resetColor();
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
}
/// COPIAR FUNCION Y EDITAR LOS DATOS A MOSTRAR
void listarPlanilla(){
    int ancho =10; // Determina el ancho de cada columna
    cls();
    title("LISTAR PLANILLA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    gotoxy(1, 5);
    cout << left;
    cout << setw(ancho) << "COL-1" << setw(ancho) << "COL-2" << setw(ancho) << "COL-3" << setw(ancho) << "COL-4" << setw(ancho) << "COL-5";
    cout << endl << "----------------------------------------------------------------------------" << endl;
    for(int i = 0; i<2; i++){
        cout << setw(ancho) << "CELDA-1";
        cout << setw(ancho) << "CELDA-2";
        cout << setw(ancho) << "CELDA-3";
        cout << setw(ancho) << "CELDA-4";
        cout << setw(ancho) << "CELDA-5";
        cout << endl << "----------------------------------------------------------------------------" << endl;
    }
    msj("Presione cualquier tecla para salir", rlutil::WHITE, rlutil::MAGENTA);
    return;
}

void msjInt(const char *mensaje, int entero, int foreColor, int backColor, int y, Orientation o){
    bar(foreColor, backColor, y, SCREEN_WIDTH);
    setColors(foreColor, backColor);

    //TODO: Analizar la orientación
    gotoxy(1, y);
    cout << mensaje << " " << entero;
    cin.ignore();
    anykey();
    resetColor();
    bar(APP_FORECOLOR, APP_BACKCOLOR, y, SCREEN_WIDTH);
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
}

void msjFloat(const char *mensaje, float dato, int foreColor, int backColor, int y, Orientation o){
    bar(foreColor, backColor, y, SCREEN_WIDTH);
    setColors(foreColor, backColor);

    //TODO: Analizar la orientación
    gotoxy(1, y);
    cout << mensaje << " " << dato;
    cin.ignore();
    anykey();
    resetColor();
    bar(APP_FORECOLOR, APP_BACKCOLOR, y, SCREEN_WIDTH);
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
}

void titleInt(const char *mensaje, int entero, int foreColor, int backColor){
    bar(foreColor, backColor, 1, SCREEN_WIDTH);
    setColors(foreColor, backColor);
    int centro = (SCREEN_WIDTH - strlen(mensaje))/2;
    gotoxy(centro, 1);
    cout << mensaje << " " << entero;
    resetColor();
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
}

void titleFloat(const char *mensaje, float dato, int foreColor, int backColor){
    bar(foreColor, backColor, 1, SCREEN_WIDTH);
    setColors(foreColor, backColor);
    int centro = (SCREEN_WIDTH - strlen(mensaje))/2;
    gotoxy(centro, 1);
    cout << mensaje << " " << dato;
    resetColor();
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
}
