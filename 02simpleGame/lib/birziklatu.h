#ifndef NIVEL1_H
#define NIVEL1_H

#include "graphics.h"
#include "imagen.h"
#include "soinua.h"
#include "text.h"
#define MAX_OBJETUAK 11
#define MAX_ZABORRONTZIAK 5

typedef struct S_OBJETUA
{
    int id;
    int x, y;
    int width, height;    // Hasierako posizioa
    int arrastratzen;     // Objetua arrastratze 1=bai 0=ez
    int offsetX, offsetY; // Desplazamiento relativo entre el ratón y el objeto
} OBJETUA;

typedef struct
{
    int id;
    int x, y;
    int width, height;
} ZABORRONTZIA;

#define N1_BACKGROUND_IMAGE "./img/fondo_birziklatu.bmp"
#define Bir_Taula_IMAGE "./img/taula1.bmp"
#define N1_PLAYER_IMAGE "./img/nivel1_player.bmp"
#define N1_EXIT_BUTTON_IMAGE "./img/nivel1_exit_button.bmp"

int birziklatu(void);

#endif // NIVEL1_H
