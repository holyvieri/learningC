#define DOLL '@'
#define GHOST 'F'
#define CAMINHO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

struct mapa{
    char** matriz;
    int linhas;
    int colunas;
}; // nesse agrupamento mapa há as informações essenciais 

typedef struct mapa MAPA; 
// TYPEDEF deixa vc criar um apelidio, nesse caso, "struct mapa" está sendo chamado de MAPA.

struct posicao{
    int x;
    int y;
};
typedef struct posicao POSICAO;

void libera_mapa(MAPA *m);
void aloca_mapa(MAPA *m);
void ler_mapa(MAPA *m);
void imprime_mapa(MAPA *m);
void encontra_mapa(MAPA* m, POSICAO* p, char c);
int validaparede_mapa(MAPA *m, int x, int y);
int pontocaminho_mapa(MAPA *m, int x, int y);
void andando_mapa(MAPA* m, int xorigem, int yorigem, int destinox, int destinoy);
void copia_mapa(MAPA* destino, MAPA* origem);

// preciso passar o ponteiro como parâmetro para q a variavel funcione, pois variavel global funciona APENAS no ARQUIVO em q foi DECLARADA
// mas para que uma variavel global seja GLOBAL DE VERDADE, preciso redeclarala como 'extern', exemplo:
// em um aqruivo x.c:
// int a;
// agr quero usar essa variavel de int em outro arquivo, o y.c:
// extern int a;
// ou seja, em apenas um arquivo é declarada normal e nos outros tem q deixar claro q é externa
