#include "nibeleiDeitu.h"
// ALDATU->
int accionNibel1(int bizitzak)
{
    int puntuazioa;
    printf("Acción del botón 'Nibel 1'\n");
    pantailaGarbitu();
    kargaPantaila();
    pantailaGarbitu();
    bizitzak = jokatu(bizitzak);

    if (puntuazioa >= 100)
    {
        bizitzak++;
    }

    return bizitzak;
}

int accionNcity(int bizitzak)
{
    printf("Acción del botón 'Ncity'\n");
    pantailaGarbitu();
    // bizitzak = jokatu(bizitzak);

    return bizitzak;
}

int accionNKoba(int bizitzak)
{
    printf("Acción del botón 'NKoba'\n");
    kargaPantaila();
    pantailaGarbitu();
    // bizitzak = jokatu(bizitzak);

    return bizitzak;
}