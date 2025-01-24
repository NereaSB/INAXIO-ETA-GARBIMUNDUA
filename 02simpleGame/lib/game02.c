#include "game02.h"

void saguarenPosizioaLortu(int *x, int *y)
{
    int saguX, saguY;
    SDL_GetMouseState(&saguX, &saguY);
    *x = saguX;
    *y = saguY;
}

int jokoAmaierakoa(EGOERA egoera)
{
    int ebentu = 0, id;
    int idAudioGame;
    
    loadTheMusic(BUKAERA_SOUND_1);
    toggleMusic();
    if (egoera == GALDU)
    {
        id = irudiaKargatu(BUKAERA_IMAGE_GALDU);
        idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
        playSound(idAudioGame);
    }
    if(egoera == IRABAZI)
    {
        id = irudiaKargatu(BUKAERA_IMAGE_IRABAZI);
        idAudioGame = loadSound(JOKOA_SOUND_WIN);
        playSound(idAudioGame);
    }
    pantailaGarbitu();

    do
    {
        ebentu = ebentuaJasoGertatuBada();
        irudiaMugitu(id, 0, 0);
        irudiakMarraztu();
        pantailaBerriztu();

    } while (ebentu != TECLA_RETURN);
    
    
    toggleMusic();
    irudiaKendu(id);
    return (ebentu != TECLA_RETURN) ? 1 : 0;
}
