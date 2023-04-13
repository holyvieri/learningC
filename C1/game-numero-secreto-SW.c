#include<stdio.h>
#include<stdlib.h> // p/ incluir a função abs de devolver o módulo/valor absoluto do número
#include<time.h>
// definir uma constante: é usar #define ABCDEF __  

int main(){
    // imprime cabeçalho do nosso game

    printf("                                                                       \n ");
    printf("                                   /~\\                                 \n ");
    printf("                                  |oo )              Seja bem vindx ao  \n");
    printf("                                  _\\=/_              meu prototipo de   \n");
    printf("                  ___            /  _  \\             jogo de adivinha!  \n");
    printf("                 / ()\\          //|/.\\|\\                               \n");
    printf("               _|_____|_        \\ \\_/  ||                              \n");
    printf("              | | === | |        \\|\\ /| ||                              \n");
    printf("              |_|  O  |_|        # _ _/ #                               \n");
    printf("               ||  O  ||          | | |    [range do numero secreto: 0-99]  \n");
    printf("               ||__*__||          | | |                                \n ");
    printf("\n\n");

    int segundos = time (0);
    srand(segundos); // gera uma semente diferente p esses números randomicos

    int n1 = rand();
    // a divisão é \ mas o resto é %; ent se eu tenho um numero grande qlqr divido por 100, o resto pode dar de 0 a 99
    int numerosecreto = n1 % 100 ;
    // double permite o cálculo de decimais e sua máscara é %f
    double pontos = 1000;

    int level;
    printf("Qual o nivel de dificuldade que queres?\n");
    printf("(1) Izi (2) Marromeno (3) Hard \n\n");
    printf("Escolha: ");
    scanf("%d", &level);

    int numerodetentativas;
   
    switch (level){
    case 1:
        numerodetentativas = 20;
        break;
    case 2: 
        numerodetentativas = 15;
        break;
    default:
        numerodetentativas = 6;
        break;
    }

    int chute;
    int tentativas=1;
    int deu_bom;
  
  // for é p um loop q vá se repetir em uma quantidade de vezes exatas, o while é infinito

    for (int i = 1; i <= numerodetentativas; i++){
         printf("Tentativa %d \n", tentativas);
        printf("Qual e o teu chute?\n ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0){
            printf("Nao vale numero negativo, hein?!\n");
            // usa continue qnd n quer quebrar o código, mas sim continuá-lo do inicio
            continue; 
        }
        deu_bom = (chute == numerosecreto);
        int menor = (chute < numerosecreto);
      // o == é de comparação e quando é Verdadeiro=1 ; Falso= 0
      // o else if tem q estar na MESMA LINHA que o FIM DO IF.
      // IDENTAÇÃO = A ORGANIZAÇÃO PADRÃO

        if (deu_bom){
            break;
        }else if(menor){
            printf("Oh no! Teu chute foi MENOR que o bendito numero secreto!\n");
        }else{
            printf("Oh no! Teu chute foi MAIOR que o bendito numero secreto!\n");
        }
        
        tentativas++;
        
        // o pc lê da esquerda para direita, então, se ele faz a conta lendo apenas "2", ele supõe que é um inteiro e perde toda a precisão, logo, se eu quero q seja decimal, preciso dar uma "dica" que quero double...boto "2.0" ou antes do dois faço um casting [q é tipo converter] assim: x/ (double) 2 . Cuidado no casting pq de um double (q guarda mais info) p/ um int (guarda menos info) vc tem perda de dados.
        double pontosperdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosperdidos;
    }
    
    char answer;
    printf("Fim de jogo!\n");

    if (deu_bom){
        
       printf("                          |oo )                        \n");
      printf("                     #    _\\=/_    #                   \n");
      printf("                     \\  /  _  \\  //                  \n");
      printf("                      \\//|/.\\|\\//                     \n");
      printf("                       \\/  \\_/  \\/                       \n");
      printf("                          |\\ /|                           \n");
      printf("   Acertou mizeravi!      \\_ _/                           \n");
      printf("      Tu = fera           | | |                            \n");
      printf("                          | | |                            \n");
      printf("                          []|[]                               \n");
      printf("                          | | |                               \n");
      printf("_________________________/_]_[_\\__                             \n");
      printf("\n\n");
        printf("Acertasse em %d tentativas!\n", tentativas);
        // o .x dps do % vai me dar a quantidade de casas q eu quero q apareça
        printf("Total de pontos: %.1f\n", pontos);
        printf("Quer jogar mais uma partida?[S/N]\n");
        scanf(" %c", &answer);

        switch (answer){
        case 'S' :
            main();
            break;
        default:
            break;
        }

    }else{
        printf("         __---__                      \n");
        printf(" .   .-'...:...'-.               .          . \n");
        printf("    / .  . : .__ .\\                                         . \n");
        printf("   /........./  \\ .\\  .   .   Ah naoooooooooo! O numero secreto era %d .       . \n", numerosecreto);
        printf("  / :  :   :| () | :\\            Perdesse, mas tenta de novo!    .       \n");
        printf(" :...........\\__/....:         .    \n");
        printf(" |___________________|              .                     .  \n");
        printf(" |...................|               .  \n");
        printf(" :  :  :   :   :   : :                          .            . \n");
        printf(" \\................./      .            .  \n");
        printf("  \\  .  . : .  .  /   .                                . \n");
        printf("   \\._........._./  .        .                   . \n");
        printf("      -..___..-                .         . \n");
        printf("\n\n");
    
        printf("Quer jogar mais uma partida?[S/N]\n");
        scanf(" %c", &answer);
        
        switch (answer){
        case 'S' :
            main();
            break;
        default:
            break;
        }
    }
}