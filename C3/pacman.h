#ifndef _PACMAN_H_
#define _PACMAN_H_

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BOMB 'b'

int acabou();
int ehdirecao(char direcao);
void kabum_drugs();
void kabum_drugs2(int x, int y, int somax, int somay, int qtd);
void move(char direcao);
int goghosts (int xatual, int yatual, int *destinox, int *destinoy);
void ghosts();
#endif