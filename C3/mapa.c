#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"mapa.h"

void copia_mapa(MAPA* destino, MAPA* origem){
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    aloca_mapa(destino);
    for (int i = 0; i < origem->linhas; i++){
        strcpy(destino->matriz[i], origem->matriz[i]);
        // strcpy é uma função q copia um array p outro até achar o /0, serve p copiar strings
    }
    
}

int ehparede(MAPA* m, int x, int y){
    return m->matriz[x][y] == PAREDE_VERTICAL || m->matriz[x][y] == PAREDE_HORIZONTAL;
}

int ehpersonagem(MAPA* m, char personagem, int x, int y){
    return m->matriz[x][y] == personagem;
}

int podeandar(MAPA* m, char personagem, int x, int y){

    return ehpermitido_mapa(m, x, y) && !ehparede(m, x, y) && !ehpersonagem(m, personagem, x, y);
}

void andar_mapa(MAPA* m, int xorigem, int yorigem, int destinox, int destinoy){
    char personagem = m->matriz[xorigem][yorigem];
    m->matriz [destinox][destinoy] = personagem;
    m->matriz [xorigem][yorigem] = CAMINHO;

}

int ehpermitido_mapa(MAPA *m, int x, int y){
    if(x >= m->linhas){
        return 0;
    }
    if(y >= m->colunas){
        return 0;
    }

    return 1;
}

// lembra que para pegar o conteúdo de um ponteiro tem q adicionar uma * antes dele. mas, p PONTEIRO DE STRUCT, tbm pode ser o ponto da struct [m] mais "->" sendo direcionado p outra coisa

void ler_mapa(MAPA *m){
    FILE *f;
    f = fopen("mapa.txt", "r");
    if(f==0){
        printf("Desculpe, erro na leitura do mapa.\n");
        exit(1);
    }
    
    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
    aloca_mapa(m);

    // vai ler uma string inteira do arquivo f e guardar no mapa.
    // se eu botasse mapa [i] [j] só iria pegar uma posição apenas, botando apenas mapa [i] ele pega uma linha toda
    for(int i=0; i < m->linhas; i++){
        fscanf(f, "%s", m->matriz[i]); 
    }

    fclose(f);
}

// representação com tabela
void aloca_mapa(MAPA *m){
    m->matriz = malloc(sizeof(char*) * m->linhas);//aloco memoria p cada linha da matriz
    
    for (int i = 0; i < m->linhas; i++){ 
        m->matriz[i] = malloc(sizeof(char) * m->colunas+1); // agr aloco memoria p cada coluna, ou seja, p cada caractere da linha
    }

}

void libera_mapa(MAPA *m){
    for (int i = 0; i < m -> linhas; i++){
        free(m -> matriz[i]);
    }
    free((*m).matriz); // pq não posso escrever só isso p liberar a matriz toda?
}

void imprime_mapa(MAPA *m){
    for (int i = 0; i < m->linhas; i++){
        printf("%s\n", m->matriz[i]);
    }
}

int encontra_mapa(MAPA* m, POSICAO* p, char c){
    // esse char é o caractere q vou achar no mapa
 // achar a posição do pac man: vou varrer a matriz a CADA tecla digitada e qnd encontrar a posição i,j q corresponder ao meu bonequinho, vou ent definir a equivalência dessa posição com x e y.
    for (int i = 0; i < m->linhas; i++){
        for (int j = 0; j < m->colunas; j++){
            if (m->matriz[i][j] == c){
                p->x = i;
                p->y = j;
                return 1;
            }
            
        }
        
    }
    // nao encontra
    return 0;
}