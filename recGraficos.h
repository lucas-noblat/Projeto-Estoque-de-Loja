#ifndef RECGRAFICOS_H_INCLUDED
#define RECGRAFICOS_H_INCLUDED
#include <windows.h>

void linhaCol (int lin, int col);
void box (int lin1, int col1, int lin2, int col2, int cor_letra, int cor_fundo);
int menu(int lin1, int col1, int qtd, char listaOpcoes[][40], int cor_letra, int cor_fundo);

COORD size;
HANDLE h;


enum letter_collor {

    BLACK,  
    BLUE,   
    GREEN,  
    CYAN,   
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE

};

enum background_collor {

    _BLACK=0,  
    _BLUE=16,   
    _GREEN=32,  
    _CYAN=48,   
    _RED=64,
    _MAGENTA=80,
    _BROWN=96,
    _LIGHTGRAY=112,
    _DARKGRAY=128,
    _LIGHTBLUE=144,
    _LIGHTGREEN=160,
    _LIGHTCYAN=176,
    _LIGTRED=192,
    _LIGHTMAGENTA=208,
    _YELLOW=224,
    _WHITE=240


};


void textColor(int letras, int fundo);
void gotoxy(int x, int y);



#endif