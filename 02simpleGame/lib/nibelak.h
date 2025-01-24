#ifndef NIBELAK_H
#define NIBELAK_H

#include "birziklatu.h"
#include "ebentoak.h"
#include "game02.h"
#include "graphics.h"
#include "imagen.h"
#include "irudiak_kargatu.h"
#include "kolisioa.h"
#include "mugimendua.h"
#include "nibelak.h"
#include "soinua.h"
#include "text.h"
#include <SDL.h>
#include <stdio.h>

#define BLOKE_MAX 20
#define BASURA_MAX 20
#define GAIZTOAK_MAX 20
#define KOBA_FONDO "./img/kobafondo.bmp"
#define ATEA_IMAGE "./img/atea1.bmp"
#define JOKALARIA_ESKUMARA_BEGIRATZEN "./img/Iñaxio/iñaxio_urdina/Eskuma_Geldi.bmp"
#define JOKALARIA_ESKUMARA_HASI_MUGITZEN "./img/Iñaxio/iñaxio_urdina/Eskuma_Hasi_Mugitzen.bmp"
#define JOKALARIA_ESKUMARA_SEGUI_MUGITZEN "./img/Iñaxio/iñaxio_urdina/Eskuma_Amaitzen_Mugitzen.bmp"
#define JOKALARIA_ESKUMARA_SALTO "./img/Iñaxio/iñaxio_urdina/Eskuma_Salto.bmp"
#define JOKALARIA_EZKERRERA_BEGIRATZEN "./img/Iñaxio/iñaxio_urdina/Ezkerra_Geldi.bmp"
#define JOKALARIA_EZKERRARA_HASI_MUGITZEN "./img/Iñaxio/iñaxio_urdina/Ezkerra_Hasi_Mugitzen.bmp"
#define JOKALARIA_EZKERRARA_SEGUI_MUGITZEN "./img/Iñaxio/iñaxio_urdina/Ezkerra_Amaitzen_Mugitzen.bmp"
#define JOKALARIA_EZKERRARA_SALTO "./img/Iñaxio/iñaxio_urdina/Ezkerra_Salto.bmp"

int jokatu(int bizitzak);
JOKO_ELEMENTUA JokoElementuakHasieratu(JOKO_ELEMENTUA jokalaria);
JOKO_ELEMENTUA gaiztoaHasieratu(JOKO_ELEMENTUA gaiztoa1);
JOKO_ELEMENTUA gaiztoaHasieratu2(JOKO_ELEMENTUA gaiztoa1);

#endif