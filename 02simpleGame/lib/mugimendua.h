#ifndef MUGIMENDUA_H
#define MUGIMENDUA_H

#include "ourTypes.h"
#include "game02.h"
#include "graphics.h"
#include "imagen.h"

JOKO_ELEMENTUA saltoEgin(JOKO_ELEMENTUA jokalaria);
JOKO_ELEMENTUA pertsonaiaMugitu(JOKO_ELEMENTUA jokalaria, int ebentu);
JOKO_ELEMENTUA aireanaDago(JOKO_ELEMENTUA jokalaria);
JOKO_ELEMENTUA gaiztoaMugituHorizontalki(JOKO_ELEMENTUA gaiztoa, JOKO_ELEMENTUA *blokeak, int blokeKopurura);
JOKO_ELEMENTUA gaiztoaMugituBertikalki(JOKO_ELEMENTUA gaiztoa, int yMin, int yMax);
int kolisioaKonprobatu(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA *objetuak, int objetuKopurua);

#endif