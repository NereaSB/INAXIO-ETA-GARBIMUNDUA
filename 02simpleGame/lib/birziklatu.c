#include "birziklatu.h"
#include "ebentoak.h"
#include "game02.h"
#include "graphics.h"
#include "imagen.h"
#include "soinua.h"
#include "text.h"
#include <stdio.h>

#define OBJETUA1 "./img/Basurak/Boligrafo.bmp"  // 1
#define OBJETUA2 "./img/Basurak/botella1.bmp"   // 0
#define OBJETUA3 "./img/Basurak/Botella2.bmp"   // 0
#define OBJETUA4 "./img/Basurak/Caja.bmp"       // 4
#define OBJETUA5 "./img/Basurak/Hezurra.bmp"    // 3
#define OBJETUA6 "./img/Basurak/Lata.bmp"       // 2
#define OBJETUA7 "./img/Basurak/Manzana.bmp"    // 3
#define OBJETUA8 "./img/Basurak/Maskarilla.bmp" // 1
#define OBJETUA9 "./img/Basurak/Papel.bmp"      // 4
#define OBJETUA10 "./img/Basurak/Tirita.bmp"    // 1
#define OBJETUA11 "./img/Basurak/Ura.bmp"       // 2

#define BERDEA "./img/Zaborrontziak/berdea.bmp"   // 0
#define GRIS "./img/Zaborrontziak/gris.bmp"       // 1
#define HORIA "./img/Zaborrontziak/horia.bmp"     // 2
#define MARROIA "./img/Zaborrontziak/marroia.bmp" // 3
#define URDINA "./img/Zaborrontziak/urdina.bmp"   // 4

void irudiaTamainaLortu(int idImg, int *width, int *height);

