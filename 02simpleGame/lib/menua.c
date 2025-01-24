#include "menua.h"

void jokoaAurkeztu(void)
{
    int ebentu = 0, x, y;
    JOKO_ELEMENTUA jolastu, kredituak, nolajolastu, soinua;
    int background, botoiwidth = 0, botoiheight = 0;
    int soinuaAktibatuta = 1, bizitzak = 3, entrada = 0;

    pantailaGarbitu();

    jolastu.pos.x = (SCREEN_WIDTH / 2) - 70;
    jolastu.pos.y = (SCREEN_HEIGHT / 2) + 80;

    kredituak.pos.x = (SCREEN_WIDTH / 2) - 240;
    kredituak.pos.y = (SCREEN_HEIGHT / 2) + 80;

    nolajolastu.pos.x = (SCREEN_WIDTH / 2) + 100;
    nolajolastu.pos.y = (SCREEN_HEIGHT / 2) + 80;

    soinua.pos.x = SCREEN_WIDTH - 70;
    soinua.pos.y = 20;

    loadTheMusic(JOKOA_MENU_SOUND);
    toggleMusic();

    background = irudiaKargatu(BACKGROUND_MENU_IMAGE);
    kredituak.id = irudiaKargatu(KREDITUAK_BOTOI_IMAGE);
    nolajolastu.id = irudiaKargatu(NOLA_JOLASTU_BOTOI_IMAGE);
    jolastu.id = irudiaKargatu(JOLASTU_BOTOI_IMAGE);
    soinua.id = irudiaKargatu(SOINUAON_IMAGE);

    irudiaTamainaEzarri(background, SCREEN_WIDTH, SCREEN_HEIGHT);

    irudiaTamainaLortu(kredituak.id, &botoiwidth, &botoiheight);
    kredituak.width = botoiwidth * 2;
    kredituak.height = botoiheight * 2;
    irudiaTamainaEzarri(kredituak.id, kredituak.width, kredituak.height);

    nolajolastu.width = botoiwidth * 2;
    nolajolastu.height = botoiheight * 2;
    irudiaTamainaEzarri(nolajolastu.id, nolajolastu.width, nolajolastu.height);

    jolastu.width = botoiwidth * 2;
    jolastu.height = botoiheight * 2;
    irudiaTamainaEzarri(jolastu.id, jolastu.width, jolastu.height);

    do
    {
        SDL_Delay(10);
        pantailaGarbitu();
        irudiaMugitu(jolastu.id, jolastu.pos.x, jolastu.pos.y);
        irudiaMugitu(kredituak.id, kredituak.pos.x, kredituak.pos.y);
        irudiaMugitu(nolajolastu.id, nolajolastu.pos.x, nolajolastu.pos.y);
        irudiaMugitu(soinua.id, soinua.pos.x, soinua.pos.y);
        irudiakMarraztu();

        pantailaBerriztu();

        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_ESKUMA || ebentu == SAGU_BOTOIA_EZKERRA)
        {
            POSIZIOA saguPos = saguarenPosizioa();
            tocado(kredituak, kredituak.width, kredituak.height, saguPos, entrada);
            tocado(nolajolastu, nolajolastu.width, nolajolastu.height, saguPos, entrada);
            tocado(jolastu, jolastu.width, jolastu.height, saguPos, entrada);
        }
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            saguarenPosizioaLortu(&x, &y);
            if (x >= soinua.pos.x && x <= soinua.pos.x + 50 && y >= soinua.pos.y && y <= soinua.pos.y + 50)
            {
                irudiaKendu(soinua.id);
                soinuaAktibatuta = !soinuaAktibatuta;
                soinua.id = irudiaKargatu(soinuaAktibatuta ? SOINUAON_IMAGE : SOINUAOFF_IMAGE);
                irudiaMugitu(soinua.id, soinua.pos.x, soinua.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
                toggleMusic();
            }
        }
    } while (ebentu != TECLA_0);

    irudiaKendu(kredituak.id);
    irudiaKendu(nolajolastu.id);
    irudiaKendu(jolastu.id);
    irudiaKendu(background);
    bizitzak = jokatu(bizitzak);
}

