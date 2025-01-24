#include "kolisioa.h"
int kolisioaKonprobatu(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA *objetuak, int objetuKopurua)
{
    int jokalariarenZabalera, jokalariarenAltuera;
    int blokeZabalera, blokeAltuera;
    int i = 0;
    int kolisioa = 0;

    irudiaTamainaLortu(jokalaria.id, &jokalariarenZabalera, &jokalariarenAltuera);

    int jokalariaEzkerra = jokalaria.pos.x;
    int jokalariaEskuma = jokalaria.pos.x + jokalariarenZabalera;
    int jokalariaGoia = jokalaria.pos.y;
    int jokalariaBehea = jokalaria.pos.y + jokalariarenAltuera;

    for (i = 0; i < objetuKopurua; i++)
    {
        irudiaTamainaLortu(objetuak[i].id, &blokeZabalera, &blokeAltuera);

        int blokeEzkerra = objetuak[i].pos.x;
        int blokeEskuma = objetuak[i].pos.x + blokeZabalera;
        int blokeGoia = objetuak[i].pos.y;
        int blokeBehea = objetuak[i].pos.y + blokeAltuera;

        if (jokalariaEskuma > blokeEzkerra && jokalariaEzkerra < blokeEskuma && jokalariaBehea > blokeGoia &&
            jokalariaGoia < blokeBehea)
        {
            kolisioa = 1;
        }
    }

    return kolisioa;
}

JOKO_ELEMENTUA KolisioaBlokea(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA *objetuak, int objetuKopurua, int ebentu)
{
    int jokalariarenZabalera, jokalariarenAltuera;
    int blokeZabalera, blokeAltuera;
    int i = 0;
    int gainean = 0;
    int kolisioa = 0;

    irudiaTamainaLortu(jokalaria.id, &jokalariarenZabalera, &jokalariarenAltuera);

    int jokalariaEzkerra = jokalaria.pos.x;
    int jokalariaEskuma = jokalaria.pos.x + jokalariarenZabalera;
    int jokalariaGoia = jokalaria.pos.y;
    int jokalariaBehea = jokalaria.pos.y + jokalariarenAltuera;

    while (i < objetuKopurua && !kolisioa)
    {
        gainean = 0;
        irudiaTamainaLortu(objetuak[i].id, &blokeZabalera, &blokeAltuera);

        int blokeEzkerra = objetuak[i].pos.x;
        int blokeEskuma = objetuak[i].pos.x + blokeZabalera;
        int blokeGoia = objetuak[i].pos.y;
        int blokeBehea = objetuak[i].pos.y + blokeAltuera;

        if (jokalariaEskuma > blokeEzkerra && jokalariaEzkerra < blokeEskuma && jokalariaGoia < blokeBehea &&
            jokalariaBehea > blokeGoia)
        {

            int desplazamientoEzkerra = jokalariaEskuma - blokeEzkerra;
            int desplazamientoEskuma = blokeEskuma - jokalariaEzkerra;
            int desplazamientoGoia = jokalariaBehea - blokeGoia;
            int desplazamientoBehea = blokeBehea - jokalariaGoia;

            if (desplazamientoGoia <= desplazamientoEzkerra && desplazamientoGoia <= desplazamientoEskuma &&
                desplazamientoGoia <= desplazamientoBehea)
            {

                jokalaria.pos.y = blokeGoia - jokalariarenAltuera;
                jokalaria.abiaduraY = 0;
                jokalaria.airean = 0;
                gainean = 1;
                kolisioa = 1;
            }
            else if (desplazamientoBehea <= desplazamientoEzkerra && desplazamientoBehea <= desplazamientoEskuma &&
                     desplazamientoBehea <= desplazamientoGoia)
            {

                jokalaria.pos.y = blokeBehea;
                jokalaria.abiaduraY = 0;
                kolisioa = 1;
            }
            else if (desplazamientoEzkerra <= desplazamientoEskuma)
            {

                jokalaria.pos.x = blokeEzkerra - jokalariarenZabalera;
                jokalaria.abiaduraX = 0;
                kolisioa = 1;
            }
            else
            {

                jokalaria.pos.x = blokeEskuma;
                jokalaria.abiaduraX = 0;
                kolisioa = 1;
            }
        }

        i++;
    }

    if (gainean)
    {
        jokalaria = pertsonaiaMugitu(jokalaria, ebentu);
    }

    return jokalaria;
}

void kolisioaBasurarekin(JOKO_ELEMENTUA *basura, int basuraKopurua, JOKO_ELEMENTUA jokalaria)
{
    int zabaleraJokalaria = 0, altueraJokalaria = 0;
    int zabaleraBasura = 0, altueraBasura = 0;

    irudiaTamainaLortu(jokalaria.id, &zabaleraJokalaria, &altueraJokalaria);

    for (int i = 0; i < basuraKopurua; i++)
    {
        if (basura[i].aktibo)
        {

            irudiaTamainaLortu(basura[i].id, &zabaleraBasura, &altueraBasura);

            if (jokalaria.pos.x < basura[i].pos.x + zabaleraBasura &&
                jokalaria.pos.x + zabaleraJokalaria > basura[i].pos.x &&
                jokalaria.pos.y < basura[i].pos.y + altueraBasura &&
                jokalaria.pos.y + altueraJokalaria > basura[i].pos.y)
            {
                basura[i].aktibo = 0;
                irudiaKendu(basura[i].id);
            }
        }
    }
}

