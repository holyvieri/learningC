#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"pacman.h"
#include"mapa.h"
#include"ui.h"

// armazenando na posição i x j: 
/* mapa [i] [j] = '|';*/
// imprimindo a posição i x j:
/* printf("%c", mapa [i] [j]);*/
// matriz de 5 x 10 --> [linha(i)] [coluna(j)].
// o +1 por causa do /0 no fim da string

// para acessar as informações da struct mapa eu chamo a variável que coloquei ao lado dele mais um '.' seguido pela info que quero
/* exemplo:
x.linhas=10;
x.colunas=10;
   
char mapa[10][10];
x.matriz = mapa;*/

MAPA m; // struct = serve p agrupar um conjunto de variáveis que não podem andar separadas; definir um conjunto de dados
POSICAO doll;
int drugs = 0;

int acabou(){

    POSICAO pos;
    
    int perdeu = !encontra_mapa(&m, &pos, DOLL);
    int ganhou = !encontra_mapa(&m, &pos, GHOST);

    if (ganhou){
        printf("GANHOU!! EXPLODISSE OS DOIS, MT FERA!\n");
        return ganhou;
    }else if(perdeu){
        printf("PERDESSE! TENTA DNV!\n");
        return perdeu;
    }else{
        return 0;
    }
}

// esses || significam "ou"
int ehdirecao(char direcao){
    return (direcao == ESQUERDA|| direcao == CIMA|| direcao == BAIXO|| direcao == DIREITA);
}

void move(char direcao){

    int nextx = doll.x;
    int nexty = doll.y;

    //matriz tá sendo representada como uma tabela onde as linhas representam a vertical e as colunas representam a horizontal
    switch (direcao){ 
     // agr ele vai pegar a entrada q o usario digitou e colocar o bonequinho para uma nova posição
    case ESQUERDA:
        nexty--;
        break;
    case CIMA:
        nextx--;
        break;
    case BAIXO:
        nextx++;
        break;
    case DIREITA:
        nexty++;
        break;
    }

    if(!podeandar(&m, DOLL, nextx, nexty)){
        return;
    }

    if(ehpersonagem(&m, DRUGS, nextx, nexty)){
        drugs = 1;
    }

   andar_mapa(&m, doll.x, doll.y, nextx, nexty);
   // atualizando a posição do personagem:
   doll.x = nextx;
   doll.y = nexty;
}

int goghosts (int xatual, int yatual, int *destinox, int *destinoy){

    int opcoes [4][2]={
        {xatual, yatual+1},
        {xatual+1,yatual},
        {xatual, yatual-1},
        {xatual-1, yatual}
    };

    srand(time(0));
    for (int i = 0; i < 10; i++){
        int posicao = rand() % 4;

        if(podeandar(&m, GHOST, opcoes[posicao][0], opcoes[posicao][1])){
            *destinox = opcoes[posicao][0];
            *destinoy = opcoes[posicao][1];
            return 1;
        }
    }
    
    return 0;
}

void ghosts(){
    MAPA copia;

    copia_mapa(&copia, &m);

    for(int i = 0; i < copia.linhas; i++){
        for(int j = 0; j < copia.colunas; j++){
             if (copia.matriz[i][j] == GHOST){

                int destinox;
                int destinoy;

                int encontrou = goghosts(i, j, &destinox, &destinoy);

                if (encontrou){
                    andar_mapa(&m, i, j, destinox, destinoy);
                }
            } 
        }
    }
    
    libera_mapa(&copia);
}

void kabum_drugs(){
    
    if (!drugs){
        return;
    }
    
    kabum_drugs2(doll.x, doll.y, 0, 1, 3);
    kabum_drugs2(doll.x, doll.y, 0, -1, 3);
    kabum_drugs2(doll.x, doll.y, 1, 0, 3);
    kabum_drugs2(doll.x, doll.y, -1, 0, 3);

    drugs = 0;
}

void kabum_drugs2(int x, int y, int somax, int somay, int qtd){
    
    if (qtd==0){
        return;
    }

    int novox = x+somax;
    int novoy = y+somay;

    if (!ehpermitido_mapa(&m, novox, novoy)){
        return;
    }
    if (ehparede(&m, novox, novoy)){
        return;
    }
    
    m.matriz[novox][novoy]=CAMINHO; // explodir a direita sempre
    kabum_drugs2(novox, novoy, somax, somay, qtd-1);// função recursiva: chama a prórpia função, tem q pensar em qnd vai parar
}

int main(){

   ler_mapa(&m);
   encontra_mapa(&m, &doll, DOLL);

    do{

        printf("Drugs: %s\n",(drugs ? "YES" : "NO"));
        imprime_mapa(&m);

        char comando;
        scanf(" %c", &comando);

        if (ehdirecao(comando)){
            move(comando);
        }
        if (comando == BOMB){
            kabum_drugs();
        }
        
        ghosts();

    }while (!acabou());
    
    printf("Queres jogar mais uma partida? [S/N]\n");
    char again;
    scanf(" %c", &again);

    switch (again){
    case 'S':
    case 's':
        libera_mapa(&m);
        return main();
    case 'N':
    case 'n':
        break;
    default:
        break;
    }

    libera_mapa(&m);

}