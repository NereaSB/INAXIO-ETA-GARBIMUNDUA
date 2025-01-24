#ifndef GAME10_H
#define GAME10_H

#include "birziklatu.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "irudiak_kargatu.h"
#include "kargapantaila.h"
#include "kolisioa.h"
#include "mapa.h"
#include "menua.h"
#include "mugimendua.h"
#include "nibelak.h"
#include "nibeleiDeitu.h"
#include "ourTypes.h"
#include "soinua.h"
#include "text.h"
#include <SDL.h>
#include <stdio.h>

#define JOKOA_SOUND "./sound/JOKU_SOINUA.wav"

#define BACKGROUND_IMAGE "./img/City.bmp"
#define BLOQUE_CITY "./img/Bloque_City.bmp"
#define NUM_BLOQUES 12
#define BUKAERA_IMAGE_IRABAZI "./img/IRABAZI.bmp"
#define BUKAERA_IMAGE_GALDU "./img/GALDU.bmp"

#define PLAYER_SIZE 100
#define BLOCK_WIDTH 109
#define BLOCK_HEIGHT 18

#define CANDADO "./img/candado.bmp"

// PERTSONAIA ANIMAZIOA
#define JOKALARIA_ESKUMARA_BEGIRATZEN "./img/Iñaxio/iñaxio_urdina/Eskuma_Geldi.bmp"
#define JOKALARIA_ESKUMARA_HASI_MUGITZEN "./img/Iñaxio/iñaxio_urdina/Eskuma_Hasi_Mugitzen.bmp"
#define JOKALARIA_ESKUMARA_SEGUI_MUGITZEN "./img/Iñaxio/iñaxio_urdina/Eskuma_Amaitzen_Mugitzen.bmp"
#define JOKALARIA_ESKUMARA_SALTO "./img/Iñaxio/iñaxio_urdina/Eskuma_Salto.bmp"
#define JOKALARIA_EZKERRERA_BEGIRATZEN "./img/Iñaxio/iñaxio_urdina/Ezkerra_Geldi.bmp"
#define JOKALARIA_EZKERRARA_HASI_MUGITZEN "./img/Iñaxio/iñaxio_urdina/Ezkerra_Hasi_Mugitzen.bmp"
#define JOKALARIA_EZKERRARA_SEGUI_MUGITZEN "./img/Iñaxio/iñaxio_urdina/Ezkerra_Amaitzen_Mugitzen.bmp"
#define JOKALARIA_EZKERRARA_SALTO "./img/Iñaxio/iñaxio_urdina/Ezkerra_Salto.bmp"

// Soinua
#define JOKOA_MENU_SOUND "./sound/musica_menu_fondo.wav"

// Menu
#define BACKGROUND_MENU_IMAGE "./img/menufondo.bmp"
#define JOLASTU_BOTOI_IMAGE "./img/jolastu.bmp"
#define NOLA_JOLASTU_BOTOI_IMAGE "./img/nolajolastu.bmp"
#define KREDITUAK_BOTOI_IMAGE "./img/kredituak.bmp"

// Soinu irudiak
#define SOINUAON_IMAGE "./img/soinua_on.bmp"
#define SOINUAOFF_IMAGE "./img/soinua_off.bmp"

#define JOKOA_SOUND_WIN "./sound/BugleCall.wav"
#define JOKOA_SOUND_LOOSE "./sound/terminator.wav"
#define BUKAERA_SOUND_1 "./sound/128NIGHT_01.wav"
#define BUKAERA_IMAGE "./img/GALDU.bmp"

// Nibel_Mapa
#define NIBEL_MAPA "./img/mapa_fondo1.bmp"
#define KARGA_IMAGE "./img/karga3.bmp"
#define N1_IMAGE "./img/nibel1_irudia.bmp"
#define Ncity_IMAGE "./img/ncity.bmp"
#define NKoba_IMAGE "./img/nibel2.bmp"
#define NCastillo_IMAGE "./img/ncastillo1.bmp"
#define NEspacio_IMAGE "./img/nEspacio.bmp"
#define N6_IMAGE "./img/n6.bmp"
#define N7_IMAGE "./img/n7.bmp"

int jokoAmaierakoa(EGOERA egoera);

void saguarenPosizioaLortu(int *x, int *y);


#endif;