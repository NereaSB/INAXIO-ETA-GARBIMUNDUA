/*#include "orokorrak.h"
#include "bukaera.h"
#include "errealitateFisikoa.h"
#include "jokoa.h"
#include "sarrera.h"*/

//---------------------------------------------------------------------------------
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "soinua.h"
#include "text.h"
//---------------------------------------------------------------------------------

#include <stdio.h>

#include "lib/game02.h"
#include "ourTypes.h"

int main(int argc, char *str[])
{
    int jarraitu = 0;
    EGOERA egoera;

    if (sgHasieratu() == -1)
    {
        fprintf(stderr, "Unable to set video: %s\n", SDL_GetError());
        return 1;
    }
    textuaGaitu();
    audioInit();

    do
    {
        jokoaAurkeztu();
        jarraitu = jokoAmaierakoa(egoera);
    } while (jarraitu);
    audioTerminate();
    sgItxi();

    return 0;
}