int birziklatu(void)
{
    int ebentu = 0, puntuazioa = 0, ObjetuaOndo = 11;
    char textua[100];    

    JOKO_ELEMENTUA fondo_birziklatu, taula;
    int disZaborrontziak = (640 - 500) / 4; // disZaborrontziak = 80<- distantzia
    int botonWidth = 0, botonHeight = 0, AukeratutakoObjetua = -1, i, taulawidth = 0, taulaheight = 0;
    OBJETUA objetuak[MAX_OBJETUAK];
    ZABORRONTZIA zaborrontziak[MAX_ZABORRONTZIAK];
    int zaborrontziaParaObjetuak[MAX_OBJETUAK] = {
        1, 0, 0, 4, 3, 2, 3, 1, 4, 1, 2}; // Índice del zaborrontzi correspondiente a cada objeto

    int hasierakoPosizioak[MAX_OBJETUAK][2];

    int x_offset[] = {SCREEN_WIDTH - 650, SCREEN_WIDTH - 550, SCREEN_WIDTH - 450, SCREEN_WIDTH - 360};
    int y_offset[] = {SCREEN_HEIGHT - 480, SCREEN_HEIGHT - 410, SCREEN_HEIGHT - 350};

    int index = 0; // Para recorrer el array de posiciones

    for (int i = 0; i < 3; i++)
    { // Fila-> (y_offset)
        for (int j = 0; j < 4; j++)
        {                                               // kolumnak-> (x_offset)
            hasierakoPosizioak[index][0] = x_offset[j]; //  x esleitu
            hasierakoPosizioak[index][1] = y_offset[i]; //  y esleitu
            index++;
        }
    }
    char *rutaIrudiak[MAX_OBJETUAK] = {OBJETUA1, OBJETUA2, OBJETUA3, OBJETUA4,  OBJETUA5, OBJETUA6,
                                       OBJETUA7, OBJETUA8, OBJETUA9, OBJETUA10, OBJETUA11};
    int ZaborrontziakPos[MAX_ZABORRONTZIAK][2] = {{SCREEN_WIDTH - 910, SCREEN_HEIGHT - 200},
                                                  {SCREEN_WIDTH - 700, SCREEN_HEIGHT - 200},
                                                  {SCREEN_WIDTH - 500, SCREEN_HEIGHT - 200},
                                                  {SCREEN_WIDTH - 300, SCREEN_HEIGHT - 200},
                                                  {SCREEN_WIDTH - 100, SCREEN_HEIGHT - 195}};
    char *rutaZABORRAK[MAX_ZABORRONTZIAK] = {BERDEA, GRIS, HORIA, MARROIA, URDINA};
    // BERDEA=0, GRIS=1, HORIA=2, MARROIA=3, URDINA=4

    // Birziklatu nibelaren fondoko musika kargatu
    loadTheMusic("./sound/nivel1_music.wav");
    toggleMusic();

    // Kargatu eta fondoa
    fondo_birziklatu.id = irudiaKargatu(N1_BACKGROUND_IMAGE);
    irudiaTamainaEzarri(fondo_birziklatu.id, SCREEN_WIDTH, SCREEN_HEIGHT);

    taula.id = irudiaKargatu(Bir_Taula_IMAGE);
    irudiaTamainaLortu(taula.id, &taulawidth, &taulaheight);
    // 248 125
    taulawidth += 150;
    taulaheight += 120;
    irudiaTamainaEzarri(taula.id, taulawidth, taulaheight);

    for (i = 0; i < MAX_ZABORRONTZIAK; i++)
    {
        zaborrontziak[i].id = irudiaKargatu(rutaZABORRAK[i]);
        zaborrontziak[i].x = ZaborrontziakPos[i][0];
        zaborrontziak[i].y = ZaborrontziakPos[i][1];
        irudiaTamainaLortu(zaborrontziak[i].id, &zaborrontziak[i].width, &zaborrontziak[i].height);
        irudiaMugitu(zaborrontziak[i].id, zaborrontziak[i].x, zaborrontziak[i].y);
    }

    // objetu bakoitzari esleitu
    for (i = 0; i < MAX_OBJETUAK; i++)
    {
        objetuak[i].id = irudiaKargatu(rutaIrudiak[i]);
        objetuak[i].x = hasierakoPosizioak[i][0];
        objetuak[i].y = hasierakoPosizioak[i][1];
        objetuak[i].arrastratzen = 0;
        objetuak[i].offsetX = 0;
        objetuak[i].offsetY = 0;
        irudiaTamainaLortu(objetuak[i].id, &objetuak[i].width, &objetuak[i].height);
    }

    do
    {
        SDL_Delay(10);

        pantailaGarbitu();

        irudiaMugitu(fondo_birziklatu.id, 0, 0);
        irudiaMugitu(taula.id, (SCREEN_WIDTH / 2) - 200, (SCREEN_HEIGHT / 2) - 240);

        for (i = 0; i < MAX_ZABORRONTZIAK; i++)
        {
            irudiaMugitu(zaborrontziak[i].id, zaborrontziak[i].x, zaborrontziak[i].y);
        }

        for (i = 0; i < MAX_OBJETUAK; i++)
        {
            if (objetuak[i].id != -1)
            {
                irudiaMugitu(objetuak[i].id, objetuak[i].x, objetuak[i].y);
            }
        }

        irudiakMarraztu();
        sprintf_s(textua, sizeof(textua), "PUNTUAZIOA: %d", puntuazioa);

        textuaIdatzi(SCREEN_WIDTH - 900, SCREEN_HEIGHT - 490, textua);

        pantailaBerriztu();

        ebentu = ebentuaJasoGertatuBada();
        POSIZIOA saguPos = saguarenPosizioa();

        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            if (AukeratutakoObjetua == -1) // SI TODAVIA NO ESTAMOS ARRASTRANDO
            {
                for (i = 0; i < MAX_OBJETUAK; i++)
                {
                    // Detectar si el clic ocurrió sobre el objeto
                    if (saguPos.x >= objetuak[i].x && saguPos.x <= objetuak[i].x + objetuak[i].width &&
                        saguPos.y >= objetuak[i].y && saguPos.y <= objetuak[i].y + objetuak[i].height)
                    {
                        AukeratutakoObjetua = i;
                        objetuak[i].arrastratzen = 1; // Arrastratzen hasi
                        objetuak[i].offsetX = saguPos.x - objetuak[i].x;
                        objetuak[i].offsetY = saguPos.y - objetuak[i].y;
                    }
                }
            }
        }
        else if (ebentu == SAGU_BOTOIA_ESKUMA) // Klik soltatzeko
        {
            if (AukeratutakoObjetua != -1)
            {
                objetuak[AukeratutakoObjetua].arrastratzen = 0; // Arrastratzen gelditu
                int ondo = zaborrontziaParaObjetuak[AukeratutakoObjetua];

                // Objetua nahi den tokian badago
                if (objetuak[AukeratutakoObjetua].x + objetuak[AukeratutakoObjetua].width >= zaborrontziak[ondo].x &&
                    objetuak[AukeratutakoObjetua].x <= zaborrontziak[ondo].x + zaborrontziak[ondo].width &&
                    objetuak[AukeratutakoObjetua].y + objetuak[AukeratutakoObjetua].height >= zaborrontziak[ondo].y &&
                    objetuak[AukeratutakoObjetua].y <= zaborrontziak[ondo].y + zaborrontziak[ondo].height)
                {
                    ObjetuaOndo--;
                    puntuazioa += 10;
                    irudiaKendu(objetuak[AukeratutakoObjetua].id);
                    objetuak[AukeratutakoObjetua].id = -1; // Markatu kenduta bezala
                }
                else
                {
                    puntuazioa -= 5;
                }

                AukeratutakoObjetua = -1;
            }
        }

        else if (ebentu == SAGU_MUGIMENDUA && AukeratutakoObjetua != -1) // Arrastratzen badago posizioa actualizatu
        {
            // POSIZIOA saguPos = saguarenPosizioa();
            objetuak[AukeratutakoObjetua].x = saguPos.x - objetuak[AukeratutakoObjetua].offsetX;
            objetuak[AukeratutakoObjetua].y = saguPos.y - objetuak[AukeratutakoObjetua].offsetY;
        }
    } while (ObjetuaOndo != 0); //(1) edo  ebentu != TECLA_ESCAPE Continuar hasta que se haga clic en el botón de salida

    SDL_Delay(10);
    for (int i = 0; i < MAX_ZABORRONTZIAK; i++)
    {
        irudiaKendu(zaborrontziak[i].id);
    }
    // Kendu irudiak
    for (int i = 0; i < MAX_OBJETUAK; i++)
    {
        irudiaKendu(objetuak[i].id);
    }
    irudiaKendu(taula.id);
    irudiaKendu(fondo_birziklatu.id);
    toggleMusic();

    EGOERA egoera;
    egoera=IRABAZI;
    egoera = jokoAmaierakoa(egoera);

    return puntuazioa;
}
