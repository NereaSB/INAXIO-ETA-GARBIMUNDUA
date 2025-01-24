#include "nibelak.h"

int jokatu(int bizitzak)
{
    char bizitza[100];
    bizitzak = 3;

    int ebentu = 0, i = 0, kolisioaBlokeekin = 0, kolisioaBasura = 0, jasotakoBasurak = 0, ateaKargatuta = 0,
        kolisioaGora = 0, kolisioaGaiztoa = 0, kolisioaGaiztoa2 = 0, ateanSartuta = 0;
    // blokeak hasieratu________________________________________________________________________________
    char *irudiakBlokeak[] = {"./img/cobaBloke3x1.bmp", "./img/cobaBloke3x1.bmp", "./img/cobaBloke3x1.bmp",
                              "./img/cobaBloke3x1.bmp", "./img/cobaBloke3x1.bmp", "./img/cobaBloke3x1.bmp",
                              "./img/cobaBloke2x1.bmp", "./img/cobaBloke1x3.bmp", "./img/cobaBloke1x2.bmp",
                              "./img/cobaBloke1x1.bmp", "./img/cobaBloke1x1.bmp", "./img/cobaBloke1x1.bmp",
                              "./img/cobaBloke1x1.bmp", "./img/cobaBloke7x1.bmp", "./img/cobaBloke7x1.bmp"};
    POSIZIOA blokeenPosizioak[] = {{600, 400}, {550, 375}, {340, 325}, {220, 300}, {110, 255},
                                   {0, 210},   {340, 430}, {100, 420}, {380, 455}, {470, 350},
                                   {675, 300}, {610, 230}, {535, 140}, {250, 100}, {750, 350}};
    // basurak hasieratu____________________________________________________________________________________
    char *irudiakBasura[] = {"./img/Basurak/botella1.bmp", "./img/Basurak/Caja.bmp", "./img/Basurak/Ura.bmp"};
    POSIZIOA basurenPosizioak[] = {{750, 290}, {300, 420}, {270, 35}};
    //___________________bloke eta basura kopurua lortu_____________________________________________
    int blokeKopurua = sizeof(blokeenPosizioak) / sizeof(blokeenPosizioak[0]);
    int basuraKopurua = sizeof(basurenPosizioak) / sizeof(basurenPosizioak[0]);
    /*__________________________________________joko_elementuak definitu____________________________*/
    JOKO_ELEMENTUA jokalaria = JokoElementuakHasieratu((JOKO_ELEMENTUA){0}),
                   gaiztoa = gaiztoaHasieratu((JOKO_ELEMENTUA){0}), gaiztoa2 = gaiztoaHasieratu2((JOKO_ELEMENTUA){0}),
                   blokea[BLOKE_MAX], basura[BASURA_MAX], atea;

    int backgroundId;

    jokalaria = JokoElementuakHasieratu(jokalaria);
    gaiztoa = gaiztoaHasieratu(gaiztoa);
    gaiztoa2 = gaiztoaHasieratu2(gaiztoa2);
    atea.pos.x = 410;
    atea.pos.y = 20;

    backgroundId = irudiaKargatu(KOBA_FONDO);
    irudiaTamainaEzarri(backgroundId, SCREEN_WIDTH, SCREEN_HEIGHT);
    jokalaria.id = irudiaKargatu(JOKALARIA_ESKUMARA_BEGIRATZEN);
    gaiztoa.id = irudiaKargatu("./img/xagux_beste_aldera.bmp");
    gaiztoa2.id = irudiaKargatu("./img/xagux_beste_aldera.bmp");

    objetuakKargatu(blokea, blokeKopurua, irudiakBlokeak);
    objetuakKargatu(basura, basuraKopurua, irudiakBasura);

    do
    {
        SDL_Delay(10);
        pantailaGarbitu();
        irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
        irudiaMugitu(gaiztoa.id, gaiztoa.pos.x, gaiztoa.pos.y);
        irudiaMugitu(gaiztoa2.id, gaiztoa2.pos.x, gaiztoa2.pos.y);
        objetuakMuitu(blokea, blokeenPosizioak, blokeKopurua);
        objetuakMuitu(basura, basurenPosizioak, basuraKopurua);

        jokalaria = kolisioaHertzekin(jokalaria);
        kolisioaBlokeekin = kolisioaKonprobatu(jokalaria, blokea, blokeKopurua);
        kolisioaBasura = kolisioaKonprobatu(jokalaria, basura, basuraKopurua);
        kolisioaGaiztoa = kolisioaKonprobatuGaiztoekin(jokalaria, gaiztoa);
        kolisioaGaiztoa2 = kolisioaKonprobatuGaiztoekin(jokalaria, gaiztoa2);

        irudiakMarraztu();

        sprintf_s(bizitza, sizeof(bizitza), "BIZITZAK: %d", bizitzak);

        textuaIdatzi(SCREEN_WIDTH - 900, SCREEN_HEIGHT - 484, bizitza);

        if (kolisioaGaiztoa)
        {
            kolisioaGora = kolisioaGoratik(jokalaria, gaiztoa);
            if (kolisioaGora)
            {
                jokalaria.abiaduraY = -6;
                irudiaKendu(gaiztoa.id);
                gaiztoa.aktibo = 0;
            }
            else
            {
                bizitzak--;
                jokalaria.pos.x = 10;
                jokalaria.pos.y = 455;
            }
        }
        if (kolisioaGaiztoa2)
        {
            kolisioaGora = kolisioaGoratik(jokalaria, gaiztoa2);
            if (kolisioaGora)
            {
                jokalaria.abiaduraY = -6;
                irudiaKendu(gaiztoa2.id);
                gaiztoa2.aktibo = 0;
            }
            else
            {
                bizitzak--;
                jokalaria.pos.x = 10;
                jokalaria.pos.y = 455;
            }
        }

        if (kolisioaBlokeekin)
        {
            jokalaria = KolisioaBlokea(jokalaria, blokea, blokeKopurua, ebentu);
        }
        if (kolisioaBasura)
        {
            kolisioaBasurarekin(basura, basuraKopurua, jokalaria);
            jasotakoBasurak++;
        }
        else if (!kolisioaBlokeekin && jokalaria.pos.y <= jokalaria.posizioaHasiera.y)
        {
            jokalaria.airean = 1;
        }
        pantailaBerriztu();

        ebentu = ebentuaJasoGertatuBada();
        jokalaria = pertsonaiaMugitu(jokalaria, ebentu);
        gaiztoa = gaiztoaMugituHorizontalki(gaiztoa, blokea, blokeKopurua);
        gaiztoa2 = gaiztoaMugituBertikalki(gaiztoa2, 200, 370);

        if (jokalaria.airean)
        {
            jokalaria = saltoEgin(jokalaria);
        }
        if (jasotakoBasurak == basuraKopurua && ateaKargatuta != 1 && ateanSartuta!=1)
        {
            atea.id = irudiaKargatu(ATEA_IMAGE);
            irudiaMugitu(atea.id, atea.pos.x, atea.pos.y);
            // funztioa kolisioa atea
            ateaKargatuta = 1;            
        }
        if(bizitzak==0)
        {
            EGOERA egoera;
            egoera=GALDU;
            egoera = jokoAmaierakoa(egoera);
        }
        
        ateanSartuta = Atea_teletransporte(jokalaria, atea);

    } while (ateanSartuta != 1 && bizitzak > 0);

    irudiaKendu(jokalaria.id);
    irudiaKendu(gaiztoa.id);
    irudiaKendu(gaiztoa2.id);
    irudiaKendu(atea.id);
    irudiaKendu(backgroundId);
    for (int i = 0; i < blokeKopurua; i++)
    {
        irudiaKendu(blokea[i].id);
    }
    for (int i = 0; i < basuraKopurua; i++)
    {
        irudiaKendu(basura[i].id);
    }

    birziklatu();

    return bizitzak;
}
JOKO_ELEMENTUA JokoElementuakHasieratu(JOKO_ELEMENTUA jokalaria)
{
    jokalaria.pos.x = 10;
    jokalaria.pos.y = 455;
    jokalaria.posizioaHasiera.x = 10;
    jokalaria.posizioaHasiera.y = 455;
    jokalaria.abiaduraY = 0;
    jokalaria.abiaduraX = 0;
    jokalaria.airean = 0;
    jokalaria.aktibo = 1;

    return jokalaria;
}
JOKO_ELEMENTUA gaiztoaHasieratu(JOKO_ELEMENTUA gaiztoa1)
{
    gaiztoa1.pos.x = 200;
    gaiztoa1.pos.y = 360;
    gaiztoa1.abiaduraX = 3;
    gaiztoa1.aktibo = 1;
    return gaiztoa1;
}
JOKO_ELEMENTUA gaiztoaHasieratu2(JOKO_ELEMENTUA gaiztoa1)
{
    gaiztoa1.pos.x = 400;
    gaiztoa1.pos.y = 360;
    gaiztoa1.abiaduraY = 3;
    gaiztoa1.aktibo = 1;
    return gaiztoa1;
}