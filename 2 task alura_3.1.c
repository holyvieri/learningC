#include<stdio.h>
#include<math.h>

void potencia(int n, int x, int *y)
{
    int result=n;
    for (int i = 1; i < x; i++)
    {
        result = result*n;
    }
    *y = result;
}
int main()
{
    int n1, n2, r;

    printf("Tell me only two numbers pls\n");
    scanf("%d %d", &n1, &n2);

    potencia(n1,n2,&r);

    printf("-----------------------------------\n");
    printf("%d raised to the power of %d is %d\n", n1, n2, r);
    printf("-----------------------------------\n");

    return 0;
}

// Ele define uma função "potencia" que calcula a potência de "n" elevado a "x" e armazena o resultado na variável apontada por "*y". No programa principal, a função é chamada com os valores de "n1" e "n2" como argumentos, e o endereço de "r" é passado como terceiro argumento. O programa solicita que o usuário insira dois números usando a função "scanf", e em seguida chama a função "potencia" para calcular a potência de "n1" elevado a "n2". Finalmente, o resultado é impresso na tela.

//Na declaração da função "potencia", o terceiro parâmetro é declarado como um ponteiro para inteiro, ou seja, "*y". Isso significa que o endereço de uma variável inteira pode ser passado como argumento para a função, e a função pode modificar o valor da variável apontada por esse ponteiro. No caso específico dessa função, o ponteiro "*y" é usado para armazenar o resultado do cálculo da potência, para que ele possa ser acessado e impresso na função principal.

//Na chamada da função "potencia" no programa principal, o terceiro argumento é passado como "&r". O operador "&" é usado para obter o endereço da variável "r" e passá-lo como argumento para a função. Isso permite que a função "potencia" altere o valor da variável "r" diretamente, ao invés de retornar o resultado como um valor de retorno. Isso é útil quando se deseja retornar mais de um valor de uma função.

//Em resumo, o uso de ponteiros permite que o valor de uma variável seja modificado dentro de uma função e mantido entre chamadas de função. Além disso, o uso de ponteiros permite que os valores calculados em uma função sejam passados ​​de volta para a função principal. Neste caso, o ponteiro é usado para armazenar o resultado do cálculo da potência, que é então usado na função principal para imprimir o resultado na tela.




