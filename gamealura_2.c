#include<stdio.h>
#include<string.h>
#include<time.h>
#include "forca.h"

// declarar as funções para não se preocupar com as ordens que elas aparecem, inclusive, coloca-se outro arquivo.h todas essas declarações de funções (header files); ficaria tipo #include "arquivo.h"

// char guarda apenas uma 'letra'. Arrays são para guardar um [monte de coisas], são mais dinâmicos pq da p fazer loop com for, por ex.
char feiticosecreto[TAMANHO_PALAVRA]; // o 20 é o limite máx do nosso array de char
char chutes[26];
int chutesdados = 0;

// esses dois char e int são variáveis globais

void abertura()
{
    printf("**********************************\n");
    printf("*     Jogo de Forca estilo HP     *\n");
    printf("***********************************\n\n");
    printf("\n\n");
}

void escolhefeitico()
{
    FILE* f;
    f = fopen("palavras.txt", "r");
    if (f==0)
    {
        printf("Desculpe, acho que um pelucio pegou nossas informaçoes brilhantes\n\n");
        exit(1);
    }
    
    int qtddepalavras;
    fscanf(f, "%d",&qtddepalavras);
    
    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for (int i = 0; i <= randomico; i++)
    {
        fscanf(f, "%s", feiticosecreto);
    }
    
    fclose(f);
    
    
    //sprintf(palavrasecreta, "MELANCIA");
    // o S antes do printf vem de string. Como saber quando parar de imprimir as letras (não é necessário ir até o limite max) ? declarando o \0 depois da ultima letra q vc quer q apareça
}

int letraexiste(char letra)
{
    for (int j = 0; j < strlen(feiticosecreto); j++)
    {
        if (letra == feiticosecreto[j])
        {
            return 1;
        }
    }
    
    return 0;
}

void chuta()
{
    char chute;
        printf("Qual a letra que queres chutar?\n");
        scanf(" %c", &chute); // no char qlqr coisa pode ser lida ent se eu digitar A e apertar Enter, o meu Enter vai ser entendido como um char, p q isso n aconteça, eu boto esse espaço antes de %c

        if(letraexiste(chute))
        {
            printf("Acertasse: o feitico tem a letra %c\n\n", chute);
        }
        else
        {
            printf("\n Ih, errasse: o feitico NAO tem a letra %c\n\n", chute);
        }

        chutes[chutesdados] = chute;
        chutesdados++;
}

int jachutou(char letra)
{
    int achou = 0;
    for (int j = 0; j < chutesdados; j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaforca()
{

    int erros = chuteserrados();

// if terminário é p qnd vc quer retornar qnd uma coisa é V e retornar outra quando F
   printf("  _______       \n");
printf(" |/      |      \n");
printf(" |      %c%c%c  \n", (erros>=1?'(':' '), 
    (erros>=1?'_':' '), (erros>=1?')':' '));
printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), 
    (erros>=2?'|':' '), (erros>=3?'/': ' '));
printf(" |       %c     \n", (erros>=2?'|':' '));
printf(" |      %c %c   \n", (erros>=4?'/':' '), 
    (erros>=4?'\\':' '));
printf(" |              \n");
printf("_|___           \n");
printf("\n\n");

    for (int i = 0; i < strlen(feiticosecreto); i++)
    {
        if (jachutou(feiticosecreto[i]))
        {
            printf("%c", feiticosecreto[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    
    printf("\n");
}

int ganhou()
{
    for (int i = 0; i < strlen(feiticosecreto); i++)
    {
        if (!jachutou(feiticosecreto[i]))
        {
            return 0;
        }
    }
    
    return 1;
}

int chuteserrados()
{
    int erros = 0;
    // fzr o loop em todos os chutes dados
    for (int i = 0; i < chutesdados; i++)
    { 
        if (!letraexiste (chutes[i]))
        {
            erros++;
        }
    }
    
    return erros;
}

int enforcou()
{
    return chuteserrados() >= 5;
}

void adcfeitico()
{
    char quer;
    printf("Ei, queres adicionar um novo feitico no joguinho? (S/N)");
    scanf(" %c", &quer);

    if (quer == 'S')
    {
        char novapalavra[TAMANHO_PALAVRA];
        printf("Digite o novo feitico em letras maiusculas: ");
        scanf("%s", novapalavra);

        FILE*f;

        f= fopen("palavras.txt", "r+");
        // r é de leitura, r+ é leitura e escrita
            if (f==0)
        {
            printf("Desculpe, acho que um pelucio pegou nossos dados brilhantes\n\n");
            exit(1);
        }
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET); //posicionei a cabeça do arquivo no inicio p ele saber a qntd
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);//posicionou na ultima palavra p poder escrever a nova 
        fprintf(f,"\n%s", novapalavra);

        fclose(f);
    }
    
}


int main()
{
    abertura();
    escolhefeitico();

    // do while difere do apenas while pq: do while primeiro executa o bloco p dps ver a condição. O while vê a condição p dps executar o bloco. O ! equivale a == 0, negação, inverter bouleano.
  
   do
   {    
        desenhaforca();
        chuta();

    } while (!ganhou() && !enforcou());

    if (ganhou())
    {
    printf("     ______  \n");
    printf("    /      \\  \n");
    printf("   |        |   \n");
    printf("   |:/-\\--\\.   \n");
    printf("    ( )-( )/,  \n");
    printf("     | ,  .   \n");
    printf("    / \\- /. \\   \n");
    printf("   | ||L  / \\ \\  Ae, bruxaooo!!! Vencesse, parabens, pontos para tua casa! \n");
    printf("  / /  \\/    | *      Jura solenemente nao fazer uma festinha  \n");
    printf(" / /          \\  \\         nada de boas no salao comunal? \n");
    printf(" | |      []   |\\ |  \n");
    printf("/| |           ||  | \n");
    printf("|| |           ||  | \n");
    printf("|  |           ||  | \n");
    printf("/_ |__________|||  | \n");
   printf("/_ \\| ---------||   | \n");
   printf("/_ / |         ||   | \n");
  printf("/  | ||         | |  |  \n");
  printf("\\//  ||         | |    \n");
  printf("/  | ||    T    | |  | \n");
 printf("/   | ||    |     |     \n");
printf("/                        \n");
        
    }
    else
    {
printf("   _____  \n");
printf("  /     \\  \n");
printf("/- (*) |*)\\  \n");
printf("|/\\.  _>/\\|   \n");
printf("    \\__/    |\\          Ih, bruxao, perdesse, mas nao desanima nao, \n");
printf("   _| |_   \\-/         Dobby esta muito confiante e apostou em voce! \n");
printf("  /|\\__|\\  //          A palavra da vez era **%s** \n", feiticosecreto);                 
printf(" |/|   |\\//  \n");
printf(" |||   | ~'   \n");
printf(" ||| __|   \n");
printf(" /_\\| ||   \n");
printf(" \\_/| ||  \n");
printf("   |7 |7   \n");
printf("   || ||   \n");
printf("   || ||   \n");
printf("   /\\ \\     \n");
printf("  ^^^^ ^^^      art by Sasquatch  \n");
    }
   
   adcfeitico();

}