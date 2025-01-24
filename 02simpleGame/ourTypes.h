#ifndef OURTYPES_H
#define OURTYPES_H

#include "ebentoak.h"

typedef enum
{
    JOLASTEN,
    GALDU,
    IRABAZI
} EGOERA;

typedef enum
{
    IRUDIA,
    MARGOA,
    TESTUA,
    BOTOIA,
    BLOKE_LIMITEA
} MOTA;

typedef enum
{
    BOTON1,
    BOTON2,
    BOTON3,
    BOTON4,
    BOTON5,
    BOTON6,
    BOTON7,
    BOTON8,
    BOTON9,
    BOTON10
} BOTON_ID;

typedef struct
{
    int x, y;
    BOTON_ID id;
} Boton; // Posición del botón int width, height; // Tamaño del botón BOTON_ID id; // Identificador del botón } Boton;

typedef struct
{
    POSIZIOA pos;
    int id;
    MOTA mota;
    int airean;
    POSIZIOA posizioaHasiera;
    int abiaduraY;
    int abiaduraX;
    int height;
    int width;
    int aktibo;
    int frameCounter;
    int alternar;
} JOKO_ELEMENTUA;

#endif