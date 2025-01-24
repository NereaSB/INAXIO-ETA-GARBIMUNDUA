
#include <SDL.h>

#include "graphics.h"
#include "imagen.h"
#include <stdio.h>

int irudiarenPosizioaAurkitu(int id);

typedef struct Img
{
    int id;
    SDL_Surface *imagen;
    SDL_Texture *texture;
    SDL_Rect dest;
} IMG;

IMG irudiak[MAX_IMG];
int irudiKop = 0;
int id = 0;

int irudiaKargatu(char *fileName)
{
    int colorkey;
    SDL_Surface *surface;
    SDL_Renderer *gRenderer = getRenderer();

    if (irudiKop < MAX_IMG)
    {
        surface = SDL_LoadBMP(fileName);
        if (surface == NULL)
        {
            fprintf(stderr, "Couldn't load %s: %s\n", fileName, SDL_GetError());
            return -1;
        }
        else
        {
            colorkey = SDL_MapRGB(surface->format, 255, 0, 255);
            SDL_SetColorKey(surface, SDL_TRUE, colorkey);
            irudiak[irudiKop].texture = SDL_CreateTextureFromSurface(gRenderer, surface);
            irudiak[irudiKop].dest.x = irudiak[irudiKop].dest.y = 0;
            irudiak[irudiKop].dest.w = surface->w;
            irudiak[irudiKop].dest.h = surface->h;
            SDL_FreeSurface(surface);
            irudiak[irudiKop].id = id;
            irudiKop++;
            id++;
        }
    }
    else
    {
        printf("Has superado el maixmo de Imagens por aplicaci�n.Para aumentar imagen.h\n");
        return -1;
    }

    return id - 1;
}

void irudiaMugitu(int numImg, int x, int y)
{

    int id = 0;

    id = irudiarenPosizioaAurkitu(numImg);

    irudiak[id].dest.x = x;
    irudiak[id].dest.y = y;
}

void irudiaTamainaLortu(int idImg, int *width, int *height)
{
    int id = irudiarenPosizioaAurkitu(idImg); // Obtener la posición de la imagen en el array

    if (id != -1)
    {
        *width = irudiak[id].dest.w;  // Ancho original
        *height = irudiak[id].dest.h; // Alto original
    }
    else
    {
        printf("Imagen con id %d no encontrada.\n", idImg);
        *width = 0;
        *height = 0;
    }
}

void irudiaTamainaEzarri(int id, int newWidth, int newHeight)
{
    // Buscar la imagen en el arreglo irudiak usando el id
    int pos = irudiarenPosizioaAurkitu(id);

    if (pos == -1)
    {
        printf("Imagen no encontrada\n");
        return;
    }

    // Redefinir el tamaño de la imagen en el arreglo
    irudiak[pos].dest.w = newWidth;
    irudiak[pos].dest.h = newHeight;
}

void irudiakMarraztu(void)
{
    int i = 0;

    for (i = 0; i < irudiKop; i++)
    {
        irudiaMarraztu(irudiak[i].texture, &irudiak[i].dest);
    }
}

void irudiaKendu(int id)
{
    int i = 0, pos = 0;

    pos = irudiarenPosizioaAurkitu(id);
    SDL_DestroyTexture(irudiak[pos].texture);
    for (i = pos; i < irudiKop; i++)
    {

        irudiak[i] = irudiak[i + 1];
    }
    irudiKop--;
}

int irudiarenPosizioaAurkitu(int id)
{
    int i = 0;

    for (i = 0; i < irudiKop; i++)
    {
        if (id == irudiak[i].id)
        {
            return i;
        }
    }
    return -1;
}