void tocado(JOKO_ELEMENTUA BOTOIA, int botoiwidth, int botoiheight, POSIZIOA saguPos, int entrada)
{
    int bizitzak = 3;
    if (saguPos.x >= BOTOIA.pos.x && saguPos.x <= BOTOIA.pos.x + botoiwidth && saguPos.y >= BOTOIA.pos.y &&
        saguPos.y <= BOTOIA.pos.y + botoiheight)
    {
        printf("Botón clicado\n");
        if (BOTOIA.id == 1 || (BOTOIA.id - 1) % 6 == 0)
        {
            Sartu_Kredituak();
            entrada++;
        }
        // Comprobamos si el ID pertenece al caso de Nolajolastu
        else if (BOTOIA.id == 2 || (BOTOIA.id - 2) % 6 == 0)
        {
            Sartu_Nola_Jolastu();
            entrada++;
        }
        else if (BOTOIA.id == 3 || (BOTOIA.id - 3) % 6 == 0)
        {
            Nibel_Mapa(entrada, bizitzak);
        }
        else
        {
            printf("No se ha reconocido el botón clicado.\n");
        }
    }
}
void Sartu_Nola_Jolastu()
{
    int fondoId = irudiaKargatu("./img/Nola_Jolastu_Pantalla2.bmp");
    irudiaTamainaEzarri(fondoId, SCREEN_WIDTH, SCREEN_HEIGHT);

    pantailaGarbitu();
    irudiaMugitu(fondoId, 0, 0);
    irudiakMarraztu();
    textuaIdatzi(SCREEN_WIDTH - 700, SCREEN_HEIGHT - 370, "- W, A, S, D, pertsonaia mugitzea eta salto egitea.");
    textuaIdatzi(SCREEN_WIDTH - 700, SCREEN_HEIGHT - 340, "- Zaborra hartzerakoan saguarekin klik mantenduz objektuak");
    textuaIdatzi(SCREEN_WIDTH - 700, SCREEN_HEIGHT - 320, "arrastatzea.");

    textuaIdatzi(SCREEN_WIDTH - 700, SCREEN_HEIGHT - 290, "- Bizitza kenduko duten etsaiak.");
    textuaIdatzi(SCREEN_WIDTH - 700, SCREEN_HEIGHT - 260, "- Etsaiak hiltzeko gainean salto egin beharra.");
    textuaIdatzi(SCREEN_WIDTH - 700, SCREEN_HEIGHT - 230,
                 "- 1, 2, 3 edo 4 botoia sakatutakoan pertsonaiaren txapela kolorez");
    textuaIdatzi(SCREEN_WIDTH - 700, SCREEN_HEIGHT - 210, " aldatu zabor desberdinak hartzeko. ");

    textuaIdatzi(SCREEN_WIDTH - 700, SCREEN_HEIGHT - 190, "Adibidez, kolore horia = plastikoa.");
    pantailaBerriztu();

    // Esperar a que el usuario presione el 0 para volver al menú
    int ebentu;

    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);

    irudiaKendu(fondoId);
}

void Sartu_Kredituak()
{
    int fondoId = irudiaKargatu("./img/Kredituak_Pantalla2.bmp");
    irudiaTamainaEzarri(fondoId, SCREEN_WIDTH, SCREEN_HEIGHT);

    pantailaGarbitu();
    irudiaMugitu(fondoId, 0, 0);
    irudiakMarraztu();
    textuaIdatzi(SCREEN_WIDTH - 700, SCREEN_HEIGHT - 340, "- EGILEAK:");
    textuaIdatzi(SCREEN_WIDTH - 700, SCREEN_HEIGHT - 320, "     Beñat Telleria");
    textuaIdatzi(SCREEN_WIDTH - 700, SCREEN_HEIGHT - 300, "     Lander Huarte");
    textuaIdatzi(SCREEN_WIDTH - 700, SCREEN_HEIGHT - 280, "     Nerea Soares");
    textuaIdatzi(SCREEN_WIDTH - 700, SCREEN_HEIGHT - 260, "     Aimar Martin");
    textuaIdatzi(SCREEN_WIDTH - 700, SCREEN_HEIGHT - 240, "     Maren Etxezarreta");
    textuaIdatzi(SCREEN_WIDTH - 700, SCREEN_HEIGHT - 210, "- INSPIRAZIOA:   Mario Bros (Nintendo, Ubisoft etab.)");

    pantailaBerriztu();

    // Esperar a que el usuario presione la tecla RETURN para volver al menú
    int ebentu;
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);

    irudiaKendu(fondoId);
}