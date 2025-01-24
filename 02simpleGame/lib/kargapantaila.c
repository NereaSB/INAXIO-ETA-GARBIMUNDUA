#include "kargapantaila.h"
int pantallaCargaActiva = 0;
void kargaPantaila(void)
{
    pantallaCargaActiva = 1; // Activar la pantalla de carga
    int kargaId = -1;
    int ebentu = 0;
    int botonWidth = 0, botonHeight = 0;

    kargaId = irudiaKargatu(KARGA_IMAGE);

    irudiaTamainaLortu(kargaId, &botonWidth, &botonHeight);
    irudiaTamainaEzarri(kargaId, SCREEN_WIDTH, SCREEN_HEIGHT);

    pantailaGarbitu();
    irudiaMugitu(kargaId, 0, 0);

    irudiakMarraztu();

    textuaIdatzi(SCREEN_WIDTH - 690, SCREEN_HEIGHT - 260, "Plastikozko botila bat birziklatuz bonbilla bat 6 orduz");
    textuaIdatzi(SCREEN_WIDTH - 690, SCREEN_HEIGHT - 240, " piztuta mantentzeko behar den energia aurrezten dugu.");
    pantailaBerriztu();

    SDL_Delay(3000); // Esperar segundos

    irudiaKendu(kargaId);
    pantallaCargaActiva = 0; // Desactivar la pantalla de carga
}