#ifndef _UI_H_
#define _UI_H_
// se o ui.h n foi definido, o código daq vai rodar, daí, caso o o ui.h já tenha sido importado em outro arquivo, ele pula todo o código.
#include "mapa.h"

void imprime_mapa(MAPA *m);
void imprimeparte(char drawing[4][7], int parte);


#endif