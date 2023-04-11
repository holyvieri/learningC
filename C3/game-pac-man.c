#include<stdio.h>
#include<stdlib.h>
#include"pacman.h"
#include"mapa.h"

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

void ghosts(){
    MAPA copia;

    copia_mapa(&copia,&m);

    for (int i = 0; i < m.linhas; i++){
        for (int j = 0; j < m.colunas; j++){

            if (copia.matriz[i][j]== GHOST){
                if (validaparede_mapa(&m, i, j+1) && pontocaminho_mapa(&m, i, j+1)){
                    andando_mapa(&m,i,j,i,j+1);
                }
                
            }
            
        }
        
    }
    
    libera_mapa(&copia);
}

int acabou(){
    return 0;
}

// esses || significam "ou"
int ehdirecao(char direcao){
    return direcao == 'a'|| 
        direcao =='w'||
        direcao =='s'||
        direcao =='d';
}

void move(char direcao){

    if (!ehdirecao(direcao)){
        return;
    }

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

    if(!validaparede_mapa(&m, nextx, nexty)){
        return;
    }
    if(!pontocaminho_mapa(&m, nextx, nexty)){
        return;
    }

   andando_mapa(&m, doll.x, doll.y, nextx, nexty);
   // atualizando a posição do personagem:
   doll.x = nextx;
   doll.y = nexty;
}

int main(){

   ler_mapa(&m);
   encontra_mapa(&m, &doll, DOLL);

    do{
        imprime_mapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);
        ghosts();

    }while (!acabou());
    
    libera_mapa(&m);

}