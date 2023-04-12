#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BOMB 'b'

int acabou();
int ehdirecao(char direcao);
void kabum_drugs(int x, int y, int qtd);
void move(char direcao);
int goghosts (int xatual, int yatual, int *destinox, int *destinoy);
void ghosts();