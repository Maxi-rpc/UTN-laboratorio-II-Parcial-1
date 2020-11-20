#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

#define APP_BACKCOLOR 0 // DEFINE EL COLOR DE FONDO general
#define APP_FORECOLOR 15 // DEFINE EL COLOR DEL TEXTO general
#define APP_TITLEBACKCOLOR 1 // DEFINE EL COLOR DE FONDO en titulo
#define APP_TITLEFORECOLOR 15 // DEFINE EL COLOR DEL TEXTO en titulo
#define APP_ERRORCOLOR 4
#define APP_OKCOLOR 2
#define APP_DELAY 1000

/// COLORES
/*
    0 NEGRO
    1 AZUL
    2 VERDE
    3 CELESTE
    4 ROJO
    5 VIOLETA
    6 DORADO
    7 GRIS
    8 GRIS OSCURO
    9 CELESTE NEON
    10 VERDE NEON
    11 TURQUESA
    12 ROJO NEON
    13 VIOLETA FUERTE
    14 AMARILLO PALIDO
    15 BLANCO
    16 NEGRO
    17 AZUL
    18 VERDE OSCURO
    19 CELESTE OSCURO
    20 ROJO OSCURO
*/
enum Orientation{
    TEXT_LEFT,
    TEXT_RIGHT,
    TEXT_CENTER
};
void setColors(int foreColor = APP_FORECOLOR, int backColor = APP_BACKCOLOR);
void bar(int foreColor, int backColor, int y=SCREEN_HEIGHT, int width=SCREEN_WIDTH);
void title(const char *mensaje, int foreColor = APP_TITLEFORECOLOR, int backColor = APP_TITLEBACKCOLOR);
void msj(const char *mensaje, int foreColor = APP_FORECOLOR, int backColor = APP_BACKCOLOR, int y = SCREEN_HEIGHT, Orientation o = TEXT_CENTER);
void delline(int line, int foreColor = APP_FORECOLOR, int backColor = APP_BACKCOLOR);
void initUI();

void listarPlanilla();
void titleInt(const char *mensaje,int entero, int foreColor = APP_TITLEFORECOLOR, int backColor = APP_TITLEBACKCOLOR);
void titleFloat(const char *mensaje,float dato, int foreColor = APP_TITLEFORECOLOR, int backColor = APP_TITLEBACKCOLOR);
void msjInt(const char *mensaje,int entero, int foreColor = APP_FORECOLOR, int backColor = APP_BACKCOLOR, int y = SCREEN_HEIGHT, Orientation o = TEXT_CENTER);
void msjFloat(const char *mensaje,float dato, int foreColor = APP_FORECOLOR, int backColor = APP_BACKCOLOR, int y = SCREEN_HEIGHT, Orientation o = TEXT_CENTER);

#endif // UI_H_INCLUDED
