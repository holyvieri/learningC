#include<stdio.h>
#include<stdlib.h>
#include "ui.h"
#include "mapa.h"

char d_ghost[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char d_wall[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char d_doll[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char d_drug[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char d_way[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void imprimeparte(char drawing[4][7], int parte){
    printf("%s", drawing[parte]);
}

void imprime_mapa(MAPA *m){
    for (int i = 0; i < m->linhas; i++){ //para cada linha do mapa
        for (int parte = 0; parte < 4; parte++){ // cada 4 linha de desenho
            for (int j = 0; j < m->colunas; j++){
                
                switch (m->matriz[i][j]){
                case GHOST:
                    imprimeparte(d_ghost, parte);
                    break;
                case DOLL:
                    imprimeparte(d_doll, parte);
                    break;
                case DRUGS:
                    imprimeparte(d_drug, parte);
                    break;
                case PAREDE_VERTICAL:
                case PAREDE_HORIZONTAL:
                    imprimeparte(d_wall, parte);
                    break;
                case CAMINHO:
                    imprimeparte(d_way, parte);
                    break;
                }
            }

           printf("\n"); 
        }
        
    }
}