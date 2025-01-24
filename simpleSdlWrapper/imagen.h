#ifndef IMAGEN_H
#define IMAGEN_H

#define MAX_IMG 100

int irudiaKargatu(char *fileName);
void irudiaMugitu(int numImg, int x, int y);
void irudiakMarraztu(void);
void irudiaKendu(int id);
int irudiarenPosizioaAurkitu(int id);
void irudiaTamainaEzarri(int id, int newWidth, int newHeight);
void irudiaTamainaLortu(int idImg, int *width, int *height);
#endif
