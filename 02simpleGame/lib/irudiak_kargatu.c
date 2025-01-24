#include "irudiak_kargatu.h"

void objetuakMuitu(JOKO_ELEMENTUA *blokea, POSIZIOA *posizioak, int kopurua)
{
    for (int i = 0; i < kopurua; i++)
    {
        if (blokea[i].aktibo)
        {
            blokea[i].pos.x = posizioak[i].x;
            blokea[i].pos.y = posizioak[i].y;
            irudiaMugitu(blokea[i].id, blokea[i].pos.x, blokea[i].pos.y);
        }
    }
}

void objetuakKargatu(JOKO_ELEMENTUA *blokea, int kopurua, char *irudia[])
{
    int i;

    for (i = 0; i < kopurua; i++)
    {
        blokea[i].id = irudiaKargatu(irudia[i]);
        blokea[i].aktibo = 1;
    }
}