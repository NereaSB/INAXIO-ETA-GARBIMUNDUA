#ifndef KOLISIOA_H
#define KOLISIOA_H

#include "game02.h"
#include "graphics.h"
#include "imagen.h"
#include "kolisioa.h"
#include "mugimendua.h"
#include "ourTypes.h"

int kolisioaKonprobatu(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA *objetuak, int objetuKopurua);
JOKO_ELEMENTUA KolisioaBlokea(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA *objetuak, int objetuKopurua, int ebentu);
void kolisioaBasurarekin(JOKO_ELEMENTUA *basura, int basuraKopurua, JOKO_ELEMENTUA jokalaria);
JOKO_ELEMENTUA kolisioaHertzekin(JOKO_ELEMENTUA jokalaria);
int kolisioaKonprobatuGaiztoekin(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA objetuak);
int kolisioaGoratik(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA objetua);
int Atea_teletransporte(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA objetuak);

#endif