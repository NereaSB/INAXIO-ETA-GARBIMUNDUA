#include "mapa.h"
EGOERA Nibel_Mapa(bizitzak)
{
    EGOERA egoera = JOLASTEN;
    int ebentu = 0, puntuak = 0, puntuak_Total = 0;
    int jugadorId = 0;
    int botonWidth = 0, botonHeight = 0;
    JOKO_ELEMENTUA nibelmapa, nibel1Button, ncityButton, nKobaButton, nCastilloButton, nEspacioButton,
        n6Button, n7Button;

    loadTheMusic(JOKOA_SOUND);
    toggleMusic();
    nibelmapa.id = irudiaKargatu(NIBEL_MAPA);
    irudiaTamainaEzarri(nibelmapa.id, SCREEN_WIDTH, SCREEN_HEIGHT);

    nibel1Button.id = irudiaKargatu(N1_IMAGE);
    ncityButton.id = irudiaKargatu(Ncity_IMAGE);
    nKobaButton.id = irudiaKargatu(NKoba_IMAGE);
    nCastilloButton.id = irudiaKargatu(NCastillo_IMAGE);
    nEspacioButton.id = irudiaKargatu(NEspacio_IMAGE);
    n6Button.id = irudiaKargatu(N6_IMAGE);
    n7Button.id = irudiaKargatu(N7_IMAGE);


    nibel1Button.pos.x = (SCREEN_WIDTH - 865);
    nibel1Button.pos.y = 150;

    ncityButton.pos.x = (SCREEN_WIDTH - 690);
    ncityButton.pos.y = 40;

    nKobaButton.pos.x = (SCREEN_WIDTH - 800);
    nKobaButton.pos.y = 325;

    nCastilloButton.pos.x = (SCREEN_WIDTH - 600);
    nCastilloButton.pos.y = 320;

    nEspacioButton.pos.x = (SCREEN_WIDTH - 332);
    nEspacioButton.pos.y = 320;

    n6Button.pos.x = (SCREEN_WIDTH - 470);
    n6Button.pos.y = 130;

    n7Button.pos.x = (SCREEN_WIDTH - 270);
    n7Button.pos.y = 130;

    // BOTON NIBEL 1
    irudiaTamainaLortu(nibel1Button.id, &botonWidth, &botonHeight);
    nibel1Button.width = botonWidth;
    nibel1Button.height = botonHeight;
    irudiaTamainaEzarri(nibel1Button.id, nibel1Button.width, nibel1Button.height);

    // BOTON NIBEL CITY
    irudiaTamainaLortu(ncityButton.id, &botonWidth, &botonHeight);
    ncityButton.width = botonWidth;
    ncityButton.height = botonHeight;
    irudiaTamainaEzarri(ncityButton.id, ncityButton.width, ncityButton.height);

    // BOTON NIBEL KOBA
    irudiaTamainaLortu(nKobaButton.id, &botonWidth, &botonHeight);
    nKobaButton.width = botonWidth;
    nKobaButton.height = botonHeight;
    irudiaTamainaEzarri(nKobaButton.id, nKobaButton.width, nKobaButton.height);

    // BOTON NIBEL CASTILLO
    irudiaTamainaLortu(nCastilloButton.id, &botonWidth, &botonHeight);
    nCastilloButton.width = botonWidth;
    nCastilloButton.height = botonHeight;
    irudiaTamainaEzarri(nCastilloButton.id, nCastilloButton.width, nCastilloButton.height);

    // BOTON NIBEL ESPACIO
    irudiaTamainaLortu(nEspacioButton.id, &botonWidth, &botonHeight);
    nEspacioButton.width = botonWidth;
    nEspacioButton.height = botonHeight;
    irudiaTamainaEzarri(nEspacioButton.id, nEspacioButton.width, nEspacioButton.height);

    // BOTON NIBEL 6
    irudiaTamainaLortu(n6Button.id, &botonWidth, &botonHeight);
    n6Button.width = botonWidth;
    n6Button.height = botonHeight;
    irudiaTamainaEzarri(n6Button.id, n6Button.width, n6Button.height);

    // BOTON NIBEL 7
    irudiaTamainaLortu(n7Button.id, &botonWidth, &botonHeight);
    n7Button.width = botonWidth;
    n7Button.height = botonHeight;
    irudiaTamainaEzarri(n7Button.id, n7Button.width, n7Button.height);

    do
    {
        SDL_Delay(10);
        pantailaGarbitu();
        // Botoiak marraztu irudiaren tamainaren arabera
        irudiaMugitu(nibel1Button.id, nibel1Button.pos.x, nibel1Button.pos.y);
        irudiaMugitu(ncityButton.id, ncityButton.pos.x, ncityButton.pos.y);
        irudiaMugitu(nKobaButton.id, nKobaButton.pos.x, nKobaButton.pos.y);
        irudiaMugitu(nCastilloButton.id, nCastilloButton.pos.x, nCastilloButton.pos.y);
        irudiaMugitu(nEspacioButton.id, nEspacioButton.pos.x, nEspacioButton.pos.y);
        irudiaMugitu(n6Button.id, n6Button.pos.x, n6Button.pos.y);
        irudiaMugitu(n7Button.id, n7Button.pos.x, n7Button.pos.y);

        irudiakMarraztu();
        pantailaBerriztu();

        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_ESKUMA || ebentu == SAGU_BOTOIA_EZKERRA)
        {
            // Saguaren posizioa lortu
            POSIZIOA saguPos = saguarenPosizioa();
            // Llamar a la función para manejar el clic en los botones
            bizitzak =
                tocado_Nibel_Mapa(nibel1Button, nibel1Button.width, nibel1Button.height, saguPos, bizitzak);
            bizitzak =
                tocado_Nibel_Mapa(ncityButton, ncityButton.width, ncityButton.height, saguPos, bizitzak);
            bizitzak =
                tocado_Nibel_Mapa(nKobaButton, nKobaButton.width, nKobaButton.height, saguPos, bizitzak);
            bizitzak = tocado_Nibel_Mapa(nCastilloButton, nCastilloButton.width, nCastilloButton.height, saguPos,
                                         bizitzak);
            bizitzak = tocado_Nibel_Mapa(nEspacioButton, nEspacioButton.width, nEspacioButton.height, saguPos, bizitzak);
            bizitzak = tocado_Nibel_Mapa(n6Button, n6Button.width, n6Button.height, saguPos, bizitzak);
            bizitzak = tocado_Nibel_Mapa(n7Button, n7Button.width, n7Button.height, saguPos, bizitzak);
            // puntuak = birziklatu();

            puntuak_Total += puntuak;

            if (bizitzak <= 0)
            {
                egoera = GALDU;
            }
            else
            {
                egoera = IRABAZI;
            }
        }
    } while (1); //(1) Continuar hasta que se haga clic en el botón nibel1, ncity

    irudiaKendu(nibelmapa.id);
    irudiaKendu(nibel1Button.id);
    irudiaKendu(ncityButton.id);
    irudiaKendu(nKobaButton.id);
    irudiaKendu(nCastilloButton.id);
    irudiaKendu(nEspacioButton.id);
    irudiaKendu(n6Button.id);
    irudiaKendu(n7Button.id);

    if (jugadorId != -1)
    {
        irudiaKendu(jugadorId);
    }
    toggleMusic();
    return egoera;
}
int tocado_Nibel_Mapa(JOKO_ELEMENTUA BOTOIA, int botonWidth, int botonHeight, POSIZIOA saguPos, int bizitzak)
{
    if (saguPos.x >= BOTOIA.pos.x && saguPos.x <= BOTOIA.pos.x + botonWidth && saguPos.y >= BOTOIA.pos.y &&
        saguPos.y <= BOTOIA.pos.y + botonHeight)
    {
        printf("Botón clicado\n");
        if (BOTOIA.id == 7)
        {
            bizitzak = accionNibel1(bizitzak);
        }
        else if (BOTOIA.id == 8)
        {
            bizitzak = accionNcity(bizitzak);
        }
        else if (BOTOIA.id == 9)
        {
            bizitzak = accionNKoba(bizitzak);
        }
        else
        {
            printf("No se ha reconocido el botón clicado.\n");
        }
    }
    return bizitzak;
}