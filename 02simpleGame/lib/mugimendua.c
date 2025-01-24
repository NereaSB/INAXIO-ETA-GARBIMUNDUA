#include "mugimendua.h"

// PERTSONAIA ANIMAZIOA
#define JOKALARIA_ESKUMARA_BEGIRATZEN "./img/Iñaxio/iñaxio_urdina/Eskuma_Geldi.bmp"
#define JOKALARIA_ESKUMARA_HASI_MUGITZEN "./img/Iñaxio/iñaxio_urdina/Eskuma_Hasi_Mugitzen.bmp"
#define JOKALARIA_ESKUMARA_SEGUI_MUGITZEN "./img/Iñaxio/iñaxio_urdina/Eskuma_Amaitzen_Mugitzen.bmp"
#define JOKALARIA_ESKUMARA_SALTO "./img/Iñaxio/iñaxio_urdina/Eskuma_Salto.bmp"
#define JOKALARIA_EZKERRERA_BEGIRATZEN "./img/Iñaxio/iñaxio_urdina/Ezkerra_Geldi.bmp"
#define JOKALARIA_EZKERRARA_HASI_MUGITZEN "./img/Iñaxio/iñaxio_urdina/Ezkerra_Hasi_Mugitzen.bmp"
#define JOKALARIA_EZKERRARA_SEGUI_MUGITZEN "./img/Iñaxio/iñaxio_urdina/Ezkerra_Amaitzen_Mugitzen.bmp"
#define JOKALARIA_EZKERRARA_SALTO "./img/Iñaxio/iñaxio_urdina/Ezkerra_Salto.bmp"

JOKO_ELEMENTUA aireanaDago(JOKO_ELEMENTUA jokalaria)
{
    if (jokalaria.pos.y < jokalaria.posizioaHasiera.y)
    {
        jokalaria.airean = 1;
    }
    return jokalaria;
}

JOKO_ELEMENTUA saltoEgin(JOKO_ELEMENTUA jokalaria)
{
    int GRABITATEA = 1;

    if (jokalaria.airean)
    {
        jokalaria.abiaduraY += GRABITATEA;
        jokalaria.pos.y += jokalaria.abiaduraY;
        jokalaria.abiaduraX = 3;

        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_D])
        {
            irudiaKendu(jokalaria.id);
            jokalaria.id = irudiaKargatu(JOKALARIA_ESKUMARA_SALTO);
            jokalaria.pos.x += jokalaria.abiaduraX;
        }
        if (state[SDL_SCANCODE_A])
        {
            irudiaKendu(jokalaria.id);
            jokalaria.id = irudiaKargatu(JOKALARIA_EZKERRARA_SALTO);
            jokalaria.pos.x -= jokalaria.abiaduraX;
        }

        if (jokalaria.pos.y + jokalaria.abiaduraY >= jokalaria.posizioaHasiera.y)
        {

            jokalaria.abiaduraY = 0;
            jokalaria.airean = 0;
        }
    }

    return jokalaria;
}

JOKO_ELEMENTUA pertsonaiaMugitu(JOKO_ELEMENTUA jokalaria, int ebentu)
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    int saltoAbiadura = -15, derecha = 0;

    if (!jokalaria.airean)
    {
        if (state[SDL_SCANCODE_D])
        {
            jokalaria.pos.x += 2;
            derecha++;

            // Alternar entre imágenes según el frameCounter
            if (jokalaria.frameCounter % 5 == 0) // Cambia la animación cada 10 frames
            {
                jokalaria.alternar = 1 - jokalaria.alternar;
            }

            irudiaKendu(jokalaria.id);
            if (jokalaria.alternar == 0)
            {
                jokalaria.id = irudiaKargatu(JOKALARIA_ESKUMARA_HASI_MUGITZEN);
            }
            else
            {
                jokalaria.id = irudiaKargatu(JOKALARIA_ESKUMARA_SEGUI_MUGITZEN);
            }
        }
        else if (state[SDL_SCANCODE_A])
        {
            jokalaria.pos.x -= 2;

            // Alternar entre imágenes según el frameCounter
            if (jokalaria.frameCounter % 5 == 0)
            {
                jokalaria.alternar = 1 - jokalaria.alternar;
            }

            irudiaKendu(jokalaria.id);
            if (jokalaria.alternar == 0)
            {
                jokalaria.id = irudiaKargatu(JOKALARIA_EZKERRARA_HASI_MUGITZEN);
            }
            else
            {
                jokalaria.id = irudiaKargatu(JOKALARIA_EZKERRARA_SEGUI_MUGITZEN);
            }
        }
        else
        {
            // Si no hay movimiento, volver a la posición de reposo
            if (jokalaria.alternar != -1)
            {
                irudiaKendu(jokalaria.id);
                if (derecha != 0)
                {
                    jokalaria.id = irudiaKargatu(JOKALARIA_ESKUMARA_BEGIRATZEN);
                    derecha = 0;
                }
                else
                {
                    jokalaria.id = irudiaKargatu(JOKALARIA_EZKERRERA_BEGIRATZEN);
                }
                jokalaria.alternar = -1; // Resetea el alternar
            }
        }

        // Salto
        if (ebentu == TECLA_w)
        {
            jokalaria.abiaduraY = saltoAbiadura;
            jokalaria.airean = 1;
        }
    }

    // Incrementar el contador de frames
    jokalaria.frameCounter++;

    return jokalaria;
}

JOKO_ELEMENTUA gaiztoaMugituHorizontalki(JOKO_ELEMENTUA gaiztoa, JOKO_ELEMENTUA *blokeak, int blokeKopurua)
{
    int kolisioa;

    kolisioa = kolisioaKonprobatu(gaiztoa, blokeak, blokeKopurua);

    if (kolisioa)
    {
        gaiztoa.abiaduraX = gaiztoa.abiaduraX * -1;
    }
    gaiztoa.pos.x = gaiztoa.pos.x + gaiztoa.abiaduraX;

    return gaiztoa;
}
JOKO_ELEMENTUA gaiztoaMugituBertikalki(JOKO_ELEMENTUA gaiztoa, int yMin, int yMax)
{

    // Movimiento vertical
    gaiztoa.pos.y = gaiztoa.pos.y + gaiztoa.abiaduraY;

    // Verificar si se sale del rango permitido
    if (gaiztoa.pos.y <= yMin || gaiztoa.pos.y >= yMax)
    {
        // Cambiar dirección al llegar al límite del rango
        gaiztoa.abiaduraY = gaiztoa.abiaduraY * -1;
        // Asegurarse de no salir del rango
        if (gaiztoa.pos.y < yMin)
        {
            gaiztoa.pos.y = yMin;
        }
        if (gaiztoa.pos.y > yMax)
        {
            gaiztoa.pos.y = yMax;
        }
    }

    return gaiztoa;
}