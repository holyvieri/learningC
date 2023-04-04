#include<stdio.h>

void abertura(int *x, int *y){
    printf("Tell me only two numbers pls\n");
    scanf("%d %d", x, y);
}

int main(){
    int a;
    int b;

    abertura(&a,&b);
    
    int result;
    result = a + b;

    printf("%d + %d = %d\n", a, b, result);

}

// Define uma função "abertura" que solicita ao usuário que insira dois números inteiros e armazena esses valores nas variáveis apontadas pelos ponteiros "*x" e "*y", respectivamente.

//No programa principal, as variáveis "a" e "b" são declaradas. A função "abertura" é chamada com os endereços de "a" e "b" como argumentos, para que o usuário possa inserir os valores de "a" e "b". Em seguida, o programa calcula a soma dos valores de "a" e "b" e armazena o resultado na variável "result".

//Por fim, o resultado da soma é impresso na tela.

//O uso de ponteiros na função "abertura" permite que os valores inseridos pelo usuário sejam armazenados diretamente nas variáveis "a" e "b" no programa principal, ao invés de serem retornados pela função. Isso evita a necessidade de usar um valor de retorno da função para passar os valores inseridos pelo usuário para o programa principal.

//O uso de ponteiros também permite que a função "abertura" modifique os valores de "a" e "b" diretamente, sem a necessidade de retornar uma cópia modificada das variáveis. Isso pode ser útil quando se deseja modificar variáveis em uma função e manter as modificações entre chamadas de função.