JOKO_ELEMENTUA kolisioaHertzekin(JOKO_ELEMENTUA jokalaria)
{
    int jokalariarenZabalera, jokalariarenAltuera;

    irudiaTamainaLortu(jokalaria.id, &jokalariarenZabalera, &jokalariarenAltuera);

    if (jokalaria.pos.x < 0)
    {
        jokalaria.pos.x = 0;
    }

    else if (jokalaria.pos.x + jokalariarenZabalera > SCREEN_WIDTH)
    {
        jokalaria.pos.x = SCREEN_WIDTH - jokalariarenZabalera;
    }

    if (jokalaria.pos.y < 0)
    {
        jokalaria.pos.y = 0;
    }

    else if (jokalaria.pos.y + jokalariarenAltuera > SCREEN_HEIGHT)
    {
        jokalaria.pos.y = SCREEN_HEIGHT - jokalariarenAltuera;
    }

    return jokalaria;
}

int kolisioaKonprobatuGaiztoekin(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA objetuak)
{
    int jokalariarenZabalera, jokalariarenAltuera;
    int blokeZabalera, blokeAltuera;
    int i = 0;
    int kolisioa = 0;
    if (objetuak.aktibo)
    {
        irudiaTamainaLortu(jokalaria.id, &jokalariarenZabalera, &jokalariarenAltuera);

        int jokalariaEzkerra = jokalaria.pos.x;
        int jokalariaEskuma = jokalaria.pos.x + jokalariarenZabalera;
        int jokalariaGoia = jokalaria.pos.y;
        int jokalariaBehea = jokalaria.pos.y + jokalariarenAltuera;

        irudiaTamainaLortu(objetuak.id, &blokeZabalera, &blokeAltuera);

        int blokeEzkerra = objetuak.pos.x;
        int blokeEskuma = objetuak.pos.x + blokeZabalera;
        int blokeGoia = objetuak.pos.y;
        int blokeBehea = objetuak.pos.y + blokeAltuera;

        if (jokalariaEskuma > blokeEzkerra && jokalariaEzkerra < blokeEskuma && jokalariaBehea > blokeGoia &&
            jokalariaGoia < blokeBehea)
        {
            kolisioa = 1;
        }
    }
    return kolisioa;
}

int Atea_teletransporte(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA objetuak)
{
    int jokalariarenZabalera, jokalariarenAltuera;
    int blokeZabalera, blokeAltuera;
    int i = 0;
    int ateanSartuta = 0;
    irudiaTamainaLortu(jokalaria.id, &jokalariarenZabalera, &jokalariarenAltuera);

    int jokalariaEzkerra = jokalaria.pos.x;
    int jokalariaEskuma = jokalaria.pos.x + jokalariarenZabalera;
    int jokalariaGoia = jokalaria.pos.y;
    int jokalariaBehea = jokalaria.pos.y + jokalariarenAltuera;

    irudiaTamainaLortu(objetuak.id, &blokeZabalera, &blokeAltuera);

    int blokeEzkerra = objetuak.pos.x;
    int blokeEskuma = objetuak.pos.x + 40;
    int blokeGoia = objetuak.pos.y;
    int blokeBehea = objetuak.pos.y + 70;
    if (jokalariaEskuma > blokeEzkerra && jokalariaEzkerra < blokeEskuma && jokalariaBehea > blokeGoia &&
    jokalariaGoia < blokeBehea)
    {
        ateanSartuta = 1;
    }
    
    return ateanSartuta;
}


int kolisioaGoratik(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA objetua)
{

    int jokalariarenZabalera, jokalariarenAltuera;
    int blokeZabalera, blokeAltuera;
    int i = 0;
    int kolisioaGoratik = 0;

    irudiaTamainaLortu(jokalaria.id, &jokalariarenZabalera, &jokalariarenAltuera);

    int jokalariaEzkerra = jokalaria.pos.x;
    int jokalariaEskuma = jokalaria.pos.x + jokalariarenZabalera;
    int jokalariaGoia = jokalaria.pos.y;
    int jokalariaBehea = jokalaria.pos.y + jokalariarenAltuera;

    irudiaTamainaLortu(objetua.id, &blokeZabalera, &blokeAltuera);

    int blokeEzkerra = objetua.pos.x;
    int blokeEskuma = objetua.pos.x + blokeZabalera;
    int blokeGoia = objetua.pos.y;
    int blokeBehea = objetua.pos.y + blokeAltuera;

    if (jokalariaEskuma > blokeEzkerra && jokalariaEzkerra < blokeEskuma && jokalariaGoia < blokeBehea &&
        jokalariaBehea > blokeGoia)
    {

        int desplazamientoEzkerra = jokalariaEskuma - blokeEzkerra;
        int desplazamientoEskuma = blokeEskuma - jokalariaEzkerra;
        int desplazamientoGoia = jokalariaBehea - blokeGoia;
        int desplazamientoBehea = blokeBehea - jokalariaGoia;

        if (desplazamientoGoia <= desplazamientoEzkerra && desplazamientoGoia <= desplazamientoEskuma &&
            desplazamientoGoia <= desplazamientoBehea)
        {
            kolisioaGoratik = 1;
        }
    }

    return kolisioaGoratik;
}